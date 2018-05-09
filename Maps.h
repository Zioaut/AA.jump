//
// Created by francesco on 25/04/18.
//

#ifndef AA_JUMP_MAPS_H
#define AA_JUMP_MAPS_H


#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Observer.h"


class Maps: public Observer {
public:
    Maps(sf::Vector2f WindS, float sc,Hero*hero= nullptr);

    ~Maps();
    void Increase_Score(float timescore);
    void Reset();
    void SetTablepoint();
    void Render(sf::RenderWindow & window);
    void Update();
    virtual void Achievments() override ;
    float GetViewSize(){return view.getCenter ().y;};



private:
    sf::Vector2f WindowSize;
    void View(Hero& hero);
    void Addstring(std::string message);
    float score;
    sf::View view;
    sf::Text text;
    sf::Font font;
    Hero*hero;



};


#endif //AA_JUMP_MAPS_H
