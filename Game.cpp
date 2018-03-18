//
// Created by francesco on 15/03/18.
//

#include "Game.h"


Game::Game() : window ("", sf::Vector2u (800, 600)), hero (sf::Vector2u (800, 600)) {
}

Game::~Game() {


}

void Game::Update() {
    window.Update ();
    hero.Update ();
}


void Game::HandleInput() {
    hero.MoveBall ();
    hero.Jump ();
}


void Game::Render() {
    window.BeginDraw ();
    hero.Reneder (*window.GetRenderWindow ());
    window.EndDraw ();
}