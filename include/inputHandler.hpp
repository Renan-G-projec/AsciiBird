// Ad Maiorem Dei Gloriam!
#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

class InputHandler {
public:

    static void init();
    static void finish();

    static void update();

    static bool isKeyPressed(const char);

private:
    static char previousPressedKey;
    static bool mKeyPressedTable[256];
};

#endif