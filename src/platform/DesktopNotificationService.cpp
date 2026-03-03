//
// Created by alex on 3/3/26.
//

#include "DesktopNotificationService.h"

#include <cstdlib>

namespace platform {

#if defined(__linux__)
#define PLATFORM_LINUX
#elif defined(__APPLE__)
#define PLATFORM_MAC
#elif defined(_WIN32)
#define PLATFORM_WINDOWS
#endif

void DesktopNotificationService::notify(std::string title, std::string body) {
    #ifdef PLATFORM_LINUX
        notify_linux(title, body);
    #elif defined(PLATFORM_MAC)
        notify_mac(title, body);
    #elif defined(PLATFORM_WINDOWS)
        notify_windows(title, body);
    #else
        std::system(("echo " + title + ": " + body).c_str());
    #endif
}

    void DesktopNotificationService::notify_linux(
        const std::string& title,
        const std::string& body)
    {
        std::string command = "notify-send \"" + title + "\" \"" + body + "\"";
        std::system(command.c_str());
    }

    void DesktopNotificationService::notify_mac(
        const std::string& title,
        const std::string& body)
    {
        std::string command =
            "osascript -e 'display notification \"" +
            body +
            "\" with title \"" +
            title +
            "\"'";

        std::system(command.c_str());
    }

    void DesktopNotificationService::notify_windows(
        const std::string& title,
        const std::string& body)
    {
        std::string command =
            "powershell -Command \"New-BurntToastNotification -Text '" +
            title + "', '" + body + "'\"";

        std::system(command.c_str());
    }
}