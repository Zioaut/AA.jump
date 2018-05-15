//
// Created by francesco on 15/03/18.
//

#ifndef AA_JUMP_GAME_H
#define AA_JUMP_GAME_H


#include "Window.h"
#include "Hero.h"
#include "Enemy.h"
#include "Block.h"
#include "Maps.h"
#include "Achievments.h"

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
    Hero hero;
    Enemy enemy;
    Block block;
    Maps maps;
    Achievments achievments;



};


#endif //AA_JUMP_GAME_H
