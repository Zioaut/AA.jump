//
// Created by francesco on 15/03/18.
//

#include "Game.h"


Game::Game() : window ("", sf::Vector2u (400,600)), hero () {
}

Game::~Game() {


}

void Game::Update() {
    window.Update ();
    hero.Update ();
}


void Game::HandleInput() {
    hero.Jump ();
}


void Game::Render() {
    window.BeginDraw ();
    hero.Reneder (*window.GetRenderWindow ());
    window.EndDraw ();
}