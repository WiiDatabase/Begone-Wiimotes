Begone Wiimotes! Plugin for the Wii U Plugin System
===================================================
This plugin for WUPS disconnects Wiimotes with a button press! Just press ZL + L + D-Pad in one of the four directions (Down = Wiimote 1, Left = Wiimote 2, etc.) to disconnect the Wiimotes. Please do not use this to annoy your friends.

## Wii U Plugin System
This is a plugin for the [Wii U Plugin System (WUPS)](https://github.com/Maschell/WiiUPluginSystem/). To be able to use this plugin you have to place the resulting `.mod` file into the following folder:

```
sd:/wiiu/plugins
```
When the file is placed on the SDCard you can load it with [plugin loader](https://github.com/Maschell/WiiUPluginLoader/releases).

## Limitations
* Does not work in applets and the HOME menu

## Building
For building you need:
- [wups](https://github.com/Maschell/WiiUPluginSystem)
- [wut](https://github.com/decaf-emu/wut)
- [libutilswut](https://github.com/Maschell/libutils/tree/wut) (WUT version) for common functions.

Install them (in this order) according to their README's. Don't forget the dependencies of the libs itself.
