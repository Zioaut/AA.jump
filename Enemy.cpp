//
// Created by francesco on 29/03/18.
//

#include "Enemy.h"
Enemy::Enemy(sf::Vector2f ev):e_velocity(ev) {
    SetEnemy ();
}

Enemy::~Enemy() {}


void Enemy::Move() {
    enemy1.move (0,e_velocity.y);
    enemy2.move (e_velocity.x,0);

    if(enemy2.getPosition ().x>=370||enemy2.getPosition ().x<=30){
      e_velocity.x=-e_velocity.x;
    }else if(enemy1.getPosition ().y>=570||enemy1.getPosition ().y<=0){
        e_velocity.y=-e_velocity.y;
    }
}


void Enemy::Update() {
    //servirà successivamente per aggiornare creazione enemy
}



void Enemy::SetEnemy() {
 enemy1.setPosition (200,200);
 enemy2.setPosition (110,250);
 enemy1.setSize (sf::Vector2f(20,20));
 enemy2.setSize (sf::Vector2f(20,20));
 enemy1.setFillColor (sf::Color::Yellow);
 enemy2.setFillColor (sf::Color::Yellow);
}

void Enemy::Render(sf::RenderWindow &window) {
    window.draw (enemy1);
    window.draw (enemy2);
}

void Enemy::Death_En2() {
    enemy2.setFillColor (sf::Color::Transparent);
}

void Enemy::Death_En1() {
    enemy1.setFillColor (sf::Color::Transparent);
}

