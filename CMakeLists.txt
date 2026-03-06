cmake_minimum_required(VERSION 4.1)
project(TomatoTimer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(src/core)
include_directories(src/platform)
include_directories(src/ui)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(TomatoTimer
        src/core/PomodoroSession.cpp
        src/core/PomodoroSession.h
        src/core/Timer.cpp
        src/core/Timer.h
        src/platform/INotificationService.h
        src/platform/DesktopNotificationService.cpp
        src/platform/DesktopNotificationService.h
        src/main.cpp
        src/ui/MainWindow.cpp
        src/ui/MainWindow.h
)

target_link_libraries(TomatoTimer
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
