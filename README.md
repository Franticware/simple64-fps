# FPS with mouse on N64

**https://www.youtube.com/watch?v=fVUlUofX8T8**

**https://www.youtube.com/watch?v=qi255SCU07k**

I wanted to play N64 version of Quake II with a mouse, so I hacked the support into the emulator. I also added support for Duke Nukem 64.

To start mouse look, click into the game window. To release the mouse, press ~ or numpad Enter.

Built nicely for me in Linux using ./build.sh. I am not going to provide Windows build because it is a chore and I get nothing out of it.

Anyway, once you have working build, you can proceed with the initial setup:

## Quake II

Run the program, go to Settings, Controller Configuration, Controller 1:
```
Profile: Keyboard-QuakeII
Gamepad: Keyboard
Mouse: Quake II
Pak: whatever
```

Start Quake II, go to Options, Player, Setup.
```
Crosshair ON
Status Bar whatever
Auto Center OFF
Always Run ON
X Sensitivity MAX
Y Sensitivity MAX
Controller Style E
```

The controls are then:
```
WASD - movement
QE - change weapon
left click - shoot
left shift - walk, proceed in menu (A)
space - jump, go back in menu (B)
enter - start
```

Please note that there is noticeable input lag, but it is not significantly worse than when using gamepad. I wonder if there is such input lag when playing on the real hardware.

## Duke Nukem 64

Run the program, go to Settings, Controller Configuration, Controller 1:
```
Profile: Keyboard-DukeNukem64
Gamepad: Keyboard
Mouse: Duke Nukem 64
Pak: whatever
```

Start the game, keep the default control settings.

The controls are then:
```
WASD - movement
E - open, (A)
R - change weapon
left click - shoot
right click - center y axis (useful before entering menu)
T - change item
Q - use item
left shift - crouch, (B)
space - jump
enter - start
```

Original readme follows below.

# simple64 website

**https://simple64.github.io**

# Downloads

#### Windows: **https://github.com/simple64/simple64/releases**

#### Linux: **https://flathub.org/apps/details/io.github.simple64.simple64**

#### Mac OS: No releases currently, requires a maintainer.

# Wiki

**https://github.com/simple64/simple64/wiki**

Check the Wiki page Simple64 FAQ for CPU and GPU requirements. 
**Do this before asking for help!**
