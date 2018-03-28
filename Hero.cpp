//
// Created by francesco on 17/03/18.
//

#include "Hero.h"


Hero::Hero() {
    gravity=0.00002f;
    velocity = sf::Vector2f (0.1,0.1);
    Reset ();



}


Hero::~Hero() {}

void Hero::Reset() {
    is_catch = false;
    is_death = false;
    Create_Sethero ();


}


void Hero::Create_Sethero() {

    doodle.setPosition (100,400);
    doodle.setSize (sf::Vector2f (30, 60));
    doodle.setFillColor (sf::Color (144, 238, 144));

}


void Hero::CreateBullet() {
    int i=0;
    while (i<3) {
        bullet[i].setRadius (7.5f);
        bullet[i].setPosition (doodle.getSize ().x / 2 - 10 + doodle.getPosition ().x, doodle.getPosition ().y);
        bullet[i].setFillColor (sf::Color::Red);
        i++;
    }
}

void Hero::Update() {
    Shoot ();
    Collision ();
}


void Hero::Shoot() {
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Space)) {
        CreateBullet ();
        MoveBall ();
        }
    //funzione se colpisce nemico;
}


void Hero::Jump() {
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::D) && !sf::Keyboard::isKeyPressed (sf::Keyboard::A)) {
        velocity.y-=gravity;
        doodle.setPosition (doodle.getPosition ().x+velocity.x,doodle.getPosition ().y-velocity.y);

    } else if (sf::Keyboard::isKeyPressed (sf::Keyboard::A) && !sf::Keyboard::isKeyPressed (sf::Keyboard::D)) {


    }

        velocity.y -= gravity;

    doodle.setPosition (doodle.getPosition ().x,doodle.getPosition ().y-velocity.y);

}
void Hero::Collision() {


 if(velocity.y==0){
    doodle.setPosition (doodle.getPosition ().x,doodle.getPosition ().y+velocity.y);
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





bool Hero::GameOver() {
    if (is_death) {
        //devo richiamare reset di Map
    }
    if (doodle.getPosition ().y +doodle.getSize ().y>=900) {
        //richiamo reset di Map

    }
}

void Hero::Reneder(sf::RenderWindow &window) {
    window.draw (doodle);
    for (int i = 0; i < 3; ++i) {
        window.draw (bullet[i]);
    }

}

void Hero::MoveBall() {

    }


float Hero::Setvelocity() {
    velocity.y  =0.1f;
}

