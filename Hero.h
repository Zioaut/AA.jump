//
// Created by francesco on 17/03/18.
//

#ifndef AA_JUMP_HERO_H
#define AA_JUMP_HERO_H

#include <SFML/Graphics.hpp>

#include <vector>
#include "Subject.h"
#include <list>


class Hero : public Subject {
public:

    explicit Hero(float g, float s, sf::Vector2f v, int j, int k, int kg, int p);

    ~Hero();

    void Notify() const override;

    void Attach(Observer *o) override;

    void Detach(Observer *o) override;

    void Jump();

    void Update();

    void Shoot();

    bool Collision();

    bool GameOver(bool death);

    void Reneder(sf::RenderWindow &window);

    void Create_Sethero();

    void Reset();

    float Setvelocity();

    float Getvelocity() { return velocity.y; }

    void Create_Bullet();

    sf::FloatRect GetBound() { return doodle.getGlobalBounds (); }

    float GetPosy() { return doodle.getPosition ().y; }

    float GetPosx() { return doodle.getPosition ().x; }

    sf::FloatRect GetposBullet();

    void Changed() { Notify (); };
    // FUNZIONI CHE SETTANO VARIABILI PER ACHIEVMENTS
    int SetKillYellow();

    int SetJump();

    int SetKillGreen(); 

    int Setpoint(int pt);

    int Setnumbullet();
    
    void SetDeath();
    
    bool GetDeath() { return death; }
    //FUNZIONI CHE SERVONO PER IL TEST..

    sf::Color GetColor() { return doodle.getFillColor (); }
    
    int GetBulletsize() { return static_cast<int>(bullet.size ()); }

    sf::Vector2f SetPositionTest(int index);//MI SETTA POSZIONE DI HERO 

   


protected:
    std::list<Observer *> observer;
    float gravity;
    sf::Vector2f velocity;
    sf::RectangleShape doodle;
    sf::CircleShape b;
    std::vector<sf::CircleShape> bullet;
    float shoot;
    int killYellow;//VARIABILI PER ACHIEVMENTS
    int jump_block;
    int point;
    int killGreen;
    int numbullet;
    bool death = false;
    const int pointzero = 0;//COORDINATE MAPPA
    const int maxsize = 500;
    bool repos = false;//BOOLENANO PER CONTROLLO USCITA DALLA MAPPA


};


#endif //AA_JUMP_HERO_H
