//
// Created by francesco on 15/03/18.
//

#ifndef AA_JUMP_GAME_H
#define AA_JUMP_GAME_H


#include "Window.h"

class Game {
public:
    Game();

    ~Game();

    void Update();

    void HandleInput();

    void Render();

    Window *GetWindow() { return &window; };

private:
    Window window;

};


#endif //AA_JUMP_GAME_H
