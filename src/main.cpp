// Ad Maiorem Dei Gloriam!
#include <iostream>
#include "renderer.hpp"

#define WINDOW_WIDTH 60
#define WINDOW_HEIGHT 30

int main() {
    Renderer renderer{WINDOW_WIDTH, WINDOW_HEIGHT};

    renderer.display();

    std::cout << "Hello, World!\n";
    return 0;
}