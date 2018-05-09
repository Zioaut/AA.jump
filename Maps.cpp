//
// Created by francesco on 25/04/18.
//

#include <iostream>
#include "Maps.h"


Maps::Maps(sf::Vector2f WindS, float sc,Hero*hero):WindowSize(WindS),score(sc),hero(hero) {
    Reset ();
    hero->Attach (this);
}


void Maps::Reset() {
    SetTablepoint ();
    score=0;
    view=sf::View(sf::Vector2f(300,5600),sf::Vector2f(100,100));
    view.zoom (6.0f);

}


void Maps::SetTablepoint() {
    font.loadFromFile ("arial.ttf");
    text.setFont (font);
    text.setString ("0000");
    text.setColor (sf::Color::Black);
    text.setCharacterSize (20);
    text.setPosition (WindowSize.x-100,5200);

    //setta parametri punteggio
}


void Maps::Render(sf::RenderWindow &window) {
    window.draw (text);
    window.setView (view);

}

Maps::~Maps() {
    hero->Detach (this);
}

void Maps::Increase_Score(float timescore) {
    int i=0;

    while (timescore<30){
        timescore+=0.1f;
    }
    if(timescore>30){
    score=WindowSize.y-hero->GetPosy ()-300;
    Addstring (std::to_string (static_cast<int>(score)));
    }
    if(i==0&&score==800){
        hero->Notify ();
        i++;
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
        text.setPosition (text.getPosition ().x,hero.GetPosy ()-100);
   }
}

void Maps::Achievments() {

}