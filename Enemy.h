//
// Created by francesco on 29/03/18.
//

#ifndef AA_JUMP_ENEMY_H
#define AA_JUMP_ENEMY_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Hero.h"
#include "StrategyMove.h"
#include "StrategyDefenseRight.h"
#include "StrategyDefenseLeft.h"
#include "StrategyAttack.h"


class Enemy {
public:
    Enemy(sf::Vector2f ev, sf::Vector2i winds, int en, int en2, StrategyMove *s, Hero &h);

    ~Enemy();

    int SetEnemy();

    void Update();

    void Move();

    void Death_En2();

    void Death_En1(bool test );

    void Death_En3();

    void Render(sf::RenderWindow &window);

    sf::Vector2i SetRandom();

    sf::Vector2i SetRandom2();

    void Collsion();

    sf::FloatRect GetBounden1();

    float GetPosy_en1();

    void Move3();
    
    void EraseEn1(int index){  enemy1_container.erase (enemy1_container.begin ()+index);}

    void EraseEn2(int index){enemy2_container.erase (enemy2_container.begin ()+index);}

    void EraseEn3(int index){enemy3_container.erase (enemy3_container.begin ()+index);}
    
//FUNZIONI CHE SERVONO PER IL TEST..
    int Getposy(){return pos.y;}

    int Getposy2(){return pos2.y;}
    
    int GetSizeEn1(){ return static_cast<int>(enemy1_container.size ());}
    
    int GetSizeEn2(){return static_cast<int>(enemy2_container.size ());}  
    
    int GetSizeEn3(){ return static_cast<int>(enemy3_container.size ());}
    
    
    sf::Vector2f SetposEntest(int index);

    sf::FloatRect TestRectEn1(int index);

    sf::Vector2f SetposEn2test(int index);//SETTANO POSIZIONI E BOUND DI ENEMY 1 E 2

    sf::FloatRect TestRectEn2(int index);





private:
    sf::Vector2i windowSize;
    sf::RectangleShape enemy1;
    sf::RectangleShape enemy2;
    sf::RectangleShape enemy3;
    std::vector<sf::RectangleShape> enemy1_container;
    std::vector<sf::RectangleShape> enemy2_container;
    std::vector<sf::RectangleShape> enemy3_container;
    std::vector<sf::RectangleShape>::iterator itr;
    std::vector<sf::RectangleShape>::iterator itr2;
    sf::Vector2f e_velocity;
    int enemysize;
    int enemysize2;
    sf::Vector2i pos;
    sf::Vector2i pos2;
    Hero &hero;
    StrategyMove *strategy;
    int enemyrange = 10000;//INDICI CHE INDICANO DOVE SETTARE NEMICO 
    int enemyrange2 = 13000;
    const int scale = 5000;//DISTANZA TRA LORO
    const int distance = 300;
    int randomy = rand () % 100 + 1;
    int count = 0;
    const int choose_range=60;//CONSTANTE PER IDENTIFICARE LA ZONA DI SETTAGGIO

};


#endif //AA_JUMP_ENEMY_H
