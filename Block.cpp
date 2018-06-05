//
// Created by francesco on 20/04/18.
//

#include "Block.h"


Block::Block(sf::Vector2i windSize, int bls, Enemy &e, Maps &m, Hero &h) :
        windowSize (windSize), blockSize (bls), enemy (e), maps (m), hero (h) {

    SetBlock ();
    velocity = sf::Vector2f (0.1, 0);


}

Block::~Block() {
    blocks.clear ();
    blocks2.clear ();
}

void Block::Update() {
    Collision (false);

}

int Block::SetBlock() {

    block.setSize (sf::Vector2f (40, 10));
    block.setFillColor (sf::Color::Red);
    block2.setFillColor (sf::Color::Blue);
    block2.setSize (sf::Vector2f (50, 10));
    if (minrange > changedifficulty) {
        for (int j = 0; j < 50; ++j) {
            blockcreate += 1;
            decision = rand () % nrand;
            if (decision >= choose) {//IF CONTROLLA QUALE BLOCK SETTARE E DOVE SETTARLO 
                Random ();//FUNZIONE RANDOMICA CHE RITONA UN VETTORE DI POSIZIONE 
                block2.setPosition (random.x * blockSize, random.y + minrange);
                blocks2.emplace_back (block2);
                minrange -= bscale1;
            } else {
                Random ();
                block.setPosition (random.x * blockSize, random.y + minrange);
                blocks.emplace_back (block);
                minrange -= bscale1;
            }
        }
    }
    if (minrange <= changedifficulty && minrange > 0) {//AUMENTA LA DISTANZA TRA I BLOCCHI
        for (int i = 0; i < 30; ++i) {
            decision = rand () % nrand;
            blockcreate += 1;
            if (decision >= choose) {
                Random ();
                block.setPosition (random.x * blockSize, random.y + minrange);
                blocks.emplace_back (block);
                minrange -= bscale2;
            } else {
                Random ();
                block2.setPosition (random.x * blockSize, random.y + minrange);
                blocks2.emplace_back (block2);
                minrange -= bscale2;
            }
        }
        for (int k = 0; k < 20; ++k) {
            decision = rand () % nrand;
            blockcreate += 1;
            if (decision >= choose) {
                Random ();
                block.setPosition (random.x * blockSize, random.y + minrange);
                blocks.emplace_back (block);
                minrange -= bscale3;
            } else {
                Random ();
                block2.setPosition (random.x * blockSize, random.y + minrange);
                blocks2.emplace_back (block2);
                minrange -= bscale3;
            }
        }
    }


    return blockcreate;
}

void Block::Render(sf::RenderWindow &window) {
    for (const auto &block : blocks) {
        window.draw (block);
    }
    for (const auto &i : blocks2) {
        window.draw (i);
    }
}

sf::Vector2i Block::Random() {
    int maxX = (windowSize.x / blockSize) - 2;
    return random = sf::Vector2i (rand () % maxX + 1, rand () % 100 + 1);
}//funzione randomica per settare coordinate del blocco



void Block::Collision(bool collide) {
    for (auto i = 0; i < blocks.size (); ++i) {
        if ((blocks[i].getGlobalBounds ().intersects (hero.GetBound ()) && hero.Getvelocity () <= mindistance) ||
            collide) {//CONTROLLA LA COLLISIONE TRA BLOCK E HERO E MI RISETTA LA VELOCITA
            hero.Setvelocity ();
            hero.SetJump ();//VIENE INCREMENTATO VARIABILE SETJUMP 
           
        }
        if (blocks[i].getPosition ().y > hero.GetPosy () + bdistance) {
            Erase (i);//FA ERASE DEL BLOCCO i QUANDO SUPERA IL HERO DI BDISTANCE
        }
        if (blocks[i].getGlobalBounds ().intersects (enemy.GetBounden1 ())) {
            blocks[i].setPosition (blocks[i].getPosition ().x, enemy.GetPosy_en1 ());
        }//FUNZIONE CHE MI SETTA IL NEMICO SOPRA IL BLOCCO NEL CASO DELL'INTERSECT
    }

    for (auto j = 0; j < blocks2.size (); ++j) {
        if ((blocks2[j].getGlobalBounds ().intersects (hero.GetBound ()) && hero.Getvelocity () <= mindistance) ||
            collide) {
            hero.Setvelocity ();
            hero.SetJump ();
        }
        if (blocks2[j].getPosition ().y > hero.GetPosy () + bdistance) {
            Erase2 (j);
        }

    }

}


bool Block::Move() {
    for (auto i = 0; i < blocks2.size (); ++i) {
        if (maps.GetScore () > changedifficulty) {//AUMENTA VELOCITA QUANDO SCORE SUPERA CHANHEDIFFICULTY
            blocks2[i].move (velocity.x + 0.05f, velocity.y);
        } else {
            blocks2[i].move (velocity.x, velocity.y);
        }

        if (blocks2[i].getPosition ().x >= windowSize.x) { 
            blocks2[i].setPosition (pointzero, blocks2[i].getPosition ().y);
            repos = true;
        }//SE BLOCCO MAGGIORE DELLA GRANDEZZA  MAPPA TORNA ALLO ZERO
    }
    return repos;
}


float Block::GetposBlock(int index) {
    return blocks[index].getPosition ().y;
}

sf::Vector2f Block::TesPosBlock2(int index, int pos) {
    blocks2[index].setPosition (blocks2[index].getPosition ().x + pos, blocks2[index].getPosition ().y + pos);
    return {blocks2[index].getPosition ().x, blocks2[index].getPosition ().y};
}

float Block::GetBlock2posx(int index) {
    return blocks2[index].getPosition ().x;
}



