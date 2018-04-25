//
// Created by francesco on 17/03/18.
//

#ifndef AA_JUMP_HERO_H
#define AA_JUMP_HERO_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <vector>



class Hero {
public:
     Hero(float g, float s, sf::Vector2f v,Enemy* e= nullptr);

    ~Hero();
    void Jump();
    void Update();
    void Shoot(Enemy&e);
    void Collision();
    bool GameOver(Enemy&e);
    void Reneder(sf::RenderWindow &window);
    void Create_Sethero();
    void Reset();
    float Setvelocity();
    void Create_Bullet();
    sf::FloatRect GetBound(){return doodle.getGlobalBounds ();}


protected:
    float gravity;
    sf::Vector2f velocity;
    sf::RectangleShape doodle;
    std::vector<sf::CircleShape>bullet;
    sf::CircleShape b;
    float shoot;
    Enemy* enemy;


};


#endif //AA_JUMP_HERO_H
