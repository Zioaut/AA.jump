//
// Created by francesco on 22/05/18.
//

#ifndef AA_JUMP_STRATEGYATKRIGHT_H
#define AA_JUMP_STRATEGYATKRIGHT_H


#include "StrategyMove.h"

class StrategyAttack : public StrategyMove {
public:
    StrategyAttack(float maxX, float maxY, int f) : StrategyMove (maxX, maxY), fortune (f) {}


    sf::Vector2f Strategy_move() override {
        sf::Vector2f item;
        fortune = rand () % 5 + 1;
        item.x = maxX;
        item.y = -maxY;
        if (fortune > 3) {
            item.y = maxY * 2;
        }
        return item;
    }

private:
    int fortune;
};


#endif //AA_JUMP_STRATEGYATKRIGHT_H
