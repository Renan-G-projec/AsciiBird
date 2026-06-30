// Ad Maiorem Dei Gloriam!

#include "player.hpp"

Player::Player(int posX, int posY) : realPosY{posY}, velY{0} {
    mSpr.x = posX;
    mSpr.y = posY;
}

void Player::update(float deltatime) {
    velY += (GRAVITY);

    if (InputHandler::isKeyPressed(' ')) {
        jump(JMP_FORCE);
    }

    realPosY += velY;
    mSpr.y = static_cast<int>(realPosY);
}

void Player::jump(float jumpForce) {
    velY = -jumpForce;
}

void Player::reset() {
    velY = 0;
    realPosY = 1;
    mSpr.y = 1;
}

Sprite& Player::getSprite() { return mSpr; }

Hitbox Player::getHitbox() {
    return Hitbox{mSpr.x, mSpr.y, mSpr.width, mSpr.height};
}