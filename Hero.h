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

    float GetmaxjumpD() { return max_jumpD; };

    float GetmaxjumpL() { return max_jumpL; }
    void Setmaxjump();
    void CreateBlock();


private:
    sf::Vector2u WindowSize;
    sf::Vector2f gravity;
    sf::Vector2f velocity;
    bool is_death;
    float costime;
    bool is_catch;
    sf::RectangleShape doodle;
    sf::CircleShape bullet[4];
    float max_jumpD;
    float max_jumpL;
    sf::RectangleShape land[3];
    bool ritorno=true;
};


#endif //AA_JUMP_HERO_H
