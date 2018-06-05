//
// Created by francesco on 14/05/18.
//

#include "Achievments.h"

Achievments::Achievments(Subject *hero)
        : hero (hero), jump_block (0), killYellow (0), killGreen (0), point (0), numbullet (0) {
    hero->Attach (this);
    LoadAch ();
    a = 0;
    b = 0;
    c = 0;
    d = 0;


}

Achievments::~Achievments() {
    hero->Detach (this);
}


void Achievments::Modify(int ky, int j, int p, int kg, int nb) {
    killYellow = ky;
    jump_block = j;
    point = p;
    killGreen = kg;
    numbullet = nb;
    Display ();
}


void Achievments::LoadAch() {//CARICA LA STRINGA INDICATA DA STRING[INDEX]
    std::ifstream in ("achievements.txt");
    int j = 0;
    while (in) {
        in.getline ((string[j++]), MAX_LINES_LEN);
    }
}

void Achievments::Display() {//SCRIVE SUL TERMINALE ACHIVMENTS SE SODDISFATTA CONDIZIONE
    if (point >= 10000 && a == 0) {
        std::cout << string[3] << std::endl;
        a = 1;
    }

    if (killGreen == 1 && b == 0) {
        std::cout << string[0] << std::endl;
        b = 1;
    }

    if (killYellow == 1 && c == 0) {
        std::cout << string[1] << std::endl;
        killYellow += 1;
        c = 1;
    }

    if (killYellow + killGreen == 3 && numbullet == 3 && d == 0) {
        std::cout << string[4] << std::endl;
        d = 1;
    }
    if (killYellow + killGreen == 3 && a == 1) {
        std::cout << string[2] << std::endl;
        a = 2;
    }


}




