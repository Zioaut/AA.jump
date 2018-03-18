//
// Created by francesco on 17/03/18.
//

#include "Hero.h"


Hero::Hero(sf::Vector2u WindSize) {
    WindSize = WindowSize;
    gravity = sf::Vector2f (0, 0.7);
    velocity = sf::Vector2f (1, 2);
    costime = 0.25;
    Reset ();
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

    if (sf::Keyboard::isKeyPressed (sf::Keyboard::D)) {
        doodle.move (velocity.x * costime, -velocity.y * costime + 0.5f * gravity.y * costime * costime);

    }


    if (sf::Keyboard::isKeyPressed (sf::Keyboard::A)) {
        doodle.move (-velocity.x * costime, -velocity.y * costime + 0.5f * gravity.y * costime * costime);
    }


}

void Hero::Collision() {
    if (doodle.getPosition ().y <= 400) {
        doodle.setPosition (doodle.getPosition ().x + velocity.x * costime,
                            doodle.getPosition ().y + velocity.y * costime + gravity.y * costime * costime);
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


