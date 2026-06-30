// Ad Maiorem Dei Gloriam!
#include "random.hpp"

int Random::randint(int min, int max) {
    return (rand() % std::abs(max - min)) + min;
}