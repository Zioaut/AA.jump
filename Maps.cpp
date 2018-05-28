//
// Created by francesco on 25/04/18.
//

#include <iostream>
#include "Maps.h"


Maps::Maps(sf::Vector2f WindS, float sc,Hero*hero):WindowSize(WindS),score(sc),hero(hero){
    Reset ();


}


void Maps::Reset() {
    SetTablepoint ();
    score=0;
    view=sf::View(sf::Vector2f(300,15000),sf::Vector2f(300,300));
    view.zoom (2.1f);

}


void Maps::SetTablepoint() {
    font.loadFromFile ("arial.ttf");
    text.setFont (font);
    text.setString ("");
    text.setColor (sf::Color::Blue);
    text.setCharacterSize (25);
    text.setPosition (50,15200);

    //setta parametri punteggio
}


void Maps::Render(sf::RenderWindow &window) {
    window.draw (text);

    window.setView (view);

}

Maps::~Maps() {

}

void Maps::Increase_Score() {
    score=WindowSize.y-hero->GetPosy ()-mdistance;
    if(hero->Getvelocity ()>=0){
        Addstring (std::to_string (static_cast<int>(score)));
    }
    if(score>=3000){
        hero->Setpoint (static_cast<int>(score));
    }
}
void Maps::Addstring(std::string message) {
    text.setString (message);//mi aggiunge a text una stringa
}


void Maps::Update() {
    Increase_Score ();
    View ();

}
void Maps::View() {
    if (hero->GetPosy () < view.getCenter ().y) {
        view.setCenter (view.getCenter ().x, hero->GetPosy ());
        text.setPosition (text.getPosition ().x,hero->GetPosy ()-mdistance);
   }
}


