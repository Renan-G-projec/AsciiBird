// Ad Maiorem Dei Gloriam!
#include <iostream>
#include "inputHandler.hpp"
#include "renderer.hpp"
#include "clock.hpp"
#include "player.hpp"
#include "pipe.hpp"

#define WINDOW_WIDTH 40
#define WINDOW_HEIGHT 12

#define WINDOW_FPS 60

// Test
int main() {
    Renderer renderer{WINDOW_WIDTH, WINDOW_HEIGHT};
    InputHandler::init();
    Clock::setTargetFPS(WINDOW_FPS);

    Player player(1, 1);

    Pipe pipe;
    pipe.setVel(-0.1);
    pipe.chooseRandomY();
    pipe.setX(5);

    while (true) {
        Clock::initTick();
        InputHandler::update();
        renderer.clear();

        if (InputHandler::isKeyPressed('q') || InputHandler::isKeyPressed('Q')) break;
        player.update(Clock::getFrameTime());
        pipe.update();

        renderer.render(player.getSprite());
        renderer.render(pipe.getSprite());

        renderer.display();
        Clock::finishTick();
    }

    InputHandler::finish();
    return 0;
}