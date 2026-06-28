// Ad Maiorem Dei Gloriam!
#include "renderer.hpp"

// Initializes the sprite
Sprite::Sprite(int width, int height, int x, int y) : width(width), height(height), x(x), y(y), data(width * height) {};

// Initializes the framebuffer
Framebuffer::Framebuffer(int width, int height) : width(width), height(height), data(width * height) {};

void Framebuffer::tempLog() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) std::cout << data[i * width + j];
        std::cout << '\n';
    }
}

// Render
void Renderer::render(const Sprite& sprite) {
    for (int y = 0; y < sprite.height; y++) {
        const char fbY = y + sprite.y;
        if (fbY >= mFramebuffer.height) break;
        if (fbY < 0) continue;

        for (int x = 0; x < sprite.width; x++) {
            const int fbX = x + sprite.x;
            if (fbX >= mFramebuffer.width) break;
            if (fbX < 0) continue;

            const char currentChar = sprite.data[y * sprite.width + x];
            const int fbCurrentIndex = fbY * mFramebuffer.width + fbX;

            mFramebuffer.data[fbCurrentIndex] = currentChar;
        }
    }
}