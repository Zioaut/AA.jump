//
// Created by francesco on 29/03/18.
//

#ifndef AA_JUMP_ENEMY_H
#define AA_JUMP_ENEMY_H

#include <SFML/Graphics.hpp>



class Enemy {
public:
     explicit Enemy(sf::Vector2f ev);

    ~Enemy();

    void SetEnemy();
    void Update();
    void Move();
    void Death_En2();
    void Death_En1();
    void Render(sf::RenderWindow  &window);
   sf::FloatRect GetBound2(){return enemy2.getGlobalBounds ();}
    sf::FloatRect GetBound(){return enemy1.getGlobalBounds ();}
private:
    sf::RectangleShape enemy1;
    sf::RectangleShape enemy2;
    sf::Vector2f e_velocity;

};


#endif //AA_JUMP_ENEMY_H
