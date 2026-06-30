// Ad Maiorem Dei Gloriam!
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "renderer.hpp" // For Sprite
#include "inputHandler.hpp"

#define GRAVITY 0.2f
#define JMP_FORCE 3.0f

class Player {
public:

    Player(int posX, int PosY);

    void jump(float jumpForce);
    void update(float deltatime);
    
private:
    Sprite mSpr{"assets/bird.ascii"};

    // The bird does not change it's X position
    float realPosY;
    float velY;
};

#endif