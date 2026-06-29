// Ad Maiorem Dei Gloriam!
#ifndef PHYSICS_ENGINE_HPP
#define PHYSICS_ENIGNE_HPP

struct Hitbox {
    int x, y;
    int w, h;
};

class PhysicsEngine {

    static bool checkCollisionRect(Hitbox, Hitbox);
};

#endif