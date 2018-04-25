//
// Created by francesco on 29/03/18.
//

#ifndef AA_JUMP_ENEMY_H
#define AA_JUMP_ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>

class Enemy {
public:
    explicit Enemy(sf::Vector2f ev,sf::Vector2i winds,int en,int en2);
    ~Enemy();
    void SetEnemy();
    void Update();
    void Move();
    void Death_En2();
    void Death_En1();
    void Render(sf::RenderWindow  &window);
    sf::FloatRect GetBound2();
    sf::FloatRect GetBound();
    sf::Vector2i SetRandom();
    sf::Vector2i SetRandom2();


private:
    sf::Vector2i windowSize;
    sf::RectangleShape enemy1;
    sf::RectangleShape enemy2;
    std::vector<sf::RectangleShape>enemy1_container;
    std::vector<sf::RectangleShape>enemy2_container;
    std::vector<sf::RectangleShape>::iterator itr;
    std::vector<sf::RectangleShape>::iterator itr2;
    sf::Vector2f e_velocity;
    int enemysize;
    int enemysize2;
    sf::Vector2i pos;
    sf::Vector2i pos2;

};


#endif //AA_JUMP_ENEMY_H
