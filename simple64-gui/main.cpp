#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>

MainWindow *w = nullptr;
int main(int argc, char *argv[])
{
    srand (time(NULL));

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/simple64.svg"));

    QCoreApplication::setApplicationName("simple64-gui");

    QCommandLineParser parser;
    parser.addHelpOption();
    QCommandLineOption verboseOption({"v", "verbose"}, "Verbose mode. Prints out more information to log.");
    QCommandLineOption noGUIOption("nogui", "Disable GUI elements.");
    parser.addOption(verboseOption);
    parser.addOption(noGUIOption);
    parser.addPositionalArgument("ROM", QCoreApplication::translate("main", "ROM to open."));
    parser.process(a);
    const QStringList args = parser.positionalArguments();

    MainWindow mainWin;
    w = &mainWin;
    w->show();
    if (parser.isSet(verboseOption))
        w->setVerbose();
    if (parser.isSet(noGUIOption))
        w->setNoGUI();
    if (args.size() > 0)
        w->openROM(args.at(0), "", 0, 0);
    else
        w->updateApp();

    return a.exec();
}
