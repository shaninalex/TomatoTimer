#include <iostream>
#include <thread>
#include <chrono>

#include "../core/Timer.h"

using namespace std::chrono_literals;

int main() {
    core::Timer timer(std::chrono::seconds(10));

    std::cout << "Starting 10-second timer...\n";

    timer.start();

    auto previous = core::Timer::clock::now();

    while (timer.state() != core::TimerState::FINISHED) {
        auto now = core::Timer::clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::seconds>(now - previous);

        if (delta.count() > 0) {
            timer.update(delta);
            previous = now;

            std::cout << "Remaining: "
                      << timer.remaining().count()
                      << " seconds\n";
        }

        std::this_thread::sleep_for(100ms);
    }

    std::cout << "Timer finished!\n";

    return 0;
}