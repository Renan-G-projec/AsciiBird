// Ad Maiorem Dei Gloriam!
#include "inputHandler.hpp"

#ifdef _WIN32 // Windows

#else // Unix 

#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

struct termios oldt, newt;

bool InputHandler::mKeyPressedTable[256];
char InputHandler::previousPressedKey;

void InputHandler::init() {
    memset(&mKeyPressedTable, 0, sizeof(mKeyPressedTable));
    previousPressedKey = 0;

    tcgetattr(0, &oldt);

    // Copies everything
    newt = oldt;

    // Enter pressing disable
    newt.c_lflag &= ~ICANON;
    newt.c_lflag &= ~ECHO;

    // Set the time
    newt.c_cc[VTIME] = 0;
    newt.c_cc[VMIN] = 0;

    tcsetattr(0, TCSANOW, &newt);


}

void InputHandler::finish() {
    tcsetattr(0, TCSANOW, &oldt);
}

void InputHandler::update() {
    char buffer;
    unsigned char readAnything = read(0, &buffer, 1);

    if (readAnything > 0) {
        if (previousPressedKey != 0) mKeyPressedTable[previousPressedKey] = false;
        
        mKeyPressedTable[buffer] = true;
        previousPressedKey = buffer;
    } else {
        if (previousPressedKey != 0) {
            mKeyPressedTable[previousPressedKey] = false;
            previousPressedKey = 0;
        }
    }
}

bool InputHandler::isKeyPressed(char c) {
    return mKeyPressedTable[c];
}

#endif
