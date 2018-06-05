//
// Created by francesco on 17/03/18.
//

#include "Hero.h"


Hero::Hero(float g, float s, sf::Vector2f v, int j, int k, int kg, int p)
        : gravity (g), shoot (s), velocity (v), jump_block (j), killYellow (k), killGreen (kg), point (p) {
    Reset ();

}


Hero::~Hero() {
    bullet.clear ();
}

void Hero::Reset() {
    Create_Sethero ();
}


void Hero::Create_Sethero() {//SETTA CARATTERISTICHE DI HERO

    doodle.setPosition (100, 15000);
    doodle.setSize (sf::Vector2f (20, 40));
    doodle.setFillColor (sf::Color (144, 238, 144));

}


void Hero::Update() {
    Collision ();
    Shoot ();
}


void Hero::Shoot() {//FUNZIONE CHE SPARA PROIETTILE 

    if (sf::Keyboard::isKeyPressed (sf::Keyboard::C)) {
        Create_Bullet ();
        bullet.emplace_back (sf::CircleShape (b));
    }

    for (size_t j = 0; j < bullet.size (); ++j) {
        bullet[j].move (0, -shoot);
        Setnumbullet ();

        if (bullet[j].getPosition ().y < doodle.getPosition ().y - doodle.getSize ().y - 100) {
            bullet.erase (bullet.begin () + j); //ERASE SE BULLET SUPERA UN CERTO RANGE

        }
    }
    bullet.resize (2);

}


void Hero::Jump() {
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::D) && !sf::Keyboard::isKeyPressed (sf::Keyboard::A)) {
        velocity.y -= gravity;
        doodle.setPosition (doodle.getPosition ().x + velocity.x, doodle.getPosition ().y - velocity.y);
        //MI POSIZIONA HERO A DESTRA RISPETTO A POSIZIONE PRECEDENTE
    } else if (sf::Keyboard::isKeyPressed (sf::Keyboard::A) && !sf::Keyboard::isKeyPressed (sf::Keyboard::D)) {
        velocity.y -= gravity;
        doodle.setPosition (doodle.getPosition ().x - velocity.x, doodle.getPosition ().y - velocity.y);
        //MI POSIZIONA HERO A SINISTRA RISPETTO A POSIZIONE PRECEDENTE
    }

    velocity.y -= gravity;      //come si muove l'eroe se non si preme nessun tasto
    doodle.setPosition (doodle.getPosition ().x, doodle.getPosition ().y - velocity.y);

}

bool Hero::Collision() {

    if (velocity.y == 0) {
        doodle.setPosition (doodle.getPosition ().x, doodle.getPosition ().y);
        doodle.setPosition (doodle.getPosition ().x, doodle.getPosition ().y + gravity);
        //se arriva alla sua massima altezza torna indietro per effetto della gravita
    }

    if (doodle.getPosition ().x <= pointzero) { //se l'eroe arriva alla grandezza massima o minima di x riappare dal lato opposto
        doodle.setPosition (maxsize, doodle.getPosition ().y);
        repos = true;
    } else if (doodle.getPosition ().x >= maxsize) {
        doodle.setPosition (pointzero, doodle.getPosition ().y);
        repos = true;
    }

    return repos;
   
}


bool Hero::GameOver(bool death) {
    SetDeath ();//SETTA MORTE A TRUE
    if (death) {
        doodle.setFillColor (sf::Color::Black);
    }
    return death;
}

void Hero::Reneder(sf::RenderWindow &window) {
    window.draw (doodle);
    for (const auto &b : bullet) {
        window.draw (b);
    }
}

float Hero::Setvelocity() {
    velocity.y = 0.1f;//risetta la velocità quando tocca o un blocco
}


void Hero::Create_Bullet() {//GENERALITA DI BULLET
    b.setRadius (5);
    b.setFillColor (sf::Color::Red);
    b.setPosition (doodle.getPosition ().x + doodle.getSize ().x / 2, doodle.getPosition ().y);
}


sf::FloatRect Hero::GetposBullet() {//FUNZIONE CHE RITORNA IL RECT DI BULLET PER INTERSECT
    sf::FloatRect bulletshape;
    for (auto &i : bullet) {
        bulletshape = i.getGlobalBounds ();
    }
    return bulletshape;
}


void Hero::Notify() const {
    for (auto itro = observer.begin (); itro != observer.end (); ++itro) {
        (*itro)->Modify (killYellow, jump_block, point, killGreen, numbullet);
    }
}

void Hero::Attach(Observer *o) {
    observer.push_back (o);
}

void Hero::Detach(Observer *o) {
    observer.remove (o);
}


int Hero::SetJump() {
    jump_block += 1;
    Changed ();
    return jump_block;

}

int Hero::SetKillYellow() {
    killYellow += 1;
    Changed ();
    return killYellow;
}

int Hero::SetKillGreen() {
    killGreen += 1;
    Changed ();
    return killGreen;
}

int Hero::Setpoint(int pt) {
    point = pt;
    Changed ();
    return point;
}

int Hero::Setnumbullet() {
    numbullet += 1;
    Changed ();
    return numbullet;
}

sf::Vector2f Hero::SetPositionTest(int index) {
    doodle.setPosition (doodle.getPosition ().x + index, doodle.getPosition ().y + index);
    return {doodle.getPosition ().x, doodle.getPosition ().y};
}

void Hero::SetDeath() {
    if (death) {
        death = false;
    } else death = true;
}



