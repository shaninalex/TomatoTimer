//
// Created by alex on 3/3/26.
//namespace platform {


#ifndef TOMATOTIMER_DESKTOPNOTIFICATIONSERVICE_H
#define TOMATOTIMER_DESKTOPNOTIFICATIONSERVICE_H
#include <string>

namespace platform {
    class DesktopNotificationService {
    public:
        void notify(std::string title, std::string body);

    public:
        void notify_linux(const std::string& title, const std::string& body);
        void notify_mac(const std::string& title, const std::string& body);
        void notify_windows(const std::string& title, const std::string& body);
    };
}

#endif //TOMATOTIMER_DESKTOPNOTIFICATIONSERVICE_H