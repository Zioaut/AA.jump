//
// Created by francesco on 16/05/18.
//

#ifndef AA_JUMP_STRATEGYDEFENSE_H
#define AA_JUMP_STRATEGYDEFENSE_H

#include <utility>

#include "StrategyMove.h"

class StrategyDefenseRight : public StrategyMove {
public:
    explicit StrategyDefenseRight(float maxX, float maxY, bool berserk, int anger) :
            StrategyMove (maxX, maxY), berserk (berserk), anger (anger) {};

    sf::Vector2f Strategy_move() override {
        sf::Vector2f item;
        item.x = -maxX;
        item.y = maxY;
        if (berserk) {
            anger = rand () % 3 + 1;
            item.x = -maxX * anger;
        }
        return item;

    }

private:
    int anger;
    bool berserk;
};


#endif //AA_JUMP_STRATEGYDEFENSE_H
