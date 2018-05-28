//
// Created by francesco on 14/05/18.
//

#ifndef AA_JUMP_ACHIEVMENTS_H
#define AA_JUMP_ACHIEVMENTS_H
#define MAX_LINES 30
#define MAX_LINES_LEN 255

#include "Observer.h"
#include "Subject.h"
#include "Hero.h"
#include "DisplayElement.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>



class Achievments: public Observer, public DisplayElement {
public:
    explicit Achievments(Subject*hero);
    ~Achievments()override ;
    void Modify(int ky,int j,int p,int kg,int nb) override;
    void Display();
    void LoadAch();





protected:
    char string[MAX_LINES] [MAX_LINES_LEN];
    Subject*hero;
    int killYellow;
    int jump_block;
    int killGreen;
    int point;
    int numbullet;
    int a,b,c,d;

};


#endif //AA_JUMP_ACHIEVMENTS_H
