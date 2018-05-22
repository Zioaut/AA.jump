//
// Created by francesco on 16/05/18.
//

#ifndef AA_JUMP_STRATEGYDEFENSE_H
#define AA_JUMP_STRATEGYDEFENSE_H

#include <utility>

#include "StrategyMove.h"

class StrategyDefense: public  StrategyMove{
public:
    explicit StrategyDefense(float max,float maxY,float maxZ):StrategyMove (maxX,maxY),maxZ(maxZ){};

    sf::Vector2f Strategy_move() override {
        sf::Vector2f item;
        item.x=maxX;
        item.y=maxZ;

        return item;

    }
private:
    float maxZ;
};


#endif //AA_JUMP_STRATEGYDEFENSE_H
