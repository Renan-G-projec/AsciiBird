// Ad Maiorem Dei Gloriam!
#include <iostream>
#include "inputHandler.hpp"

#define WINDOW_WIDTH 60
#define WINDOW_HEIGHT 30

// Test
int main() {
    InputHandler::init();
    while (1) {
        InputHandler::update();

        if (InputHandler::isKeyPressed('q')) break;
        if (InputHandler::isKeyPressed('s')) std::cout << "hello\n";
    }
    InputHandler::finish();

    std::cout << "Hello, World!\n";
    return 0;
}