// Ad Maiorem Dei Gloriam!
#include "clock.hpp"
using namespace std::chrono;

time_point<high_resolution_clock> Clock::mPrevStartTick;


void Clock::initTick() {
    mPrevStartTick = high_resolution_clock::now();
}

void Clock::finishTick() {
    const auto targetTime = duration<float, std::milli>{1/60.0 * 1000};

    const auto now = high_resolution_clock::now();

    const auto delta = now - mPrevStartTick;

    if (delta <= targetTime) std::this_thread::sleep_for(targetTime - delta);
}