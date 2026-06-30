// Ad Maiorem Dei Gloriam!

#include "player.hpp"

Player::Player(int posX, int posY) : realPosY{posY}, velY{0} {
    mSpr.x = posX;
    mSpr.y = posY;
}

void Player::update(float deltatime) {
    velY += (GRAVITY * deltatime);

    if (InputHandler::isKeyPressed(' ')) {
        jump(JMP_FORCE);
    }

    mSpr.y += velY;
}

void Player::jump(float jumpForce) {
    velY -= jumpForce;
}