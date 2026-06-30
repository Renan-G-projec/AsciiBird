// Ad Maiorem Dei Gloriam!
#include <iostream>
#include "clock.hpp"

#define WINDOW_WIDTH 60
#define WINDOW_HEIGHT 30

// Test
int main() {
    for (int i = 0; i <= 60; i++) {
        Clock::initTick();
        std::cout << i << '\n';
        Clock::finishTick();
    }
    std::cout << "Hello, World!\n";
    return 0;
}