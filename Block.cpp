//
// Created by francesco on 20/04/18.
//

#include "Block.h"
Block::Block(sf::Vector2i windSize, int bls,Hero*h,Enemy*e,Maps*m):
        windowSize(windSize),blockSize(bls),hero(h),enemy(e),maps(m) {
    SetBlock ();


}

Block::~Block() {
    blocks.clear ();
}

void Block::Update() {
    Collision (*hero,*enemy);

}
void Block::SetBlock() {
    int minrange=5500;
    for (int j = 0; j <50 ; ++j) {
            Random ();
            block.setSize (sf::Vector2f (40, 10));
            block.setFillColor (sf::Color::Red);
            block.setPosition (random.x * blockSize, random.y + minrange);
            blocks.insert (blocks.begin () + j, block);
            minrange-=100;
    }
}

void Block::Render(sf::RenderWindow &window) {
    for (const auto &block : blocks) {
        window.draw (block);
    }
}

sf::Vector2i Block::Random()  {
    int maxX = (windowSize.x/ blockSize) - 2;
    return random=sf::Vector2i( rand ()%maxX+1,rand ()%100+1);
}//funzione randomica per settare coordinate del blocco



void Block::Collision(Hero &hero,Enemy& enemy) {
    for (auto i=0;i<blocks.size ();++i) {
        if (blocks[i].getGlobalBounds ().intersects (hero.GetBound ())) {
            hero.Setvelocity ();//risetta la velocità di hero
        }

        if(blocks[i].getPosition ().y>hero.GetPosy ()+300){
            blocks.erase (blocks.begin ()+i);
        }

        if (blocks[i].getGlobalBounds ().intersects (enemy.GetBounden1 ())) {
            blocks[i].setPosition (blocks[i].getPosition ().x, enemy.GetPosy_en1 ());
        }
    }
}






