// Ad Maiorem Dei Gloriam!
#include <iostream>
#include "clock.hpp"

#define WINDOW_WIDTH 60
#define WINDOW_HEIGHT 30

// Test
int main() {
    Clock::setTargetFPS(60);
    for (int i = 0; i <= 60; i++) {
        Clock::initTick();
        Clock::getFrameTime();
        Clock::finishTick();
    }
    std::cout << "Hello, World!\n";
    return 0;
}