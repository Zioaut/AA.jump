//
// Created by francesco on 20/04/18.
//

#include "Block.h"
Block::Block(sf::Vector2i windSize, int bls,Hero*h,Enemy*e):
        windowSize(windSize),blockSize(bls),hero(h),enemy(e) {
    SetBlock ();


}

Block::~Block() {
    blocks.clear ();
}

void Block::Update() {
    Collision (*hero,*enemy);

}
void Block::SetBlock() {
    Random_Create ();
    if(iscreate){

    for (int i = 0; i <20 ; ++i) {
        Random ();
        block.setSize (sf::Vector2f (40, 10));
        block.setFillColor (sf::Color::Red);
        block.setPosition (item.x*blockSize , item.y*blockSize );
        blocks.insert (blocks.begin ()+i,block);
        blockSize=rand ()%7+1;
        //setta dei blocchi (provvisorio)
    }
    }else
        for (int j = 0; j <8 ; ++j) {
         Random ();
            block.setSize (sf::Vector2f (40, 10));
            block.setFillColor (sf::Color::Red);
            block.setPosition (item.x*blockSize , item.y*blockSize );
            blocks.insert (blocks.begin ()+j,block);
            blockSize=rand ()%7+1;
        }
}

void Block::Render(sf::RenderWindow &window) {
    for (const auto &block : blocks) {
        window.draw (block);
    }
}

sf::Vector2i Block::Random() {
    int maxX = (windowSize.x/ blockSize) - 2;
    int maxY = (windowSize.y / blockSize) - 2;
    return item = sf::Vector2i(rand () % maxX + 1, rand () % maxY + 1);
}//funzione randomica per settare coordinate del blocco



void Block::Collision(Hero &hero,Enemy& enemy) {
    for (auto  i = 0; i <blocks.size () ; ++i) {
        if(blocks[i].getGlobalBounds ().intersects (hero.GetBound ())){
            hero.Setvelocity ();//risetta la velocità di hero

    }

     if(blocks[i].getPosition ().y>=1240||blocks[i].getPosition ().y<50){
          { itr=blocks.begin ()+i;blocks.erase (itr); }
    }

     if(blocks[i].getGlobalBounds ().intersects (enemy.GetBounden1 ())){
         blocks[i].setPosition (blocks[i].getPosition ().x,enemy.GetPosy_en1 ());
     }
 }

}

bool Block::Random_Create() {
    int random=rand ();
    iscreate=false;
    srand ((unsigned)time(NULL));
    if((random%2)==1){
        iscreate= true;
    } else iscreate=false;
    return  iscreate;
}