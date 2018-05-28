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
     Enemy(sf::Vector2f ev,sf::Vector2i winds,int en,int en2,StrategyMove*s= nullptr,Hero*h= nullptr);
    ~Enemy();
    void SetEnemy();
    void Update();
    void Move();
    void Death_En2();
    void Death_En1();
    void Death_En3();
    void Death_En4();
    void Render(sf::RenderWindow  &window);
    sf::Vector2i SetRandom();
    sf::Vector2i SetRandom2();
    void Collsion();
    sf::FloatRect GetBounden1();
    float GetPosy_en1();
    void Move3();
    void Explosion(float count);



private:
    sf::Vector2i windowSize;
    sf::RectangleShape enemy1;
    sf::RectangleShape enemy2;
    sf::RectangleShape enemy3;
    sf::RectangleShape enemy4;
    std::vector<sf::RectangleShape>enemy1_container;
    std::vector<sf::RectangleShape>enemy2_container;
    std::vector<sf::RectangleShape>enemy3_container;
    std::vector<sf::RectangleShape>enemy4_container;
    std::vector<sf::RectangleShape>::iterator itr;
    std::vector<sf::RectangleShape>::iterator itr2;
    sf::Vector2f e_velocity;
    int enemysize;
    int enemysize2;
    sf::Vector2i pos;
    sf::Vector2i pos2;
    Hero*hero;
    StrategyMove*strategy;
    int enemyrange=10000;
    int enemyrange2=13000;
    int enemyrange3=12000;
    const int scale=5000;
    const int distance=300;
    int randomina=rand ()%100+1;
};


#endif //AA_JUMP_ENEMY_H
