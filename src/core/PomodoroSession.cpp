//
// Created by alex on 3/3/26.
//

#include "PomodoroSession.h"

namespace core {

    PomodoroSession::PomodoroSession(
        int workMinutes,
        int shortBreakMinutes,
        int longBreakMinutes,
        int cyclesBeforeLongBreak
    )
        : timer_(std::chrono::minutes(workMinutes)),
          phase_(SessionPhase::Work),
          workMinutes_(workMinutes),
          shortBreakMinutes_(shortBreakMinutes),
          longBreakMinutes_(longBreakMinutes),
          cyclesBeforeLongBreak_(cyclesBeforeLongBreak),
          completedWorkSessions_(0)
    {
    }

    void PomodoroSession::start() {
        timer_.start();
    }

    void PomodoroSession::pause() {
        timer_.pause();
    }

    void PomodoroSession::resume() {
        timer_.resume();
    }

    void PomodoroSession::reset() {
        phase_ = SessionPhase::Work;
        completedWorkSessions_ = 0;

        timer_.update(std::chrono::minutes(workMinutes_));
        timer_.reset();
    }

    void PomodoroSession::update(std::chrono::seconds delta) {
        timer_.update(delta);

        if (timer_.state() == TimerState::FINISHED) {
            switchPhase();
        }
    }

    void PomodoroSession::switchPhase() {

        if (phase_ == SessionPhase::Work) {

            completedWorkSessions_++;

            if (completedWorkSessions_ % cyclesBeforeLongBreak_ == 0) {
                phase_ = SessionPhase::LongBreak;
                timer_.update(std::chrono::minutes(longBreakMinutes_));
            } else {
                phase_ = SessionPhase::ShortBreak;
                timer_.update(std::chrono::minutes(shortBreakMinutes_));
            }

        } else {

            phase_ = SessionPhase::Work;
            timer_.update(std::chrono::minutes(workMinutes_));
        }

        timer_.reset();
        timer_.start();
    }

    SessionPhase PomodoroSession::phase() const {
        return phase_;
    }

    TimerState PomodoroSession::timerState() const {
        return timer_.state();
    }

    int PomodoroSession::completedWorkSessions() const {
        return completedWorkSessions_;
    }

    std::chrono::seconds PomodoroSession::remaining() const {
        return timer_.remaining();
    }
}