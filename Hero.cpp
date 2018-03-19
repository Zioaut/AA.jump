//
// Created by francesco on 17/03/18.
//

#include "Hero.h"


Hero::Hero(sf::Vector2u WindSize) {
    WindSize = WindowSize;
    gravity = sf::Vector2f (0, 9.8);
    velocity = sf::Vector2f (10, 20);
    costime = 0.025;
    Reset ();
    Setmaxjump ();

}


Hero::~Hero() {}

void Hero::Reset() {
    is_catch = false;
    is_death = false;
    Create_Sethero ();
}


void Hero::Create_Sethero() {
    doodle.setPosition (400, 500);
    doodle.setSize (sf::Vector2f (20, 30));
    doodle.setFillColor (sf::Color (144, 238, 144));

}


void Hero::CreateBullet() {
    bullet.setRadius (7.5f);
    bullet.setPosition (doodle.getSize ().x / 2 - 10 + doodle.getPosition ().x, doodle.getPosition ().y);
    bullet.setFillColor (sf::Color::Red);
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

    if (sf::Keyboard::isKeyPressed (sf::Keyboard::D)) {
        sf::Keyboard::Right;
        doodle.move (velocity.x * costime, -velocity.y * costime + 0.5f * gravity.y * costime * costime);
        while (max_jumpD < 10000) {
            //doodle.move (velocity.x * costime, -velocity.y * costime + 0.5f * gravity.y * costime * costime);
            max_jumpD += 1;
        }
    }


    if (sf::Keyboard::isKeyPressed (sf::Keyboard::A)) {
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


    if (doodle.getPosition ().y >= 560) {
        doodle.setPosition (doodle.getPosition ().x, 560);
        Setmaxjump ();
        gravity.y = -gravity.y;
    }
    if (doodle.getPosition ().y <= 0) {
        doodle.setPosition (doodle.getPosition ().x, 0);
        Setmaxjump ();
        gravity.y = -gravity.y;
    }

    if (doodle.getPosition ().x >= 770) {
        doodle.setPosition (30, doodle.getPosition ().y);
        Setmaxjump ();
    }
    if (doodle.getPosition ().x <= 30) {
        doodle.setPosition (760, doodle.getPosition ().y);
        Setmaxjump ();
    }


}


bool Hero::GameOver() {
    if (is_death) {
        //devo richiamare reset di Map
    }
    if (doodle.getPosition ().y >= WindowSize.y - 30) {
        //richiamo reset di Map
    }
}

void Hero::Reneder(sf::RenderWindow &window) {
    window.draw (doodle);
    window.draw (bullet);
}

void Hero::MoveBall() {
    bullet.move (velocity.x * costime, -velocity.y * costime + gravity.y * costime * costime);
}


void Hero::Setmaxjump() {
    max_jumpD = 0;
    max_jumpL = 0;
}