//
// Created by francesco on 29/03/18.
//

#include <iostream>
#include "Enemy.h"


Enemy::Enemy(sf::Vector2f ev, sf::Vector2i winds, int en, int en2, StrategyMove *s,Hero*h)
        : e_velocity (ev), windowSize (winds), enemysize (en), enemysize2 (en2), strategy (s),hero(h) {
    SetEnemy ();

}

Enemy::~Enemy() {
    enemy1_container.clear ();
    enemy2_container.clear ();
    enemy3_container.clear ();
    enemy4_container.clear ();


}


void Enemy::Move() {
    for (auto &e : enemy2_container) {
        if (hero->GetPosy () - e.getPosition ().y < distance && hero->GetPosx () < e.getPosition ().x
            && hero->GetPosy () > e.getPosition ().y) {
            strategy = new StrategyDefenseRight (0.1, 0, false, 0);
            e.move (strategy->Strategy_move ());
            delete strategy;
        }
        if (hero->GetPosy () - e.getPosition ().y < distance && hero->GetPosx () > e.getPosition ().x
            && hero->GetPosy () > e.getPosition ().y) {
            strategy = new StrategyDefenseLeft (0.1, 0, false, 0);
            e.move (strategy->Strategy_move ());
            delete strategy;
        }
        if (hero->GetPosy () - e.getPosition ().y < distance && hero->GetPosx () == e.getPosition ().x
            && hero->GetPosy () > e.getPosition ().y) {
            strategy = new StrategyAttack (0.01, 0.05, 0);
            e.move (strategy->Strategy_move ());
            delete strategy;
        }
    }

}


void Enemy::Update() {
    //servirà successivamente per aggiornare creazione enemy
    Death_En2 ();
    Death_En1 ();
    Death_En3 ();
    Death_En4 ();
    Collsion ();
    Explosion (0);
}


void Enemy::SetEnemy() {

    for (int i = 0; i < 2; ++i) {
        SetRandom ();
        enemy1.setFillColor (sf::Color::Green);
        enemy1.setSize (sf::Vector2f (60, 20));
        enemy1.setPosition (pos.x * enemysize, pos.y + enemyrange);
        itr = enemy1_container.begin ();
        enemy1_container.insert (itr + i, enemy1);
        enemyrange-=scale;
        enemysize = rand () % 8 + 1;
    }

    for (int j = 0; j < 5; ++j) {
        SetRandom2 ();
        enemy2.setFillColor (sf::Color::Yellow);
        enemy2.setSize (sf::Vector2f (20, 20));
        enemy2.setPosition (windowSize.x - pos2.x, pos2.y + enemyrange2);
        itr2 = enemy2_container.begin ();
        enemy2_container.insert (itr2 + j, enemy2);
        enemyrange2-=scale;
    }

    for (int k = 0; k < 2; ++k) {
        SetRandom ();
        enemy4.setFillColor (sf::Color::White);
        enemy4.setSize (sf::Vector2f (10, 10));
        enemy4.setPosition (pos.x*enemysize2, enemyrange3);
        enemy4_container.insert (enemy4_container.begin () + k, enemy4);
        enemyrange3 -=scale;
    }
}

void Enemy::Render(sf::RenderWindow &window) {
    for (const auto &enemy1 : enemy1_container) {
        window.draw (enemy1);
    }
    for (const auto &enemy2 : enemy2_container) {
        window.draw (enemy2);
    }
    for (const auto &i : enemy3_container) {
        window.draw (i);
    }
    for (const auto &j : enemy4_container) {
        window.draw (j);
    }
}

void Enemy::Death_En2() {
    for (int j = 0; j < enemy2_container.size (); ++j) {
        if (enemy2_container[j].getGlobalBounds ().intersects (hero->GetposBullet ())) {
            enemy2_container.erase (enemy2_container.begin () + j);
            hero->SetKillYellow ();
        }
        if (enemy2_container[j].getPosition ().y > hero->GetPosy () + distance) {
            enemy2_container.erase (enemy2_container.begin () + j);
        }
    }
}

