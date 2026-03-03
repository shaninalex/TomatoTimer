//
// Created by alex on 3/3/26.
//

#ifndef TOMATOTIMER_INOTIFICATIONSERVICE_H
#define TOMATOTIMER_INOTIFICATIONSERVICE_H
#include <string>

namespace platform {
    class INotificationService {
    public:
        virtual void notify(std::string title, std::string body);
        virtual ~INotificationService() = default;
    };
}

#endif //TOMATOTIMER_INOTIFICATIONSERVICE_H