//
// Created by alex on 3/3/26.
//

#include "Timer.h"

namespace core {
    Timer::Timer(seconds duration)
        : duration_(duration),
          elapsed_(seconds::zero()),
          state_(TimerState::IDLE) {
    }

    void Timer::start() {
        if (state_ != TimerState::IDLE)
            return;

        elapsed_ = seconds::zero();
        state_ = TimerState::RUNNING;
    }

    void Timer::pause() {
        if (state_ != TimerState::RUNNING)
            return;

        state_ = TimerState::PAUSED;
    }

    void Timer::resume() {
        if (state_ != TimerState::PAUSED)
            return;

        state_ = TimerState::RUNNING;
    }

    void Timer::reset() {
        elapsed_ = seconds::zero();
        state_ = TimerState::IDLE;
    }

    void Timer::update(seconds delta) {
        if (state_ != TimerState::RUNNING)
            return;

        elapsed_ += delta;

        if (elapsed_ >= duration_) {
            elapsed_ = duration_;
            state_ = TimerState::FINISHED;
        }
    }

    TimerState Timer::state() const noexcept {
        return state_;
    }

    Timer::seconds Timer::remaining() const noexcept {
        return duration_ - elapsed_;
    }

    Timer::seconds Timer::elapsed() const noexcept {
        return elapsed_;
    }

    Timer::seconds Timer::duration() const noexcept {
        return duration_;
    }
}
