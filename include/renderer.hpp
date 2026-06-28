// Ad Maiorem Dei Gloriam!
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct Sprite {
    Sprite(int width, int height, int x, int y);
    Sprite(const std::string& filename);

    int width, height, x, y;
    std::vector<char> data;
};

// Represents the screen
struct Framebuffer {
    Framebuffer(int width, int height);

    std::vector<char> data;
    int width, height;

    void tempLog();
};


// Has the screen and modifies it
class Renderer {
public:
    Renderer() = default;
    Renderer(const Renderer&) = delete;
    ~Renderer() = default;

    void render(const Sprite&);

    void clear();
    void display();

    Framebuffer mFramebuffer;
};

#endif