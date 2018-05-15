//
// Created by francesco on 14/05/18.
//

#ifndef AA_JUMP_DISPLAYELEMENT_H
#define AA_JUMP_DISPLAYELEMENT_H

#include <SFML/Graphics/RenderWindow.hpp>

class DisplayElement{
 public:
virtual void Display()=0;
 protected:
    virtual  ~DisplayElement(){};
};


#endif //AA_JUMP_DISPLAYELEMENT_H

