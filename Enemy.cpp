//
// Created by francesco on 29/03/18.
//

#include <iostream>
#include "Enemy.h"


Enemy::Enemy(sf::Vector2f ev, sf::Vector2i winds, int en, int en2, StrategyMove *s, Hero &h)
        : e_velocity (ev), windowSize (winds), enemysize (en), enemysize2 (en2), strategy (s), hero (h) {
    SetEnemy ();
    strategy = nullptr;

}

Enemy::~Enemy() {
    enemy1_container.clear ();
    enemy2_container.clear ();
    enemy3_container.clear ();


}


void Enemy::Move() {//MOVIMENTO NEMICO ATTRAVERSO STRATEGY
    for (auto &e : enemy2_container) {
        if (hero.GetPosy () - e.getPosition ().y < distance && hero.GetPosx () < e.getPosition ().x
            && hero.GetPosy () > e.getPosition ().y) {
            strategy = new StrategyDefenseRight (0.1, 0, false, 0);
            e.move (strategy->Strategy_move ());
            delete strategy;
        }
        if (hero.GetPosy () - e.getPosition ().y < distance && hero.GetPosx () > e.getPosition ().x
            && hero.GetPosy () > e.getPosition ().y) {
            strategy = new StrategyDefenseLeft (0.1, 0, false, 0);
            e.move (strategy->Strategy_move ());
            delete strategy;
        }
        if (hero.GetPosy () - e.getPosition ().y < distance && hero.GetPosx () == e.getPosition ().x
            && hero.GetPosy () > e.getPosition ().y) {
            strategy = new StrategyAttack (0.01, 0.05, 0);
            e.move (strategy->Strategy_move ());
            delete strategy;
        }
    }

}


void Enemy::Update() {
    //servirà successivamente per aggiornare creazione enemy
    Death_En2 ();
    Death_En1 (false);
    Death_En3 ();
    Collsion ();
}


int Enemy::SetEnemy() {//SETTAGGIO NEMICI
    if (enemyrange > 0) {
        for (int i = 0; i < 2; ++i) {
            SetRandom ();
            enemy1.setFillColor (sf::Color::Green);
            enemy1.setSize (sf::Vector2f (200, 50));
            enemy1.setPosition (pos.x * enemysize, pos.y + enemyrange);
            itr = enemy1_container.begin ();
            enemy1_container.insert (itr + i, enemy1);
            enemyrange -= scale;
            enemysize = rand () % 8 + 1;//VARIABILE CHE VARIA IL POSIZIONAMENTO DEL NEMICO LUNGO X
            count += 1;//CONTATORE PER TEST

        }
    }

    for (int j = 0; j < 5; ++j) {
        if (enemyrange2 > 0) {
            SetRandom2 ();
            enemy2.setFillColor (sf::Color::Yellow);
            enemy2.setSize (sf::Vector2f (20, 20));
            enemy2.setPosition (windowSize.x - pos2.x, pos2.y + enemyrange2);
            itr2 = enemy2_container.begin ();
            enemy2_container.insert (itr2 + j, enemy2);
            enemyrange2 -= scale;
            count += 1;
        }
    }

    return count;
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
}

void Enemy::Death_En2() {
    for (int j = 0; j < enemy2_container.size (); ++j) {
        if (enemy2_container[j].getGlobalBounds ().intersects (hero.GetposBullet ())) {
            EraseEn2 (j);//ERASE SE ENEMY COLPITO DA PROIETTILE
            hero.SetKillYellow ();
        }
        if (enemy2_container[j].getPosition ().y > hero.GetPosy () + distance) {
            EraseEn2 (j);//ERASE SE SUPERA IL RANGE
        }
    }
}

