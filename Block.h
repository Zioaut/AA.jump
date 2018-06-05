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
    Block(sf::Vector2i windSize, int bls, Enemy &e, Maps &m, Hero &h);

    ~Block();

    void Update();

    int SetBlock();

    void Render(sf::RenderWindow &window);

    void Collision(bool collide);

    bool Move();

    //FUNZIONI CHE FANNO ERASE DI UNA DETERMINATA POSIZIONE DEL VETTORE DEI BLOCCHI
    void Erase(int index) { blocks.erase (blocks.begin () + index); }

    void Erase2(int index) { blocks2.erase (blocks2.begin () + index); }
    
    //FUNZIONI CHE SERVONO PER IL TEST..

    int Getdecision() { return decision; }

    int GetrandomX() { return random.x; }

    int Getrandomy() { return random.y; }
    
    //FUNZIONI CHE MI RITORNANO LA LUNGHEZZA DEI VETTORI DI BLOCCHI
    int GetSizeBlock1() { return static_cast<int>(blocks.size ()); }

    int GetSizeBlock2() { return static_cast<int>(blocks2.size ()); }

    //SETTANO POSIZIONI DEI BLOCCHI
    float GetposBlock(int index);
    
    sf::Vector2f TesPosBlock2(int index, int pos);

    float GetBlock2posx(int index);

    


private:
    sf::Vector2f velocity;

    sf::Vector2i Random();

    sf::RectangleShape block2;
    sf::RectangleShape block;
    std::vector<sf::RectangleShape> blocks;
    std::vector<sf::RectangleShape> blocks2;
    sf::Vector2i windowSize;
    int blockSize;
    sf::Vector2i random;
    Hero &hero;
    Enemy &enemy;
    Maps &maps;
    int minrange = 15500;//INDICI PER SETTARE POSIZIONI DEL BLOCCO E PER LA DISTANZA TRA UNO E L'ALTRO
    const int changedifficulty = 10500;
    const int bscale1 = 100;
    const int bscale2 = 200;
    const int bscale3 = 250;
    const int bdistance = 300;//MI DA LA DISTANZA PER FARE ERASE
    const int mindistance = 0;
    const int nrand = 10 + 1;
    const int choose = 6;
    int blockcreate = 0;//CONTATORE PER TEST
    int decision;//VALORE RANDOMICO PER SCEGLIERE QUALE BLOCK SETTARE
    const int pointzero = 0;
    bool repos = false;//VARIABILE BOOLEANA PER CONTROLLO SUL TEST
};


#endif //AA_JUMP_BLOCK_H
