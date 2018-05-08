//
// Created by francesco on 05/05/18.
//

#ifndef AA_JUMP_SUBJECT_H
#define AA_JUMP_SUBJECT_H


#include <vector>
#include "Observer.h"

class Subject {
public:
    virtual void Attach(Observer*)=0;
    virtual void Detach(Observer*)=0;
    virtual void Notify() =0;


protected:
    virtual ~Subject(){};
};


#endif //AA_JUMP_SUBJECT_H
