#!/bin/bash

# Run the FollowSun script when the screen is locked or unlocked
/home/tomas/.local/bin/FollowSun

# Monitor the screen lock/unlock events
dbus-monitor --session "type='signal',interface='org.gnome.ScreenSaver'" |
  while read line; do
    if echo "$line" | grep -q "boolean false"; then
      # Screen unlocked
      /home/tomas/.local/bin/FollowSun
    fi
  done