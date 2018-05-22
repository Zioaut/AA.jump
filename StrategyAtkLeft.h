//
// Created by francesco on 16/05/18.
//

#ifndef AA_JUMP_STRATEGYATKLEFT_H
#define AA_JUMP_STRATEGYATKLEFT_H

#include <utility>

#include "StrategyMove.h"

class StrategyAtkLeft: public StrategyMove{
public:
   StrategyAtkLeft(float maxX,float maxY)
           :StrategyMove(maxX,maxY){};

    sf::Vector2f Strategy_move()override{
        sf::Vector2f item;
        item.x=-maxX;
        item.y=maxY;
        return item;
    }

private:
};


#endif //AA_JUMP_STRATEGYATKLEFT_H
