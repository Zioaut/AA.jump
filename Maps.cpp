//
// Created by francesco on 25/04/18.
//

#include "Maps.h"


Maps::Maps(sf::Vector2f WindS, float sc,Block*block,Hero*hero):WindowSize(WindS),score(sc),block(block),hero(hero) {
    Reset ();




}


void Maps::Reset() {
    SetTablepoint ();
    score=0;
    view=sf::View(sf::Vector2f(300,1000),sf::Vector2f(600,1300));
    view.zoom (0.9f);

}


void Maps::SetTablepoint() {
    font.loadFromFile ("arial.ttf");
    text.setFont (font);
    text.setString ("0");
    text.setColor (sf::Color::Black);
    text.setPosition (WindowSize.x-30,50);

    //setta parametri punteggio
}


void Maps::Render(sf::RenderWindow &window) {
    window.draw (text);
    window.setView (view);

}

Maps::~Maps() {}

void Maps::Increase_Score(float timescore) {
    while (timescore<30){
        timescore+=0.1f;
    }
    if(timescore>30){
    score=WindowSize.y-hero->GetPosy ();
    Addstring (std::to_string (static_cast<int>(score)));
    }

}
void Maps::Addstring(std::string message) {
    text.setString (message);//mi aggiunge a text una stringa
}


void Maps::Update() {
    Increase_Score (0);
    View (*hero);

}
void Maps::View(Hero &hero) {
    if (hero.GetPosy () < view.getCenter ().y) {
        view.setCenter (view.getCenter ().x, hero.GetPosy ());

   }
}