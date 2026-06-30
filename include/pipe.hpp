// Ad Maiorem Dei Gloriam!
#ifndef PIPE_HPP
#define PIPE_HPP

#include "renderer.hpp"

class Pipe {
public:

    void update();

    void chooseRandomY();
    void setX(int newx);

    void setVel(float newVel);

    Sprite& getSprite();

private:
    Sprite mSpr{"assets/pipe.ascii"};

    float realVelX;
    float realPosX;

};

#endif