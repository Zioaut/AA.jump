//
// Created by francesco on 20/04/18.
//

#ifndef AA_JUMP_BLOCK_H
#define AA_JUMP_BLOCK_H


#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
class Block {
public:
    Block(sf::Vector2i windSize,int bls);
    ~Block();
    void Update();
    void SetBlock();
    void Render(sf::RenderWindow& window);
    sf::FloatRect GetBound(){return block.getGlobalBounds ();};
    sf::Vector2i Random();


private:
    sf::RectangleShape block;// Todo prova a mettere block come array e riprova
    std::vector<sf::RectangleShape>blocks;
    std::vector<sf::RectangleShape>::iterator itr;
    sf::Vector2i windowSize;
    int blockSize;
    sf::Vector2i item;
};


#endif //AA_JUMP_BLOCK_H
