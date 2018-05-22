//
// Created by francesco on 16/05/18.
//

#ifndef AA_JUMP_STRATEGYMOVE_H
#define AA_JUMP_STRATEGYMOVE_H


#include <SFML/Graphics.hpp>


class StrategyMove{
public:
    StrategyMove(float mx,float my):maxX(mx),maxY(my){}


    virtual sf::Vector2f Strategy_move()=0;

protected:

    float maxX;
    float maxY;



};




#endif //AA_JUMP_STRATEGYMOVE_H
