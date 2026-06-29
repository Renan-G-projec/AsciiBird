// Ad Maiorem Dei Gloriam!
#include <iostream>
#include "physicsEngine.hpp"

#define WINDOW_WIDTH 60
#define WINDOW_HEIGHT 30

// Test
int main() {
    std::cout << PhysicsEngine::checkCollisionRect({1, 1, 2, 2}, {3, 4, 2, 2}) << '\n';

    std::cout << "Hello, World!\n";
    return 0;
}