//
// Created by francesco on 29/03/18.
//

#include "Enemy.h"
Enemy::Enemy(sf::Vector2f ev):e_velocity(ev) {
    SetEnemy ();
}

Enemy::~Enemy() {}


void Enemy::Move() {
       enemy2.move (e_velocity.x,0);

    if(enemy2.getPosition ().x<0){
        e_velocity=-e_velocity;
    }    else if(enemy2.getPosition ().x>400){
        e_velocity=-e_velocity;
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
 itr2=enemy2_container.begin ();
 enemy2_container.insert (itr2,enemy2);
 itr=enemy1_container.begin ();
 enemy1_container.insert (itr,enemy1);
}

void Enemy::Render(sf::RenderWindow &window) {
  for(auto itr2=enemy2_container.begin ();itr2!=enemy2_container.end ();itr2++){
      window.draw (enemy2);
  }
    for (auto itr=enemy1_container.begin ();itr!=enemy1_container.end ();itr++) {
        window.draw (enemy1);
    }
}

void Enemy::Death_En2() {
    for (auto itr2=enemy2_container.begin ();itr2<enemy2_container.end (); ++itr2) {
        enemy2_container.erase (itr2);
    }
}

void Enemy::Death_En1() {
    for (auto itr=enemy1_container.begin ();itr<enemy1_container.end ();++itr) {
        enemy1_container.erase (itr);
    }
}

sf::FloatRect Enemy::GetBound() {
    return enemy1.getGlobalBounds ();
}
sf::FloatRect Enemy::GetBound2() {
    return enemy2.getGlobalBounds ();
}