#include <iostream>
#include <thread>
#include <chrono>

#include "DesktopNotificationService.h"
#include "PomodoroSession.h"
#include "Timer.h"

using namespace std::chrono_literals;

int main() {
    core::PomodoroSession session;

    session.start();

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        session.update(std::chrono::seconds(1));
        std::cout << "Remaining: "
                  << session.remaining().count()
                  << " seconds\n";
    }
}
