//
// Created by alex on 3/3/26.
//

#ifndef TOMATOTIMER_POMODOROSESSION_H
#define TOMATOTIMER_POMODOROSESSION_H

#include <chrono>
#include "Timer.h"

namespace core {
    enum class SessionPhase {
        Work,
        ShortBreak,
        LongBreak
    };

    class PomodoroSession {
    public:
        PomodoroSession(
            int workMinutes = 25,
            int shortBreakMinutes = 5,
            int longBreakMinutes = 15,
            int cyclesBeforeLongBreak = 4
        );

        void start();

        void pause();

        void resume();

        void reset();

        void update(std::chrono::seconds delta);

        SessionPhase phase() const;

        TimerState timerState() const;

        int completedWorkSessions() const;

        std::chrono::seconds remaining() const;

    private:
        void switchPhase();

        Timer timer_;
        SessionPhase phase_;

        int workMinutes_;
        int shortBreakMinutes_;
        int longBreakMinutes_;

        int cyclesBeforeLongBreak_;
        int completedWorkSessions_;
    };
};

#endif //TOMATOTIMER_POMODOROSESSION_H
