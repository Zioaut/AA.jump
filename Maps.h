//
// Created by francesco on 25/04/18.
//

#ifndef AA_JUMP_MAPS_H
#define AA_JUMP_MAPS_H


#include <SFML/Graphics.hpp>
#include "Block.h"

class Maps {
public:
    Maps(sf::Vector2f WindS,int sc,Block*block= nullptr,Hero*hero= nullptr);

    ~Maps();
    void Increase_Score(Block& block);
    void Reset();
    void SetTablepoint();
    void Render(sf::RenderWindow & window);
    void Update();




private:
    sf::Vector2f WindowSize;
    void View(Hero& hero);
    void Addstring(std::string message);
    int score;
    sf::View view;
    sf::Text text;
    sf::Font font;
    Block*block;
    Hero*hero;


};


#endif //AA_JUMP_MAPS_H
