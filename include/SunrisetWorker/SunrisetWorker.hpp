// MIT License
// Copyright (c) 2024-2025 Tomáš Mark

#ifndef __SUNRISETWORKER_HPP
#define __SUNRISETWORKER_HPP

#include <SunrisetWorker/version.h>
#include <filesystem>
#include <string>
#include <utility>

extern "C" {
#include "SunrisetC/sunriset.h"
}

// Public API

namespace dotname {

  struct Params {
    std::pair<bool, double> lat;
    std::pair<bool, double> lon;
    std::pair<bool, int> utcOffsetMinutes;
    std::pair<bool, int> riseOffsetMinutes;
    std::pair<bool, int> setOffsetMinutes;
    std::pair<bool, bool> clear;
  };

  class SunrisetWorker {

    const std::string libName_ = std::string ("SunrisetWorker v.") + SUNRISETWORKER_VERSION;

  public:
    SunrisetWorker ();
    // SunrisetWorker (const std::filesystem::path& assetsPath, double lat, double lon,
    //                 int utcOffsetMinutes, int riseOffsetMinutes, int setOffsetMinutes, bool clear);
    SunrisetWorker (const std::filesystem::path& assetsPath, Params& params);
    ~SunrisetWorker ();

    int loadConfig ();
    int saveConfig ();

    void switchLightThemeGNome (bool lightTheme) {
      if (lightTheme) {
        // Switch to light theme
        std::system ("gsettings set org.gnome.desktop.interface color-scheme 'default'");
        std::system ("gsettings set org.gnome.desktop.interface gtk-theme 'Adwaita'");
      } else {
        // Switch to dark theme
        std::system ("gsettings set org.gnome.desktop.interface color-scheme 'prefer-dark'");
        std::system ("gsettings set org.gnome.desktop.interface gtk-theme 'Adwaita-dark'");
      }
    }

    template <typename T> std::string to24Time (T time) {
      // Convert time to 24-hour format
      int hours = static_cast<int> (time);
      int minutes = static_cast<int> ((time - hours) * 60);
      return std::to_string (hours) + ":" + (minutes < 10 ? "0" : "") + std::to_string (minutes);
    }

  private:
    std::filesystem::path configPath_;
    
    double lat_;
    double lon_;
    int utcOffsetMinutes_;
    int riseOffsetMinutes_;
    int setOffsetMinutes_;
    bool clear_;
    Params params_;

    int year_;
    int month_;
    int day_;

    double rise_;
    double set_;
    double currentTime_;

    std::string riseTime_;
    std::string setTime_;

    std::string riseTimeWithOffset_;
    std::string setTimeWithOffset_;

    std::tm now_tm_; // Local time
  };

} // namespace dotname

#endif // __SUNRISETWORKER_HPP