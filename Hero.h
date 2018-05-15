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
     Hero(float g, float s, sf::Vector2f v,int j,int k,int kg,int p);
    ~Hero();
    virtual void Notify()const ;
    virtual void Attach(Observer*o);
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
    float Getvelocity(){ return velocity.y;}
    void Create_Bullet();
    sf::FloatRect GetBound(){return doodle.getGlobalBounds ();}
    float GetPosy(){return doodle.getPosition ().y;}
    sf::FloatRect GetposBullet();
    void Changed(){Notify ();};
    void SetKillYellow();
    void SetJump();
    void SetKillGreen();
    void Setpoint(int pt);




protected:
    std::list<Observer*>observer;
    float gravity;
    sf::Vector2f velocity;
    sf::RectangleShape doodle;
    sf::CircleShape b;
    std::vector<sf::CircleShape>bullet;
    std::vector<sf::CircleShape>::iterator itr;
    float shoot;
    int killYellow;
    int jump_block;
    int point;
    int killGreen;
};


#endif //AA_JUMP_HERO_H
