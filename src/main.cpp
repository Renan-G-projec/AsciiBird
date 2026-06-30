// Ad Maiorem Dei Gloriam!
#include <iostream>
#include "inputHandler.hpp"
#include "renderer.hpp"
#include "clock.hpp"
#include "player.hpp"
#include "pipe.hpp"

#define WINDOW_WIDTH 40
#define WINDOW_HEIGHT 24

#define WINDOW_FPS 60

// Test
int main() {
    Renderer renderer{WINDOW_WIDTH, WINDOW_HEIGHT};
    InputHandler::init();
    Clock::setTargetFPS(WINDOW_FPS);

    int points = 0;

    Player player(1, 1);
    Pipe pipe{WINDOW_WIDTH, -0.5f, &points};

    bool gameOver = false;

    while (true) {
        Clock::initTick();
        InputHandler::update();
        renderer.clear();

        if (InputHandler::isKeyPressed('q') || InputHandler::isKeyPressed('Q')) break;

        if (!gameOver) {
            player.update(Clock::getFrameTime());
            pipe.update();
            
            gameOver = PhysicsEngine::checkCollisionRect(player.getHitbox(), pipe.getHitboxBottom()) ||
            PhysicsEngine::checkCollisionRect(player.getHitbox(), pipe.getHitboxUp());
            
            const Hitbox pH = player.getHitbox();
            // Outside the window
            if (pH.y + pH.h < 0 || pH.y > WINDOW_HEIGHT) gameOver = true; 
        } else {
            if (InputHandler::isKeyPressed('r') || InputHandler::isKeyPressed('R')) {
                points = 0;
                pipe.chooseRandomY();
                pipe.resetX();

                player.reset();
                gameOver = false;
            } 
        }

        renderer.render(pipe.getSprite());
        renderer.render(player.getSprite());

        renderer.display();

        std::cout << "\nPoints: " << points << '\n';
        if (gameOver) std::cout << "Game Over! Press 'r' to restart.\n";
        Clock::finishTick();
    }

    InputHandler::finish();
    return 0;
}