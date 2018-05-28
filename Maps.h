//
// Created by francesco on 25/04/18.
//

#ifndef AA_JUMP_MAPS_H
#define AA_JUMP_MAPS_H


#include <SFML/Graphics.hpp>
#include "Hero.h"


class Maps {
public:
    Maps(sf::Vector2f WindS, float sc,Hero*hero);
    ~Maps();
    void Increase_Score();
    void Reset();
    void SetTablepoint();
    void Render(sf::RenderWindow & window);
    void Update();
    float  GetScore(){return score;}
    float GetViewPos(){return view.getCenter ().y;}



private:
    sf::Vector2f WindowSize;
    void View();
    void Addstring(std::string message);
    float score;
    sf::View view;
    sf::Text text;
    sf::Font font;
    Hero*hero;
    const int mdistance=300;

};


#endif //AA_JUMP_MAPS_H
