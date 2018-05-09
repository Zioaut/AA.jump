//
// Created by francesco on 17/03/18.
//

#include "Hero.h"


Hero::Hero(float g, float s, sf::Vector2f v):gravity(g),shoot(s),velocity(v) {
    Reset ();

 }


Hero::~Hero() {
    bullet.clear ();
}

void Hero::Reset() {
    Create_Sethero ();
}


void Hero::Create_Sethero() {

    doodle.setPosition (100,5500);
    doodle.setSize (sf::Vector2f (20, 40));
    doodle.setFillColor (sf::Color (144, 238, 144));

}


void Hero::Update() {
    Collision ();
    Shoot ();
}


void Hero::Shoot() {

    if (sf::Keyboard::isKeyPressed (sf::Keyboard::C)) {
        Create_Bullet ();
        bullet.emplace_back (sf::CircleShape (b));
    }

    for (size_t j = 0; j < bullet.size (); ++j) {
        bullet[j].move (0, -shoot);

        if (bullet[j].getPosition ().y < doodle.getPosition ().y-doodle.getSize ().y-35) {
            bullet.erase (bullet.begin () + j);
        }
    }
    bullet.resize (2);

}



void Hero::Jump() {
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::D) && !sf::Keyboard::isKeyPressed (sf::Keyboard::A)) {
        velocity.y-=gravity;
        doodle.setPosition (doodle.getPosition ().x+velocity.x,doodle.getPosition ().y-velocity.y);

    } else if (sf::Keyboard::isKeyPressed (sf::Keyboard::A) && !sf::Keyboard::isKeyPressed (sf::Keyboard::D)) {
        velocity.y-=gravity;
        doodle.setPosition (doodle.getPosition ().x-velocity.x,doodle.getPosition ().y-velocity.y);

    }

        velocity.y -= gravity;      //come si muove l'eroe se non si preme nessun tasto
        doodle.setPosition (doodle.getPosition ().x,doodle.getPosition ().y-velocity.y);

}
void Hero::Collision() {

    if(velocity.y==0){
        doodle.setPosition (doodle.getPosition ().x,doodle.getPosition ().y);
        doodle.setPosition (doodle.getPosition ().x,doodle.getPosition ().y+gravity);
        //se arriva alla sua massima altezza torna indietro per effetto della gravita
    }

    if (doodle.getPosition ().x <= 0) {
        doodle.setPosition (500, doodle.getPosition ().y);
    } else if (doodle.getPosition ().x >= 500) {
        doodle.setPosition (0, doodle.getPosition ().y);
    }//se l'eroe arriva alla grandezza massima o minima di x riappare dal lato opposto
 }





bool Hero::GameOver() {
    doodle.setFillColor (sf::Color::Black);

    if (doodle.getPosition ().y +doodle.getSize ().y>=600) {
    }
}

void Hero::Reneder(sf::RenderWindow &window) {
    window.draw (doodle);
     for (const auto &b : bullet) {
        window.draw (b);
    }
}

float Hero::Setvelocity() {
    velocity.y  =0.1f;//risetta la velocità quando tocca o un blocco
}


void Hero::Create_Bullet() {
    b.setRadius (5);
    b.setFillColor (sf::Color::Red);
    b.setPosition (doodle.getPosition ().x+doodle.getSize ().x/2,doodle.getPosition ().y);
}


sf::FloatRect Hero::GetposBullet() {
    sf::FloatRect bulletshape;
    for (auto &i : bullet) {
       bulletshape= i.getGlobalBounds ();
    }
    return bulletshape;
}


void Hero::Notify() {
    for (itro=observer.begin () ;itro!=observer.end ();++itr) {
        (*itro)->Achievments ();
    }
}

void Hero::Attach(Observer *o) {
    observer.push_back (o);
}

void Hero::Detach(Observer *o) {
    observer.emplace_back (o);
}