void Enemy::Death_En1(bool test) {
    for (int i = 0; i < enemy1_container.size (); ++i) {
        if (enemy1_container[i].getGlobalBounds ().intersects (hero.GetposBullet ()) || test) {

            float k = 0;
            for (int j = 0; j < 2; ++j) {//mi crea due enemy4 quando muore enemy2
                enemy3.setSize (sf::Vector2f (20, 20));
                enemy3.setFillColor (sf::Color::Green);
                enemy3.setPosition (enemy1_container[i].getPosition ().x + k, enemy1_container[i].getPosition ().y);
                enemy3_container.insert (enemy3_container.begin () + j, enemy3);
                k = enemy1_container[i].getSize ().x-choose_range;
            }
            Move3 ();
            EraseEn1 (i);
            hero.SetKillGreen ();
        }

        if (enemy1_container[i].getPosition ().y > hero.GetPosy () + distance) {
            EraseEn1 (i);
        }

    }


}


sf::Vector2i Enemy::SetRandom() {
    srand ((unsigned) time (NULL));
    int x = windowSize.x - choose_range;
    int maxX = (x / enemysize) - 2;
    return pos = sf::Vector2i (rand () % maxX + 1, randomy);
}


sf::Vector2i Enemy::SetRandom2() {
    return pos2 = sf::Vector2i (rand () % distance, randomy);
}


void Enemy::Collsion() {//FUNZIONE CHE FA MORIRE PERSONAGGIO SE INTERSECT CON ENEMY
    for (auto &i : enemy1_container) {
        if (i.getGlobalBounds ().intersects (hero.GetBound ())) {
            hero.GameOver (true);
        }
    }
    for (auto &j : enemy2_container) {
        if (j.getGlobalBounds ().intersects (hero.GetBound ())) {
            hero.GameOver (true);
        }
    }
    for (auto &k : enemy3_container) {
        if (k.getGlobalBounds ().intersects (hero.GetBound ())) {
            hero.GameOver (true);
        }
    }


}

sf::FloatRect Enemy::GetBounden1() {//MI RITORNA IL RECT PER CONTROLLO INTERSECT CON BLOCK
    sf::FloatRect enemy1shape;
    for (auto &i : enemy1_container) {
        enemy1shape = i.getGlobalBounds ();
    }
    return enemy1shape;
}

float Enemy::GetPosy_en1() {//MI RITORNA POS ENEMY1
    float posEn1;
    for (auto &i : enemy1_container) {
        posEn1 = i.getPosition ().y + i.getSize ().y;
    }
    return posEn1;
}

void Enemy::Move3() {//COME SI MUOVE ENEMY3
    for (int j = 0; j < enemy3_container.size (); ++j) {
        if (j == 0) {
            if (hero.GetPosy () - enemy3_container[j].getPosition ().y < distance
                && hero.GetPosx () <= enemy3_container[j].getPosition ().x
                && hero.GetPosy () > enemy3_container[j].getPosition ().y) {
                strategy = new StrategyDefenseRight (0.1, 0, false, 0);
                enemy3_container[j].move (strategy->Strategy_move ());
                delete strategy;
            }
            if (hero.GetPosy () - enemy3_container[j].getPosition ().y < distance
                && hero.GetPosx () >= enemy3_container[j].getPosition ().x
                && hero.GetPosy () > enemy3_container[j].getPosition ().y) {
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


void Enemy::Death_En3() {
    for (int i = 0; i < enemy3_container.size (); ++i) {
        if (enemy3_container[0].getGlobalBounds ().intersects (hero.GetposBullet ())) {
            EraseEn3 (i);
        }
        if (enemy3_container[i].getPosition ().y > hero.GetPosy () + distance) {
            EraseEn3 (i);
        }
    }

}

sf::Vector2f Enemy::SetposEntest(int index) {

    enemy1_container[index].setPosition (windowSize.x / 2, windowSize.y / 2);
    return {enemy1_container[index].getPosition ().x, enemy1_container[index].getPosition ().y};
}

sf::FloatRect Enemy::TestRectEn1(int index) {
    return enemy1_container[index].getGlobalBounds ();
}

sf::Vector2f Enemy::SetposEn2test(int index) {
    enemy2_container[index].setPosition (rand () % distance + 1, hero.GetPosy () - distance);
    return {enemy2_container[index].getPosition ().x, enemy2_container[index].getPosition ().y};
}

sf::FloatRect Enemy::TestRectEn2(int index) {
    return enemy2_container[index].getGlobalBounds ();
}






