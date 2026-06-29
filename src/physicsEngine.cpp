// Ad Maiorem Dei Gloriam!
#include "physicsEngine.hpp"

bool rangesOverlap(int start1, int end1, int start2, int end2) {
    if (start1 >= start2 && start1 <= end2) return true;
    if (start2 >= start1 && start2 <= end1) return true;
    return false;
}

bool PhysicsEngine::checkCollisionRect(const Hitbox& a, const Hitbox& b) {
    return (rangesOverlap(a.x, a.x + a.w, b.x, b.x + b.w) && rangesOverlap(a.y, a.y + a.h, b.y, b.y + b.h));
}