# MMRecomp Randomizer

## Setup

### Archipelago Setup
1. Know [Archipelago](https://archipelago.gg/tutorial/Archipelago/setup/en).
2. Download the [apworld](https://github.com/LittlestCube/Archipelago/releases/latest).
3. Place the apworld into `Archipelago/custom_worlds/`.
4. Generate a multiworld, and host the game either locally or on the website.

### Mod Setup
1. Download the (for now) required build of Zelda64Recomp:
    - [Zelda64Recompiled-Windows.zip](https://nightly.link/Zelda64Recomp/Zelda64Recomp/actions/artifacts/2067011142.zip)
    - [Zelda64Recompiled-Linux-X64.zip](https://nightly.link/Zelda64Recomp/Zelda64Recomp/actions/artifacts/2067011982.zip)
    - [Zelda64Recompiled-Linux-ARM64-Release.zip](https://nightly.link/Zelda64Recomp/Zelda64Recomp/actions/artifacts/2067007137.zip)
    - [Zelda64Recompiled-AppImage-X64.zip](https://nightly.link/Zelda64Recomp/Zelda64Recomp/actions/artifacts/2067011977.zip)
    - [Zelda64Recompiled-AppImage-ARM64.zip](https://nightly.link/Zelda64Recomp/Zelda64Recomp/actions/artifacts/2067008504.zip)
2. Download the [mods](https://github.com/LittlestCube/MMRecompRando/releases/latest), as well as `apconnect.txt`.
3. Place the mods within the zip into the Zelda64Recomp mods folder.
    1. If on Windows, this is located at `C:\Users\<username>\AppData\Local\Zelda64Recompiled\mods`.
    2. If on Linux, this is located at `~/.config/Zelda64Recompiled/mods`.
4. If you like, you can add a [texture pack](https://github.com/Zelda64Recomp/Zelda64Recomp/pull/447#issue-2433547959).
    1. Download a `.rtz` file from Darío's PR.
    2. Unzip the file ending in .001, and place the resulting `.rtz` in your mods folder.
5. Place `apconnect.txt` next to `Zelda64Recompiled.exe`, and fill it out with your server connection information.
6. Open `Zelda64Recompiled.exe`, select your ROM, and hit Start Game.
7. Go nuts.

## FAQ

### When I press "Start Game" the whole thing crashes! What gives?

Make sure you have a file named "apconnect.txt" (without the quotes) in the same folder as the exe, and that it contains the correct connection information for your Archipelago server slot.

### I got Letter to Kafei and now I can't use the Pendant of Memories! Is it just gone?

Try moving your cursor to the Letter to Kafei and pressing the N64's L button. That should cycle through all quest items in that slot. That's true for the Moon's Tear item slot and the Room Key item slot as well.

## Writing mods
See [this document](https://hackmd.io/fMDiGEJ9TBSjomuZZOgzNg) for an explanation of the modding framework, including how to write function patches and perform interop between different mods.

## Tools
You'll need to install `clang` and `make` to build rando.
* On Windows, using [chocolatey](https://chocolatey.org/) to install both is recommended. The packages are `llvm` and `make` respectively.
* On MacOS, these can both be installed using Homebrew, as well as `zip`. Apple clang won't work, as you need a mips target for building the mod code.
* On Linux, install the above packages, and some additional ones: `clang`, `make`, `llvm`, `lld`, `zip`, using your distro's package manager.

You'll also need to build [N64Recomp](https://github.com/N64Recomp/N64Recomp) for the `RecompModTool` and `OfflineModRecomp` utilities.

## Building
* First, run `make offline` (with an optional job count) to build the mod code itself.
* Oops, all done.
