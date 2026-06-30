// Ad Maiorem Dei Gloriam!
#include <iostream>
#include "inputHandler.hpp"
#include "renderer.hpp"
#include "clock.hpp"

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 24

#define WINDOW_FPS 1

// Test
int main() {
    Renderer renderer{WINDOW_WIDTH, WINDOW_HEIGHT};
    InputHandler::init();
    Clock::setTargetFPS(WINDOW_FPS);

    while (true) {
        Clock::initTick();
        InputHandler::update();
        renderer.clear();

        if (InputHandler::isKeyPressed('q') || InputHandler::isKeyPressed('Q')) break;

        renderer.display();
        Clock::finishTick();
    }

    InputHandler::finish();
    return 0;
}