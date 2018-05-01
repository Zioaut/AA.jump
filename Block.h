//
// Created by francesco on 20/04/18.
//

#ifndef AA_JUMP_BLOCK_H
#define AA_JUMP_BLOCK_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include "Hero.h"
#include "Enemy.h"




class Block {
public:
    Block(sf::Vector2i windSize,int bls,Hero* h= nullptr,Enemy*e= nullptr);
    ~Block();
    void Update();
    void SetBlock();
    void Render(sf::RenderWindow& window);
    sf::Vector2i Random();
    void Collision(Hero & hero,Enemy&enemy);



private:
    bool Random_Create( );
    sf::RectangleShape block;
    std::vector<sf::RectangleShape>blocks;
    std::vector<sf::RectangleShape>::iterator itr;
    sf::Vector2i windowSize;
    int blockSize;
    sf::Vector2i item;
    Hero *hero;
    Enemy*enemy;
    bool iscreate;

};


#endif //AA_JUMP_BLOCK_H
