// Ad Maiorem Dei Gloriam!
#include "pipe.hpp"

void Pipe::update() {
    realPosX += realVelX;
    mSpr.x = static_cast<int>(realPosX);

    if (mSpr.x + mSpr.width < 0) {
        chooseRandomY();
        setX(20);
        return;
    }
}

void Pipe::setX(int newx) {
    realPosX = static_cast<float>(newx);
    mSpr.x = newx; 
}

void Pipe::setVel(float newVel) {
    realVelX = newVel;
}

void Pipe::chooseRandomY() {
    mSpr.y = -11; 
}

Sprite& Pipe::getSprite() {

    return mSpr;
}