# Quake II with mouse on N64

**https://www.youtube.com/watch?v=fVUlUofX8T8**

**https://www.youtube.com/watch?v=qi255SCU07k**

I wanted to play N64 version of Quake II with a mouse, so I hacked the support into the emulator.

Built nicely for me in Linux using ./build.sh. I am not going to provide Windows build because it is a chore and I get nothing out of it.

Anyway, once you have working build, you can proceed with the initial setup:

Run the program so that ini files are created. Exit.

Find input-profiles.ini and add the following block:
```
[Keyboard-Quake2]
A="225,0"
AxisDown="81,0"
AxisLeft="80,0"
AxisRight="79,0"
AxisUp="82,0"
B="44,0"
CDown="8,0"
CLeft="13,0"
CRight="20,0"
CUp="12,0"
DPadD="22,0"
DPadL="27,0"
DPadR="6,0"
DPadU="26,0"
Deadzone=5
L="4,0"
MouseSensitivity=100
R="7,0"
Sensitivity=100
Start="40,0"
Z="29,0"
```

Run the program, go to Settings, Controller Configuration:
```
Profile: Keyboard-Quake2
Gamepad: Keyboard
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

To start mouse look, click into the game window. To release the mouse, press ~ or numpad Enter.

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
