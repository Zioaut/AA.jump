//
// Created by francesco on 17/03/18.
//

#ifndef AA_JUMP_HERO_H
#define AA_JUMP_HERO_H

#include <SFML/Graphics.hpp>

class Hero {
public:
    Hero();

    ~Hero();

    void Jump();

    void Update();

    void Shoot();

    void Collision();

    bool GameOver();

    void CreateBullet();

    void Reneder(sf::RenderWindow &window);

    void Create_Sethero();

    void Reset();

    void MoveBall();

    bool GetDeath(){return is_death;}

    float Setvelocity();






private:

    float gravity;
    sf::Vector2f velocity;
    bool is_catch;
    bool is_death;
    sf::RectangleShape doodle;
    sf::CircleShape bullet[3];
    float x;
    float y;
};


#endif //AA_JUMP_HERO_H
