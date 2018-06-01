//
// Created by francesco on 05/05/18.
//

#ifndef AA_JUMP_OBSERVER_H
#define AA_JUMP_OBSERVER_H


class Observer {
public:
    virtual void Modify(int killYellow, int jump_block, int point, int killGreen, int numbullet)=0;

protected:
    virtual~Observer() {};


};


#endif //AA_JUMP_OBSERVER_H
