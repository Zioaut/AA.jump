//
// Created by francesco on 25/04/18.
//

#include <iostream>
#include <utility>
#include "Maps.h"


Maps::Maps(sf::Vector2f WindS, float sc, Hero &h) : WindowSize (WindS), score (sc), hero (h) {
    Reset ();


}


void Maps::Reset() {//GENERALITA DELLA VIDEOCAMERA E PUNTEGGIO
    SetTablepoint ();
    score = 0;
    view = sf::View (sf::Vector2f (300, 15000), sf::Vector2f (600, 600));


}


void Maps::SetTablepoint() {//GENERALITA DEL TESTO
    font.loadFromFile ("arial.ttf");
    text.setFont (font);
    text.setString ("");
    text.setColor (sf::Color::Blue);
    text.setCharacterSize (25);
    text.setPosition (50, 15200);

    //setta parametri punteggio
}


void Maps::Render(sf::RenderWindow &window) {
    window.draw (text);
    window.setView (view);

}

Maps::~Maps() {

}

void Maps::Increase_Score() {//INCREMENTO DELLO SCORE
    score = WindowSize.y - hero.GetPosy () - mdistance;
    if (hero.Getvelocity () >= 0) {
        Addstring (std::to_string (static_cast<int>(score)));
    }
    if (score >= checkpoint) {
        hero.Setpoint (static_cast<int>(score));
    }
}

void Maps::Addstring(std::string message) {
    text.setString (message);//mi aggiunge a text una stringa
}


void Maps::Update() {
    Increase_Score ();
    View (false);

}

void Maps::View(bool testview) {//SETTAGGIO TELECAMERA CON POSIZIONE DELL'HERO
    if (hero.GetPosy () < view.getCenter ().y || testview) {
        view.setCenter (view.getCenter ().x, hero.GetPosy ());
        text.setPosition (text.getPosition ().x, hero.GetPosy () - mdistance);//SETTAGGIO POS TEXT
    }

    if (hero.GetPosy () > view.getCenter ().y + mdistance) {
        hero.GameOver (true);//MI DA LA MORTE DI HERO


    }
}
