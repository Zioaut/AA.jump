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
#include <memory>



class Block {
public:
    Block(sf::Vector2i windSize,int bls,Enemy*e= nullptr,Maps*m= nullptr,Hero*h= nullptr);
    ~Block();
    void Update();
    void SetBlock();
    void Render(sf::RenderWindow& window);
    void Collision();
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
    Hero*hero;
    Enemy*enemy;
    Maps*maps;
    int minrange=15500;
    const int bscale1=100;
    const int bscale2=200;
    const int bscale3=250;
    const int bdistance=300;
    const int mindistance=0;
    const int nrand=10+1;
    const int choose=6;
};


#endif //AA_JUMP_BLOCK_H
