// Ad Maiorem Dei Gloriam!
#ifndef PIPE_HPP
#define PIPE_HPP

#include "renderer.hpp"
#include "random.hpp"

class Pipe {
public:

    Pipe(int startingX,float startingVel);

    void update();

    void chooseRandomY();
    void setX(int newx);

    void setVel(float newVel);

    Sprite& getSprite();

private:
    Sprite mSpr{"assets/pipe.ascii"};

    float realVelX;
    float realPosX;

    // Defines the spawn of the pipes. Shall be the right border.
    int defaultBorder;

};

#endif