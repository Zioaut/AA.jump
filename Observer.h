//
// Created by francesco on 05/05/18.
//

#ifndef AA_JUMP_OBSERVER_H
#define AA_JUMP_OBSERVER_H


class Observer {
public:
    Observer();
    ~Observer();
    virtual void update()=0;

};


#endif //AA_JUMP_OBSERVER_H
