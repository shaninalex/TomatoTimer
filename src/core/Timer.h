//
// Created by alex on 3/3/26.
//

#ifndef TOMATOTIMER_TIMER_H
#define TOMATOTIMER_TIMER_H
#include <chrono>

namespace core {

    enum class TimerState {
        IDLE,
        RUNNING,
        PAUSED,
        FINISHED,
    };

    class Timer {
    public:
        using clock = std::chrono::steady_clock;
        using seconds = std::chrono::seconds;

        explicit Timer(seconds duration);

        void start();
        void pause();
        void resume();
        void reset();

        void update(seconds delta);

        TimerState state() const noexcept;
        seconds remaining() const noexcept;
        seconds elapsed() const noexcept;
        seconds duration() const noexcept;

    private:
        seconds duration_;
        seconds elapsed_;
        TimerState state_;
    };

}

#endif //TOMATOTIMER_TIMER_H
