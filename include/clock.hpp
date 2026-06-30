// Ad Maiorem Dei Gloriam!
#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <iostream>
#include <chrono>
#include <thread>

class Clock {
public:
    static float getFrameTime();
    static void initTick();
    static void finishTick();

    static void setTargetFPS(int fps);

private:
    static int mTargetFPS;
    static std::chrono::time_point<std::chrono::high_resolution_clock> mPrevStartTick;
};

#endif