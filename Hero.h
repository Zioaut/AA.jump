//
// Created by francesco on 17/03/18.
//

#ifndef AA_JUMP_HERO_H
#define AA_JUMP_HERO_H

#include <SFML/Graphics.hpp>

#include <vector>
#include "Subject.h"
#include <list>


class Hero: public Subject {
public:
     Hero(float g, float s, sf::Vector2f v);
    ~Hero();
    virtual void Notify()override ;
    virtual void Attach(Observer*o)override ;
    virtual void Detach(Observer*o)override ;
    void Jump();
    void Update();
    void Shoot();
    void Collision();
    bool GameOver();
    void Reneder(sf::RenderWindow &window);
    void Create_Sethero();
    void Reset();
    float Setvelocity();
    void Create_Bullet();
    sf::FloatRect GetBound(){return doodle.getGlobalBounds ();}
    float GetPosy(){return doodle.getPosition ().y;}
    sf::FloatRect GetposBullet();


protected:
    std::vector<Observer*>observer;
    std::vector<Observer*>::iterator itro;
    float gravity;
    sf::Vector2f velocity;
    sf::RectangleShape doodle;
    sf::CircleShape b;
    std::vector<sf::CircleShape>bullet;
    std::vector<sf::CircleShape>::iterator itr;
    float shoot;

};


#endif //AA_JUMP_HERO_H
