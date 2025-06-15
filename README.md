[![Linux](https://github.com/tomasmark79/FollowSunFree/actions/workflows/linux.yml/badge.svg)](https://github.com/tomasmark79/FollowSunFree/actions/workflows/linux.yml)
[![MacOS](https://github.com/tomasmark79/FollowSunFree/actions/workflows/macos.yml/badge.svg)](https://github.com/tomasmark79/FollowSunFree/actions/workflows/macos.yml)
<!-- [![Windows](https://github.com/tomasmark79/FollowSunFree/actions/workflows/windows.yml/badge.svg)](https://github.com/tomasmark79/FollowSunFree/actions/workflows/windows.yml) -->

<p align="center">
  <img src="assets/followsun.png" alt="FollowSunFree" width="300" />
</p>

# FollowSunFree

FollowSunFree is a lightweight cross-platform C++ application that switches your desktop theme between light and dark modes based on your geographical location and the local solar position (sunrise/sunset times).

Currently implemented and tested with GNOME 42+ on Fedora 42.

FollowSunFree is proudly built with **[D🌀tName C++ Template](https://github.com/tomasmark79/DotNameCppFree)**.

## ⚡ Quick Start (Recommended)

Download the binary tarball and extract the contents of the bin/ and share/ folders into:

    ~/.local/bin/
    ~/.local/share/

Then set it up to run via systemd (user scope) for automatic switching:

```bash
systemctl --user daemon-reload
systemctl --user enable followsun.timer
systemctl --user start followsun.timer
```

🛑 To stop automatic switching:

```bash
systemctl --user stop followsun.timer
```

Systemd unit files (*.service and *.timer) can be found in the assets directory. Customize them to match your user environment.

📖 See also: systemd.service documentation

## 🚀 Usage

> ⚠️ Currently, you must manually specify the --utc offset based on standard or daylight saving time.

Run the binary with arguments that match your location and preferences.

```bash
~/.local/bin/FollowSunFree --lat 50.0755 --lon 14.4378 --utc 120 --riseoffset 60 --setoffset -30
```

Output:

```bash
════════════════════ FOLLOW SUN SUMMARY ════════════════════
📅 20.05.2025 08:24:39
📍 Location: 50.0755°N, 14.4378°E
🌐 UTC offset: 2 hours

🌅 Sunrise: 5:08  ➔  🌆 Sunset: 20:48

User offset adjustments:
   Sunrise: +60 min   Sunset: -30 min

Theme trigger times:
   Light theme at: 6:08 ☀️
   Dark theme at: 20:18 🌚
═══════════════════════════════════════════════════════════════
```

#### Full CLI Options

| Argument         | Short | Type   | Default | Description                                  |
|------------------|-------|--------|---------|----------------------------------------------|
| `--help`         | `-h`  | flag   | -       | Displays help information                    |
| `--log2file`     | `-2`  | bool   | false   | Enables logging to a file                    |
| `--lat`          |       | double | 0       | Latitude                                     |
| `--lon`          |       | double | 0       | Longitude                                    |
| `--utc`          |       | int    | 0       | UTC offset in minutes                        |
| `--riseoffset`   |       | int    | 0       | Sunrise offset in minutes                    |
| `--setoffset`    |       | int    | 0       | Sunset offset in minutes                     |
| `--clear`        |       | bool   | false   | Clear all to default (supress other params)  |


## 💾 Persistent Settings

FollowSunFree automatically saves your last used arguments to a config file in the assets folder. On subsequent runs, it will use those saved settings unless overridden.

To reset everything:

```bash
~/.local/bin/FollowSunFree --clear
````
Or simply run it with new arguments.

## 🌱 Planned Features

- Native support for more desktop environments (e.g., KDE, Windows)
- Automatic detection of UTC offset (daylight saving and standard time)
- Automatic installation of the entire project
- Trigger theme switch immediately after resuming from sleep (no need to wait for the systemd timer trigger)

## Disclaimer

This template is provided "as is," without any guarantees regarding its functionality or suitability for any purpose.

## License

MIT License  
Copyright (c) 2024-2025 Tomáš Mark  

