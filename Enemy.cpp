//
// Created by francesco on 29/03/18.
//

#include "Enemy.h"
Enemy::Enemy(sf::Vector2f ev,sf::Vector2i winds,int en,int en2)
        :e_velocity(ev),windowSize(winds),enemysize(en),enemysize2(en2) {
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
 SetRandom ();
 SetRandom2 ();
 enemy1.setPosition (pos.x*enemysize,pos.y*enemysize);
 enemy2.setPosition (pos2.x*enemysize2,pos2.y*enemysize2);
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
        enemy2_container.erase (itr2); }
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

sf::Vector2i Enemy::SetRandom() {
    int y=windowSize.y/2;
    srand ((unsigned)time ((NULL)));
    int maxX = (windowSize.x / enemysize) - 2;
    int maxY = (y / enemysize) - 2;
    return pos = sf::Vector2i(rand () % maxX + 1, rand () % maxY + 1);
}


sf::Vector2i Enemy::SetRandom2() {
    int y=windowSize.y/2;
    srand ((unsigned)time ((NULL)));
    int maxX = (windowSize.x / enemysize) - 2;
    int maxY = (y / enemysize) - 2;
    return pos2 = sf::Vector2i(rand () % maxX + 1, rand () % maxY + 1);
}
