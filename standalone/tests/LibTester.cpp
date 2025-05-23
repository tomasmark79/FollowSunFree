// MIT License
// Copyright (c) 2024-2025 Tomáš Mark

#include "../src/AppCore.hpp"
#include <gtest/gtest.h>

TEST (AppLogic, HandlesArguments) {
  const char* argv[] = { "FollowSun", "--help" };
  EXPECT_EQ (runApp (2, argv), 0);
}
TEST (AppLogic, HandlesArgumentsNoLibrary) {
  const char* argv[] = { "FollowSun", "--omit" };
  EXPECT_EQ (runApp (2, argv), 0);
}
TEST (AppLogic, HandlesArgumentsLog2File) {
  const char* argv[] = { "FollowSun", "--log2file" };
  EXPECT_EQ (runApp (2, argv), 0);
}
TEST (AppLogic, HandlesArgumentsWithCoordinatesAndUTCPraha) {
  const char* argv[] = { "FollowSun", "--lat", "50.0755", "--lon", "14.4378", "--utc", "120" };
  EXPECT_EQ (runApp (7, argv), 0);
}
TEST (AppLogic, HandlesArgumentsWithCoordinatesAndUTCTokyo) {
  const char* argv[] = { "FollowSun", "--lat", "35.6895", "--lon", "139.6917", "--utc", "540" };
  EXPECT_EQ (runApp (7, argv), 0);
}
TEST (AppLogic, HandlesArgumentsWithCoordinatesAndUTCParis) {
  const char* argv[] = { "FollowSun", "--lat", "48.8566", "--lon", "2.3522", "--utc", "120" };
  EXPECT_EQ (runApp (7, argv), 0);
}
TEST (AppLogic, HandlesArgumentsWithCoordinatesAndUTCNewYork) {
  const char* argv[] = { "FollowSun", "--lat", "40.7128", "--lon", "-74.0060", "--utc", "-300" };
  EXPECT_EQ (runApp (7, argv), 0);
}
TEST (AppLogic, HandlesArgumentsWithCoordinatesAndUTCLosAngeles) {
  const char* argv[] = { "FollowSun", "--lat", "34.0522", "--lon", "-118.2437", "--utc", "-480" };
  EXPECT_EQ (runApp (7, argv), 0);
}
TEST (AppLogic, HandlesArgumentsWithCoordinatesAndUTCBeijing) {
  const char* argv[] = { "FollowSun", "--lat", "39.9042", "--lon", "116.4074", "--utc", "480" };
  EXPECT_EQ (runApp (7, argv), 0);
}
TEST (AppLogic, HandlesArgumentsWithCoordinatesAndUTCNewDelhi) {
  const char* argv[] = { "FollowSun", "--lat", "28.6139", "--lon", "77.2090", "--utc", "330" };
  EXPECT_EQ (runApp (7, argv), 0);
}
TEST (AppLogic, HandlesArgumentsWithCoordinatesAndUTCNewMelbourne) {
  const char* argv[] = { "FollowSun", "--lat", "-37.8136", "--lon", "144.9631", "--utc", "660" };
  EXPECT_EQ (runApp (7, argv), 0);
}
