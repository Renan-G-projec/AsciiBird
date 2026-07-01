// Ad Maiorem Dei Gloriam!
#include "renderer.hpp"
#include "osDefines.hpp"

// Initializes the sprite
Sprite::Sprite(int width, int height, int x, int y) : width(width), height(height), x(x), y(y), data(width * height) {};
Sprite::Sprite(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        OS_CONSOLE_CLEAR();
        std::cout << "Opps! Sounds like the file " << filename << " wasn't found!\n";
        std::cout << "Remember to download the files in https://github.com/Renan-G-projec/AsciiBird -> (folder assets)\n";
        std::cout << "If you have the folders, just run the binary in the parent directory of the 'assets/' folder!\n";
        std::cout << ":)\n";

        exit(0);
    }

    file >> width >> height;

    data.reserve(width * height);

    file.ignore();

    std::string line;

    for (int i = 0; i < height; i++) {
        std::getline(file, line);

        for (int j = 0; j < width; j++) {
            data.push_back(line[j]);
        }
    }

}

// Initializes the framebuffer
Framebuffer::Framebuffer(int width, int height) : width(width), height(height), data(width * height) {};

// Render
Renderer::Renderer(int width, int height) : mFramebuffer{width, height} {};

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

void Renderer::clear() {
    OS_CONSOLE_CLEAR();
    for (int y = 0; y < mFramebuffer.height; y++) {
        for (int x = 0; x < mFramebuffer.width; x++) {
            std::fill(mFramebuffer.data.begin(), mFramebuffer.data.end(), ' ');
        }
    }
}

void Renderer::display() {
    for (int i = 0; i < mFramebuffer.height; i++) {
        for (int j = 0; j < mFramebuffer.width; j++) std::cout << mFramebuffer.data[i * mFramebuffer.width + j];
        std::cout << '\n';
    }
    std::cout.flush();
}