//
// Created by francesco on 20/04/18.
//

#include "Block.h"
Block::Block(sf::Vector2i windSize, int bls,Hero*h,Enemy*e,Maps*m):
        windowSize(windSize),blockSize(bls),hero(h),enemy(e),maps(m) {
    SetBlock ();
    velocity=sf::Vector2f(0.06,0);


}

Block::~Block() {
    blocks.clear ();
    blocks2.clear ();
}

void Block::Update() {
    Collision (*hero,*enemy);

}
void Block::SetBlock() {
    int minrange=5500;
    int minrange2=2350;
    block.setSize (sf::Vector2f (40, 10));
    block.setFillColor (sf::Color::Red);
    block2.setFillColor (sf::Color::Blue);
    block2.setSize (sf::Vector2f(50,10));
    for (int j = 0; j <30 ; ++j) {
            Random ();
            block.setPosition (random.x * blockSize, random.y + minrange);
            blocks.insert (blocks.begin () + j, block);
            minrange-=100;
    }if(minrange<=2500){
        for (int i = 0; i <5 ; ++i) {
        Random ();
        block.setPosition (random.x*blockSize,random.y+minrange);
        blocks.insert (blocks.begin ()+i,block);
        minrange-=300;
        }
    }
    for (int k = 0; k <5 ; ++k) {
        Random ();
        block2.setPosition (random.x*blockSize,random.y+minrange2);
        blocks2.insert (blocks2.begin ()+k,block2);
        minrange2-=300;
    }


}

void Block::Render(sf::RenderWindow &window) {
    for (const auto &block : blocks) {
        window.draw (block);
    }
    for (const auto &i : blocks2) {
        window.draw (i);
    }
}

sf::Vector2i Block::Random()  {
    int maxX = (windowSize.x/ blockSize) - 2;
    return random=sf::Vector2i( rand ()%maxX+1,rand ()%100+1);
}//funzione randomica per settare coordinate del blocco



void Block::Collision(Hero &hero,Enemy& enemy) {
    for (auto i=0;i<blocks.size ();++i) {
        if (blocks[i].getGlobalBounds ().intersects (hero.GetBound ())&&hero.Getvelocity ()<=0) {
            hero.Setvelocity ();
            hero.SetJump ();

            //risetta la velocità di hero
        }
        if(blocks[i].getPosition ().y>hero.GetPosy ()+300){
            blocks.erase (blocks.begin ()+i);
        }
        if (blocks[i].getGlobalBounds ().intersects (enemy.GetBounden1 ())) {
            blocks[i].setPosition (blocks[i].getPosition ().x, enemy.GetPosy_en1 ());
        }
    }
    for (auto j = 0; j <blocks2.size () ; ++j) {
        if(blocks2[j].getGlobalBounds ().intersects (hero.GetBound ())&&hero.Getvelocity ()<=0){
            hero.Setvelocity ();
            hero.SetJump ();
        }
        if(blocks2[j].getPosition ().y>hero.GetPosy ()+300){
            blocks2.erase (blocks2.begin ()+j);
        }

    }
}

void Block::Move() {
    for (auto i = 0; i <blocks2.size () ; ++i) {
        blocks2[i].move (velocity.x,velocity.y);
        if(blocks2[i].getPosition ().x<0){
            blocks2[i].setPosition (500,blocks2[i].getPosition ().y);
        }else if(blocks2[i].getPosition ().x>500){
            blocks2[i].setPosition (40,blocks2[i].getPosition ().y);
        }
    }
}