void Enemy::Death_En1() {
    for (int i = 0; i < enemy1_container.size (); ++i) {
        if (enemy1_container[i].getGlobalBounds ().intersects (hero->GetposBullet ())) {
            float k = 0;
            for (int j = 0; j < 2; ++j) {//mi crea due enemy4 quando muore enemy2
                enemy3.setSize (sf::Vector2f (20, 20));
                enemy3.setFillColor (sf::Color::Green);
                enemy3.setPosition (enemy1_container[i].getPosition ().x + k, enemy1_container[i].getPosition ().y);
                enemy3_container.insert (enemy3_container.begin () + j, enemy3);
                k = enemy1_container[i].getSize ().x / 2;
            }
            Move3 ();
            enemy1_container.erase (enemy1_container.begin () + i);
            hero->SetKillGreen ();
        }

    }
}


sf::Vector2i Enemy::SetRandom() {
    srand ((unsigned) time (NULL));
    int x = windowSize.x - 60;
    int maxX = (x / enemysize) - 2;
    return pos = sf::Vector2i (rand () % maxX + 1, randomina);
}


sf::Vector2i Enemy::SetRandom2() {
    return pos2 = sf::Vector2i (rand () % distance, randomina);
}


void Enemy::Collsion() {
    for (auto &i : enemy1_container) {
        if (i.getGlobalBounds ().intersects (hero->GetBound ())) {
            hero->GameOver ();
        }
    }
    for (auto &j : enemy2_container) {
        if (j.getGlobalBounds ().intersects (hero->GetBound ())) {
            hero->GameOver ();
        }
    }
    for (auto &k : enemy3_container) {
        if (k.getGlobalBounds ().intersects (hero->GetBound ())) {
            hero->GameOver ();
        }
    }
    for (int l = 0; l < enemy4_container.size (); ++l) {
        if (enemy4_container[l].getGlobalBounds ().intersects (hero->GetBound ())) {
            hero->GameOver ();
        }
    }


}

sf::FloatRect Enemy::GetBounden1() {
    sf::FloatRect enemy1shape;
    for (auto &i : enemy1_container) {
        enemy1shape = i.getGlobalBounds ();
    }
    return enemy1shape;
}

float Enemy::GetPosy_en1() {
    float posEn1;
    for (auto &i : enemy1_container) {
        posEn1 = i.getPosition ().y + i.getSize ().y;
    }
    return posEn1;
}

void Enemy::Move3() {
    for (int j = 0; j < enemy3_container.size (); ++j) {
        if (j == 0) {
            if (hero->GetPosy () - enemy3_container[j].getPosition ().y < distance
                && hero->GetPosx () <= enemy3_container[j].getPosition ().x
                && hero->GetPosy () > enemy3_container[j].getPosition ().y) {
                strategy = new StrategyDefenseRight (0.1, 0, false, 0);
                enemy3_container[j].move (strategy->Strategy_move ());
                delete strategy;
            }
            if (hero->GetPosy () - enemy3_container[j].getPosition ().y < distance
                && hero->GetPosx () >= enemy3_container[j].getPosition ().x
                && hero->GetPosy () > enemy3_container[j].getPosition ().y) {
                strategy = new StrategyDefenseLeft (0.1, 0, false, 0);
                enemy3_container[j].move (strategy->Strategy_move ());
                delete strategy;
            }
        } else if (j == 1) {
            strategy = new StrategyAttack (0.01, 0.5, 0);
            enemy3_container[j].move (strategy->Strategy_move ());
            delete strategy;
        }
    }
}

void Enemy::Explosion(float count) {
    for (auto &i : enemy4_container) {
        count += 0.0005f;
        if (hero->GetPosy () - i.getPosition ().y < 100 && 30 < count < 50) {
            i.setFillColor (sf::Color::Red);
            i.setSize (sf::Vector2f (30, 30));
        } else if (count > 50) {
            i.setSize (sf::Vector2f (200, 200));
        }
    }

}

void Enemy::Death_En4() {
    for (int i = 0; i < enemy4_container.size (); ++i) {

        if (enemy4_container[i].getPosition ().y > hero->GetPosy () + distance) {
            enemy4_container.erase (enemy4_container.begin () + i);
        }
    }
}

void Enemy::Death_En3() {
    for (int i = 0; i < enemy3_container.size (); ++i) {
        if (enemy3_container[0].getGlobalBounds ().intersects (hero->GetposBullet ())) {
            enemy3_container.erase (enemy3_container.begin ());
        }
        if (enemy3_container[i].getPosition ().y > hero->GetPosy () + distance) {
            enemy3_container.erase (enemy3_container.begin () + i);
        }
    }

}



