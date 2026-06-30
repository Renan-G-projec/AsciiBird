// Ad Maiorem Dei Gloriam!
#include "pipe.hpp"

Pipe::Pipe(int startingX, float startingVel) : realPosX(static_cast<float>(startingX)), realVelX(startingVel) {
    mSpr.x = startingX;
    chooseRandomY();

    defaultBorder = startingX;
}

void Pipe::update()
{
    realPosX += realVelX;
    mSpr.x = static_cast<int>(realPosX);

    if (mSpr.x + mSpr.width < 0) {
        chooseRandomY();
        setX(defaultBorder);
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
    mSpr.y = Random::randint(-10, 0);
}

Sprite& Pipe::getSprite() {
    return mSpr;
}