//
// Created by francesco on 20/04/18.
//

#include "Block.h"
Block::Block(sf::Vector2i windSize, int bls):windowSize(windSize),blockSize(bls) {
SetBlock ();
}

Block::~Block() {}


void Block::Update() {

}

void Block::SetBlock() {
    for(itr=blocks.begin ();itr<blocks.end ();itr++) {
        Random ();
        block.setSize (sf::Vector2f (50, 10));
        block.setFillColor (sf::Color::Red);
        block.setPosition (item.x*blockSize,item.y*blockSize);
        blocks.insert (itr,block);
    }
}

void Block::Render(sf::RenderWindow &window) {
    for (auto itr=blocks.begin ();itr!=blocks.end ();++itr) {
       window.draw (block);
}
}

sf::Vector2i Block::Random() {

    srand ((unsigned)time(NULL));
    int maxX = (windowSize.x / blockSize) - 2;
    int maxY = (windowSize.y / blockSize) - 2;
    return item = sf::Vector2i(rand () % maxX + 1, rand () % maxY + 1);
}