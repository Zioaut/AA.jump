//
// Created by francesco on 15/03/18.
//

#include "Game.h"


Game::Game() : window ("", sf::Vector2u (400,600)), hero (0.00002f,1.2f,sf::Vector2f(0.1,0.1),&enemy),
               enemy (sf::Vector2f(0.08,0.05)) {
}

Game::~Game() {


}

void Game::Update() {

    window.Update ();
    hero.Update ();
    enemy.Update ();
}


void Game::HandleInput() {
    hero.Jump ();
    enemy.Move ();
    hero.Shoot (&enemy);

}


void Game::Render() {
    window.BeginDraw ();
    hero.Reneder (*window.GetRenderWindow ());
    enemy.Render (*window.GetRenderWindow ());
    window.EndDraw ();
}