//
// Created by francesco on 17/03/18.
//

#include "Hero.h"


Hero::Hero(float g, float s, sf::Vector2f v, Enemy *e)
        :gravity(g),shoot(s),velocity(v),enemy(e) {
    Reset ();

    bullet.resize (2);
    }


Hero::~Hero() {

}

void Hero::Reset() {
    Create_Sethero ();
}


void Hero::Create_Sethero() {

    doodle.setPosition (100,400);
    doodle.setSize (sf::Vector2f (30, 60));
    doodle.setFillColor (sf::Color (144, 238, 144));

}




void Hero::Update() {
    Collision ();
    GameOver (enemy);
}


void Hero::Shoot(Enemy*e) {

    if(sf::Keyboard::isKeyPressed (sf::Keyboard::C)) {
        b.setRadius (1);
        b.setFillColor (sf::Color::Red);
        b.setPosition (doodle.getPosition ().x + doodle.getSize ().x / 2, doodle.getPosition ().y);
        bullet.push_back (b);
    }
    for (size_t j=0; j <bullet.size (); ++j) {
        bullet[j].move (0,-shoot);
    }

    for (size_t i = 0; i <bullet.size () ; ++i) {
        if (bullet[i].getGlobalBounds ().intersects (e->GetBound2 ())) {
            enemy->Death_En2 ();
        } else if (bullet[i].getGlobalBounds ().intersects (e->GetBound ())) {
            enemy->Death_En1 ();
        }
    }//funzione se colpisce nemico;
}


void Hero::Jump() {
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::D) && !sf::Keyboard::isKeyPressed (sf::Keyboard::A)) {
        velocity.y-=gravity;
        doodle.setPosition (doodle.getPosition ().x+velocity.x,doodle.getPosition ().y-velocity.y);

    } else if (sf::Keyboard::isKeyPressed (sf::Keyboard::A) && !sf::Keyboard::isKeyPressed (sf::Keyboard::D)) {
        velocity.y-=gravity;
        doodle.setPosition (doodle.getPosition ().x-velocity.x,doodle.getPosition ().y-velocity.y);

    }

        velocity.y -= gravity;

        doodle.setPosition (doodle.getPosition ().x,doodle.getPosition ().y-velocity.y);

}
void Hero::Collision() {

    if(velocity.y==0){
        doodle.setPosition (doodle.getPosition ().x,doodle.getPosition ().y);
        doodle.setPosition (doodle.getPosition ().x,doodle.getPosition ().y+gravity);

}

    if(doodle.getPosition ().y>=500){
        doodle.setPosition (doodle.getPosition ().x,500);
        Setvelocity ();

    }
    if (doodle.getPosition ().x <= 0) {
        doodle.setPosition (400, doodle.getPosition ().y);
    } else if (doodle.getPosition ().x >= 400) {
        doodle.setPosition (0, doodle.getPosition ().y);
    }
 }





bool Hero::GameOver(Enemy*e) {
    if(doodle.getGlobalBounds ().intersects (e->GetBound2 ())
    ||doodle.getGlobalBounds ().intersects (e->GetBound ())){

        doodle.setFillColor (sf::Color::Transparent);
}

    if (doodle.getPosition ().y +doodle.getSize ().y>=600) {
        //richiamo reset di Map

    }
}

void Hero::Reneder(sf::RenderWindow &window) {
    window.draw (doodle);
    for (size_t i= 0; i <bullet.size () ; ++i) {
        window.draw (bullet[i]);
    }
}

float Hero::Setvelocity() {
    velocity.y  =0.1f;
}




