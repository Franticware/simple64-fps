#include "keypressfilter.h"
#include "interface/core_commands.h"
#include "interface/common.h"
#include "mainwindow.h"
#include <QKeyEvent>
#include <QMessageBox>

static bool mouseLock = false;
static int nextMouseMove = 0;

KeyPressFilter::KeyPressFilter(QObject *parent)
    : QObject(parent)
{
}

bool KeyPressFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        int modValue = QT2SDL2MOD(keyEvent->modifiers());
        int keyValue = QT2SDL2(keyEvent->key());
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_QuoteLeft)
        {
            mouseLock = false;
        }
        if (keyValue != 0)
            (*CoreDoCommand)(M64CMD_SEND_SDL_KEYDOWN, (modValue << 16) + keyValue, NULL);
        return true;
    } else if (event->type() == QEvent::KeyRelease){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        int modValue = QT2SDL2MOD(keyEvent->modifiers());
        int keyValue = QT2SDL2(keyEvent->key());
        if (keyValue != 0)
            (*CoreDoCommand)(M64CMD_SEND_SDL_KEYUP, (modValue << 16) + keyValue, NULL);
        return true;
    } else if (event->type() == QEvent::MouseButtonPress) {
        if (mouseLock)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            (*CoreDoCommand)(M64CMD_SEND_MOUSE_DOWN, mouseEvent->button(), NULL);
        }
        else
        {
            mouseLock = true;
            nextMouseMove = 0;
        }
        return true;
    } else if (event->type() == QEvent::MouseButtonRelease) {
        if (mouseLock)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            (*CoreDoCommand)(M64CMD_SEND_MOUSE_UP, mouseEvent->button(), NULL);
        }
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        QWindow* window = static_cast<QWindow*>(obj);
        QRect windowRect = window->geometry();
        QPoint topLeft = window->mapToGlobal(windowRect.topLeft());
        QPoint bottomRight = window->mapToGlobal(windowRect.bottomRight());
        int x = topLeft.x();
        int y = topLeft.y();
        int x2 = bottomRight.x();
        int y2 = bottomRight.y();
        int xcen = (x + x2) / 2;
        int ycen = (y + y2) / 2;
        if (mouseLock)
        {
            QPointF mousePointF = mouseEvent->globalPosition();
            QPoint mousePoint = mousePointF.toPoint();
            int mouseX = mousePoint.x();
            int mouseY = mousePoint.y();
            if (!(xcen == mouseX && ycen == mouseY))
            {
                int dx = mouseX - xcen;
                int dy = mouseY - ycen;
                if (nextMouseMove > 1)
                {
                    if (dx)
                    {
                        (*CoreDoCommand)(M64CMD_SEND_MOUSE_RELX, dx, NULL);
                    }
                    if (dy)
                    {
                        (*CoreDoCommand)(M64CMD_SEND_MOUSE_RELY, dy, NULL);
                    }
                }
                else
                {
                    ++nextMouseMove;
                }
                QCursor::setPos(xcen, ycen);
            }
        }
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
