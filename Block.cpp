//
// Created by francesco on 20/04/18.
//

#include "Block.h"
Block::Block(sf::Vector2i windSize, int bls,Hero*h):windowSize(windSize),blockSize(bls),hero(h) {
    SetBlock ();

}

Block::~Block() {

}


void Block::Update() {
    Collision (*hero);
}
void Block::SetBlock() {
    for (int i = 0; i <12 ; ++i) {
        Random ();
        block.setSize (sf::Vector2f (40, 10));
        block.setFillColor (sf::Color::Red);
        block.setPosition (item.x*blockSize , item.y*blockSize );
        blocks.insert (blocks.begin ()+i,block);
        blockSize=rand ()%10+1;
    }
}

void Block::Render(sf::RenderWindow &window) {
    for (auto i=0;i<blocks.size ();i++){
        window.draw (blocks[i]);
    }
}

sf::Vector2i Block::Random() {
   int  x=windowSize.x-50;
    int y=windowSize.y-100;
    int maxX = (x / blockSize) - 2;
    int maxY = (y / blockSize) - 2;
    return item = sf::Vector2i(rand () % maxX + 1, rand () % maxY + 1);
}



void Block::Collision(Hero &hero) {
    for (auto  i = 0; i <blocks.size () ; ++i) {
        if(blocks[i].getGlobalBounds ().intersects (hero.GetBound ())){
            hero.Setvelocity ();
    }
     if(blocks[i].getPosition ().y>=540||blocks[i].getPosition ().y<50){
          { itr=blocks.begin ()+i;blocks.erase (itr); }
    }
 }
}