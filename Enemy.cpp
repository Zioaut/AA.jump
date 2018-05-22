//
// Created by francesco on 29/03/18.
//

#include "Enemy.h"



Enemy::Enemy(sf::Vector2f ev,sf::Vector2i winds,int en,int en2,Hero*h,StrategyMove*s)
        :e_velocity(ev),windowSize(winds),enemysize(en),enemysize2(en2),hero(h),strategy(s) {
    SetEnemy ();
    bullet.emplace_back (b);


}

Enemy::~Enemy() {
    enemy1_container.clear ();
    enemy2_container.clear ();
    bullet.clear ();
}


void Enemy::Move() {
    for (auto &enemymove : enemy2_container) {
        if(hero->GetPosy ()>enemymove.getPosition ().y<300&&hero->GetPosx()<enemymove.getPosition ().x
           &&hero->GetPosy ()>enemymove.getPosition ().y){
            strategy=new StrategyAtkLeft(0.05,0);
            enemymove.move (strategy->Strategy_move ()) ;
            delete strategy;
        }   else if(hero->GetPosy ()-enemymove.getPosition ().y<300&&hero->GetPosx()>enemymove.getPosition ().x
                 &&hero->GetPosy ()>enemymove.getPosition ().y){
            strategy=new StrategyAtkRight(0.05,0);
            enemymove.move (strategy->Strategy_move ());
            delete  strategy;
        }
    }
}



void Enemy::Update() {
    //servirà successivamente per aggiornare creazione enemy
    Death_En2 (*hero);
    Death_En1 (*hero);
    Collsion (*hero);
}


void Enemy::SetEnemy() {

    for (int i = 0; i <2 ; ++i) {
    SetRandom ();
    enemy1.setFillColor (sf::Color::Green);
    enemy1.setSize (sf::Vector2f(60,20));
    enemy1.setPosition (pos.x*enemysize,pos.y*enemysize);
    itr=enemy1_container.begin ();
    enemy1_container.insert (itr+i,enemy1);
    enemysize=rand ()%8+1;
    }
     int enemyrange=windowSize.y-3000;
    for (int j = 0; j < 5; ++j) {
        SetRandom2 ();
        enemy2.setFillColor (sf::Color::Yellow);
        enemy2.setSize (sf::Vector2f (20, 20));
        enemy2.setPosition (pos2.x * enemysize2, pos2.y+enemyrange);
        itr2 = enemy2_container.begin ();
        enemy2_container.insert (itr2+j, enemy2);
        enemyrange-=400;
    }
}

void Enemy::Render(sf::RenderWindow &window) {
    for (const auto &enemy1 : enemy1_container) {
     window.draw (enemy1);
    }
    for (const auto &enemy2 : enemy2_container) {
        window.draw (enemy2);
    }
    for (int i = 0; i <bullet.size () ; ++i) {
        window.draw (bullet[i]);
    }
}

void Enemy::Death_En2(Hero&h) {
    for (int j = 0; j < enemy2_container.size (); ++j) {
        if (enemy2_container[j].getGlobalBounds ().intersects (h.GetposBullet ())) {
            enemy2_container.erase (enemy2_container.begin () + j);
            h.SetKillYellow ();
        }
        if(enemy2_container[j].getPosition ().y>h.GetPosy ()+300){
            enemy2_container.erase (enemy2_container.begin ()+j);
        }
    }
}
void Enemy::Death_En1(Hero&h) {
    for (int i = 0; i <enemy1_container.size () ; ++i) {
        if(enemy1_container[i].getGlobalBounds ().intersects (h.GetposBullet ())){
            enemy1_container.erase (enemy1_container.begin ()+i);
            h.SetKillGreen ();
        }
        if(enemy1_container[i].getPosition ().y>h.GetPosy ()+300){
            enemy1_container.erase (enemy1_container.begin ()+i);
        }

    }
}


sf::Vector2i Enemy::SetRandom() {
    srand ((unsigned)time (NULL));
    int x=windowSize.x-60;
    int y=windowSize.y-3000;
    int maxX = (x / enemysize) - 2;
    int maxY = (y / enemysize) - 2;
    return pos = sf::Vector2i(rand () % maxX + 1, rand () % maxY + 1);
}


sf::Vector2i Enemy::SetRandom2() {
    int x=windowSize.x-80;
    int maxX = (x / enemysize) - 2;
    return pos2 = sf::Vector2i(rand () % maxX + 1, rand () % 100);
}


void Enemy::Collsion(Hero &h) {
    for (auto &i : enemy1_container) {
            if(i.getGlobalBounds ().intersects (h.GetBound ())){
                h.GameOver ();
            }
    }
    for (auto &j : enemy2_container) {
            if(j.getGlobalBounds ().intersects (h.GetBound ())){
                h.GameOver ();
            }
    }


}
sf::FloatRect Enemy::GetBounden1() {
    sf::FloatRect enemy1shape;
    for (auto &i : enemy1_container) {
     enemy1shape= i.getGlobalBounds ();
    }
    return  enemy1shape;
}

float Enemy::GetPosy_en1() {
    float posEn1;
    for (auto &i : enemy1_container) {
     posEn1= i.getPosition ().y+ i.getSize ().y;
    }
    return posEn1;
}

void Enemy::CreateBullet() {
        b.setRadius (5);
        b.setFillColor (sf::Color::Red);

}




