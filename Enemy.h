//
// Created by francesco on 29/03/18.
//

#ifndef AA_JUMP_ENEMY_H
#define AA_JUMP_ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include "Hero.h"
#include "StrategyMove.h"
#include "StrategyDefense.h"
#include "StrategyAtkLeft.h"
#include "StrategyAtkRight.h"


class Enemy {
public:
     Enemy(sf::Vector2f ev,sf::Vector2i winds,int en,int en2,Hero*h= nullptr,StrategyMove*s= nullptr);
    ~Enemy();
    void SetEnemy();
    void Update();
    void Move();
    void Death_En2(Hero&h);
    void Death_En1(Hero&h);
    void Render(sf::RenderWindow  &window);
    sf::Vector2i SetRandom();
    sf::Vector2i SetRandom2();
    void Collsion(Hero& h);
    sf::FloatRect GetBounden1();
    float GetPosy_en1();
    void CreateBullet();




private:
    sf::Vector2i windowSize;
    sf::RectangleShape enemy1;
    sf::RectangleShape enemy2;
    std::vector<sf::RectangleShape>enemy1_container;
    std::vector<sf::RectangleShape>enemy2_container;
    std::vector<sf::RectangleShape>::iterator itr;
    std::vector<sf::RectangleShape>::iterator itr2;
    std::vector<sf::CircleShape>::iterator itr3;
    sf::CircleShape b;
    std::vector<sf::CircleShape>bullet;
    sf::Vector2f e_velocity;
    int enemysize;
    int enemysize2;
    sf::Vector2i pos;
    sf::Vector2i pos2;
    Hero*hero;
    StrategyMove*strategy;
};


#endif //AA_JUMP_ENEMY_H
