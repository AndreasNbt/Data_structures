//
// Created by andre on 19/5/2021.
//

#include <iostream>
#include "Timer.h"

void Timer::start() {
    startTime = std::chrono::steady_clock::now();
}

void Timer::stop() {
    endTime = std::chrono::steady_clock::now();
}

double Timer::getDuration() {
    auto dur = (double)std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() / 1000;
    return dur;
}
