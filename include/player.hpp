// Ad Maiorem Dei Gloriam!
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "renderer.hpp" // For Sprite

class Player {
public:

    void jump();
    void update();
    
private:
    Sprite mSpr{"assets/bird.ascii"};

    // The bird does not change it's X position
    float realPosY;
    float velY;
};

#endif