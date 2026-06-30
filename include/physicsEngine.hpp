// Ad Maiorem Dei Gloriam!
#ifndef PHYSICS_ENGINE_HPP
#define PHYSICS_ENGINE_HPP

struct Hitbox {
    int x, y;
    int w, h;
};

class PhysicsEngine {
public:
    static bool checkCollisionRect(const Hitbox&, const Hitbox&);
};

#endif