// Ad Maiorem Dei Gloriam!
#ifndef PIPE_HPP
#define PIPE_HPP

#include "renderer.hpp"

class Pipe {
public:

    void update();

    void chooseRandomY(int centerYMinimum, int centerYMaximum);
    void setX(int newx);

    void setVel(float newVel);

    Sprite getSprite();

private:
    Sprite mSpr{"assets/pipe.hpp"};

    float realVelX;
    float realPosX;

};

#endif