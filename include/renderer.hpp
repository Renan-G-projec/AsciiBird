// Ad Maiorem Dei Gloriam!
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

struct Sprite {}; // Forward declaration because is not implemented yet.
struct Shape {}; // Same thing

struct Framebuffer {
    Framebuffer(int width, int height);

    std::vector<char> data;
    int width, height;
};

class Renderer {
public:
    Renderer() = default;
    Renderer(const Renderer&) = delete;
    ~Renderer() = default;

    void render(const Sprite&);
    void render(const Shape&);

    void clear();

private:
    Framebuffer mFramebuffer;
};

#endif