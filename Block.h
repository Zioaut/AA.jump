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
#include "Maps.h"


class Block {
public:
    Block(sf::Vector2i windSize,int bls,Hero* h= nullptr,Enemy*e= nullptr,Maps*m= nullptr);
    ~Block();
    void Update();
    void SetBlock();
    void Render(sf::RenderWindow& window);
    void Collision(Hero & hero,Enemy&enemy);
    void Move();




private:
    sf::Vector2f velocity;
    sf::Vector2i Random();
    sf::RectangleShape block2;
    sf::RectangleShape block;
    std::vector<sf::RectangleShape>blocks;
    std::vector<sf::RectangleShape>blocks2;
    sf::Vector2i windowSize;
    int blockSize;
    sf::Vector2i random;
    Hero *hero;
    Enemy*enemy;
    Maps*maps;
};


#endif //AA_JUMP_BLOCK_H
