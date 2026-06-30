// Ad Maiorem Dei Gloriam!
#include "pipe.hpp"

Pipe::Pipe(int startingX, float startingVel, int* globalPointsRef) : realPosX(static_cast<float>(startingX)), realVelX(startingVel), globalPoints(globalPointsRef) {
    mSpr.x = startingX;
    chooseRandomY();

    defaultBorder = startingX;
}

void Pipe::update()
{
    int prevX = mSpr.x;
    realPosX += realVelX;
    mSpr.x = static_cast<int>(realPosX);

    if (mSpr.x + mSpr.width < 0) {
        chooseRandomY();
        setX(defaultBorder);
    }

    if (prevX != 1 && mSpr.x == 1) (*globalPoints)++;
}

void Pipe::setX(int newx) {
    realPosX = static_cast<float>(newx);
    mSpr.x = newx; 
}

void Pipe::resetX() {
    setX(defaultBorder);
}

void Pipe::setVel(float newVel) {
    realVelX = newVel;
}

void Pipe::chooseRandomY() {
    mSpr.y = Random::randint(-16, 0);
}

Sprite& Pipe::getSprite() {
    return mSpr;
}

Hitbox Pipe::getHitboxUp() {
    return {mSpr.x + 1, mSpr.y, 4, 21};
}

Hitbox Pipe::getHitboxBottom() {
    return {mSpr.x + 1, mSpr.y + 29, 4, 21};
}

