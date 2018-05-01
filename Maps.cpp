//
// Created by francesco on 25/04/18.
//

#include "Maps.h"


Maps::Maps(sf::Vector2f WindS, int sc,Block*block,Hero*hero):WindowSize(WindS),score(sc),block(block),hero(hero) {
    Reset ();




}


void Maps::Reset() {
    SetTablepoint ();
    score=0;
    view=sf::View(sf::Vector2f(150,800),sf::Vector2f(600,1000));

}


void Maps::SetTablepoint() {
    font.loadFromFile ("arial.ttf");
    text.setFont (font);
    text.setString ("0");
    text.setColor (sf::Color::Black);
    text.setPosition (WindowSize.x-30,5);
    //setta parametri punteggio
}


void Maps::Render(sf::RenderWindow &window) {
    window.draw (text);
    window.setView (view);

}

Maps::~Maps() {}

void Maps::Increase_Score(Block& block) {
//todo incrementare punteggio
}

void Maps::Addstring(std::string message) {
    text.setString (message);//mi aggiunge a text una stringa
}


void Maps::Update() {
    Increase_Score (*block);
    View (*hero);

}
void Maps::View(Hero &hero) {
    if(hero.GetPosy ()<view.getCenter ().y){
        view.setCenter (view.getCenter ().x,view.getCenter ().y-hero.GetPosy ());
        view.move (0,300);
    }else {

    }     //todo muove la visuale a seconda del salto di hero
}