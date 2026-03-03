cmake_minimum_required(VERSION 4.1)
project(TomatoTimer)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/core)
include_directories(src/platform)

add_executable(TomatoTimer
        src/apps/cli_app.cpp
        src/core/PomodoroSession.cpp
        src/core/PomodoroSession.h
        src/core/Timer.cpp
        src/core/Timer.h
        src/platform/INotificationService.h
        src/platform/DesktopNotificationService.cpp
        src/platform/DesktopNotificationService.h
)
