//
// Created by francesco on 17/03/18.
//

#include "Hero.h"


Hero::Hero() {
    gravity = sf::Vector2f (0, 9.8);
    velocity = sf::Vector2f (30,90);
    costime=0.0005f;
    Reset ();
    Setmaxjump ();
}


Hero::~Hero() {}

void Hero::Reset() {
    is_catch = false;
    is_death = false;
    Create_Sethero ();
    CreateBlock ();


}


void Hero::Create_Sethero() {
    doodle.setPosition (150, 700);
    doodle.setSize (sf::Vector2f (20, 30));
    doodle.setFillColor (sf::Color (144, 238, 144));

}


void Hero::CreateBullet() {
    for (int i = 0; i < 4; ++i) {
        bullet[i].setRadius (7.5f);
        bullet[i].setPosition (doodle.getSize ().x / 2 - 10 + doodle.getPosition ().x, doodle.getPosition ().y);
        bullet[i].setFillColor (sf::Color::Red);
    }
}

void Hero::Update() {
    Jump ();
    Shoot ();
    Collision ();
}


void Hero::Shoot() {
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::Space)) {
        CreateBullet ();

        }
    //funzione se colpisce nemico;
}


void Hero::Jump() {
    if (GetmaxjumpD () == 0) {
        doodle.move (0, +0.5f * gravity.y * costime);
    }

    if (sf::Keyboard::isKeyPressed (sf::Keyboard::D)&&!sf::Keyboard::isKeyPressed (sf::Keyboard::A)) {
        sf::Keyboard::Right;
        doodle.move (velocity.x * costime, -velocity.y * costime + 0.5f * gravity.y * costime * costime);
        while (max_jumpD < 10000) {
            //doodle.move (velocity.x * costime, -velocity.y * costime + 0.5f * gravity.y * costime * costime);
            max_jumpD += 1;
        }
    }


    if (sf::Keyboard::isKeyPressed (sf::Keyboard::A)&&!sf::Keyboard::isKeyPressed (sf::Keyboard::D)) {
        sf::Keyboard::Left;
        doodle.move (-velocity.x * costime, -velocity.y * costime + 0.5f * gravity.y * costime * costime);
        while (max_jumpL < 10000) {
            max_jumpL += 1;
        }
    }


}

void Hero::Collision() {
    if (max_jumpD >= 10000) {
        doodle.move (velocity.x * costime, +velocity.y * costime + 0.5f * gravity.y * costime * costime);
    }
    if (max_jumpL >= 10000) {
        doodle.move (-velocity.x * costime, +velocity.y * costime + 0.5f * gravity.y * costime * costime);
    }
            for (int i = 0; i <4 ; ++i) {
                if (doodle.getGlobalBounds ().intersects (land[i].getGlobalBounds ())) {
                    doodle.setPosition (doodle.getPosition ().x, land[i].getPosition ().y-doodle.getSize ().y);
                    Setmaxjump ();
                    gravity.y = -gravity.y;
                }

            if(doodle.getPosition ().y<=land[i].getPosition ().y-50&&!sf::Keyboard::isKeyPressed (sf::Keyboard::D)
               &&!sf::Keyboard::isKeyPressed (sf::Keyboard::A)&&ritorno) {
                doodle.setPosition (doodle.getPosition ().x, land[i].getPosition ().y - 50);
                gravity.y = -gravity.y;

            } else
                if(doodle.getPosition ().y<=land[i].getPosition ().y-50){
                    ritorno=false;
                    i=i+1;
                }
            }
    if (doodle.getPosition ().x <= 0) {
        doodle.setPosition (400, doodle.getPosition ().y);
        Setmaxjump ();
    } else if (doodle.getPosition ().x >= 400) {
        doodle.setPosition (0, doodle.getPosition ().y);
        Setmaxjump ();
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
    for (int i = 0; i < 4; ++i) {
        window.draw (bullet[i]);
    }
    for (int j = 0; j <3 ; ++j) {
        land[j].setFillColor (sf::Color::Red);
        window.draw (land[j]);
    }
}

void Hero::MoveBall() {
    for (int i = 0; i < 4; ++i) {


        bullet[i].move (velocity.x * costime, -velocity.y * costime + gravity.y * costime * costime);
    }
}

void Hero::Setmaxjump() {
    max_jumpD = 0;
    max_jumpL = 0;
}

void Hero::CreateBlock() {
    land[0].setPosition (100,700);
    land[1].setPosition (100,530);
    land[2].setPosition (250,530);
    for (int i = 0; i <3 ; ++i) {
        land[i].setSize (sf::Vector2f(70,10));
    }


}