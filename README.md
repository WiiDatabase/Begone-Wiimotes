# Begone Wiimotes! Plugin for the Wii U Plugin System

This plugin for WUPS disconnects Wiimotes with a GamePad button combination. Please do not use this to annoy your friends.

## Installation

1. Install Aroma
2. Check the Releases page and download the [latest non-preview version](https://github.com/WiiDatabase/Begone-Wiimotes/releases/latest) of this plugin
3. Extract it to "`SD://wiiu/environments/aroma/plugins`"
4. Done!

## Usage

| Button Combo         | Action                  |
| -------------------- | ----------------------- |
| ZL + L + D-Pad Down  | Disconnect Wii Remote 1 |
| ZL + L + D-Pad Left  | Disconnect Wii Remote 2 |
| ZL + L + D-Pad Up    | Disconnect Wii Remote 3 |
| ZL + L + D-Pad Right | Disconnect Wii Remote 4 |

### Limitations

- Does not work in applets and the HOME menu

## Building

For building you need:

- [wups](https://github.com/Maschell/WiiUPluginSystem)
- [wut](https://github.com/devkitpro/wut)

Install them (in this order) according to their README's. Don't forget the dependencies of the libs itself.

Then you should be able to compile via `make` (with no logging) or `make DEBUG=1` (with logging).

## Buildflags

### Logging

Building via `make` only logs errors (via OSReport). To enable logging via the [LoggingModule](https://github.com/wiiu-env/LoggingModule) set `DEBUG` to `1` or `VERBOSE`.

`make` Logs errors only (via OSReport).  
`make DEBUG=1` Enables information and error logging via [LoggingModule](https://github.com/wiiu-env/LoggingModule).  
`make DEBUG=VERBOSE` Enables verbose information and error logging via [LoggingModule](https://github.com/wiiu-env/LoggingModule).

If the [LoggingModule](https://github.com/wiiu-env/LoggingModule) is not present, it'll fallback to UDP (Port 4405) and [CafeOS](https://github.com/wiiu-env/USBSerialLoggingModule) logging.

## Building using the Dockerfile

It's possible to use a docker image for building. This way you don't need anything installed on your host system.

```
# Build docker image (only needed once)
docker build . -t wiiu-plugin-builder

# make
docker run -it --rm -v ${PWD}:/project wiiu-plugin-builder make DEBUG=1

# make clean
docker run -it --rm -v ${PWD}:/project wiiu-plugin-builder make clean
```

## Format the code via docker

`docker run --rm -v ${PWD}:/src ghcr.io/wiiu-env/clang-format:13.0.0-2 -r ./src -i`
