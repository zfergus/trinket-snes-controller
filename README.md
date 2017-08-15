# Trinket SNES Controller

<center><img src="snes-controller.png"></center>

Script for Adafruit's Trinket that reads in the input from and SNES controller
and outputs keystrokes.

## Usage
This code is designed for a Trinket 5V. Follow these steps to setup Adafruit 
products to work with the Arduino IDE: [https://learn.adafruit.com/adafruit-arduino-ide-setup/overview](https://learn.adafruit.com/adafruit-arduino-ide-setup/overview). 
Set the board to `Adafruit Trinket 16MHz`, and set the programmer to 
`USBtinyISP`. Learn more at [https://learn.adafruit.com/introducing-trinket/setting-up-with-arduino-ide](https://learn.adafruit.com/introducing-trinket/setting-up-with-arduino-ide).

### Quick Reference

Board: `Adafruit Trinket 16MHz`

Programmer: `USBtinyISP`

### Note
There will be a couple warnings, but they do not affect functionality. The code
should compile if the environment is set up correctly.

Example compilation ([path\to] is a system specific path):
```
Build options changed, rebuilding all
In file included from [path\to]\Arduino\libraries\TrinketKeyboard\usbdrvasm_includer.S:24:0:
[path\to]\Arduino\libraries\TrinketKeyboard\usbdrv/usbdrvasm.S:17:0: warning: "__SFR_OFFSET" redefined [enabled by default]
 #define __SFR_OFFSET 0      /* used by avr-libc's register definitions */
 ^
In file included from [path\to]\appdata\roaming\arduino15\packages\arduino\tools\avr-gcc\4.8.1-arduino2\avr\include\avr\io.h:99:0,
                 from [path\to]\Arduino\libraries\TrinketKeyboard\cmdline_defs.h:26,
                 from [path\to]\Arduino\libraries\TrinketKeyboard\usbdrvasm_includer.S:22:
[path\to]\appdata\roaming\arduino15\packages\arduino\tools\avr-gcc\4.8.1-arduino2\avr\include\avr\sfr_defs.h:141:0: note: this is the location of the previous definition
 #    define __SFR_OFFSET 0x20
 ^

Sketch uses 3,974 bytes (74%) of program storage space. Maximum is 5,310 bytes.
Global variables use 106 bytes of dynamic memory.
```

## Contents
* The NES Controller Handeler.pdf - Specifies how to interface with a 
NES/SNES controller
* TrinketSNESController.ino - Arduino sketch for the trinket to interface as a
SNES controller.

## Includes
This code is based on the Adafruit code base for the Trinket. 
This code is designed for a Trinket 5V.
