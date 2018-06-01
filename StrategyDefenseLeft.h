//
// Created by francesco on 16/05/18.
//

#ifndef AA_JUMP_STRATEGYATKLEFT_H
#define AA_JUMP_STRATEGYATKLEFT_H

#include <utility>

#include "StrategyMove.h"

class StrategyDefenseLeft : public StrategyMove {
public:
    StrategyDefenseLeft(float maxX, float maxY, bool b, int count)
            : StrategyMove (maxX, maxY), berserk (b), count (count) {};

    sf::Vector2f Strategy_move() override {
        sf::Vector2f item;
        item.x = maxX;
        item.y = maxY;
        if (berserk) {
            count = rand () % 3 + 1;
            item.x = maxX * count;
        }
        return item;
    }

private:
    int count;
    bool berserk;
};


#endif //AA_JUMP_STRATEGYATKLEFT_H
