//
// Created by francesco on 20/04/18.
//

#include "Block.h"
Block::Block(sf::Vector2i windSize, int bls):windowSize(windSize),blockSize(bls) {
    SetBlock ();

}

Block::~Block() {
//todo fai un delete di array
}


void Block::Update() {

}
void Block::SetBlock() {
    for (int i = 0; i <5 ; ++i) {
        Random ();
        block.setSize (sf::Vector2f (50, 10));
        block.setFillColor (sf::Color::Red);
        block.setPosition (item.x*blockSize , item.y*blockSize );
        blocks.insert (blocks.begin ()+i,block);
        blockSize=rand ()&5+1;
    }
}

void Block::Render(sf::RenderWindow &window) {
    for (auto i=0;i<blocks.size ();i++){
        window.draw (blocks[i]);//todo prova a disegnare block[i]
    }
}

sf::Vector2i Block::Random() {
    srand ( static_cast<unsigned  int> (time (0)));
    int maxX = (windowSize.x / blockSize) - 2;
    int maxY = (windowSize.y / blockSize) - 2;
    return item = sf::Vector2i(rand () % maxX + 1, rand () % maxY + 1);
}


