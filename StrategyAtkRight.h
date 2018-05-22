//
// Created by francesco on 22/05/18.
//

#ifndef AA_JUMP_STRATEGYATKRIGHT_H
#define AA_JUMP_STRATEGYATKRIGHT_H


#include "StrategyMove.h"

class StrategyAtkRight: public StrategyMove  {
public:
    StrategyAtkRight(float maxX,float maxY):StrategyMove (maxX,maxY){}


    sf::Vector2f Strategy_move()override{
        sf::Vector2f item;
        item.x=maxX;
        item.y=maxY;
        return  item;
    }

private:

};


#endif //AA_JUMP_STRATEGYATKRIGHT_H
