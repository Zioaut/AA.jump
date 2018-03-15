//
// Created by francesco on 15/03/18.
//

#include "Game.h"


Game::Game() : window ("", sf::Vector2u (800, 600)) {
}

Game::~Game() {


}

void Game::Update() {
    window.Update ();
}


void Game::HandleInput() {}


void Game::Render() {
    window.BeginDraw ();
    window.EndDraw ();
}