// Ad Maiorem Dei Gloriam!
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "renderer.hpp" // For Sprite
#include "physicsEngine.hpp" // For Hitbox
#include "inputHandler.hpp"

#define GRAVITY 0.02f
#define JMP_FORCE 0.5f

class Player {
public:

    Player(int posX, int PosY);

    void jump(float jumpForce);
    void update(float deltatime);

    void reset();

    Hitbox getHitbox();

    Sprite& getSprite();
    
private:
    Sprite mSpr{"assets/bird.ascii"};

    // The bird does not change it's X position
    float realPosY;
    float velY;
};

#endif