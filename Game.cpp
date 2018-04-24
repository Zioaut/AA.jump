//
// Created by francesco on 15/03/18.
//

#include "Game.h"


Game::Game() : window ("", sf::Vector2u (400,600)), hero (0.00002f,0.08f,sf::Vector2f(0.1,0.1),&enemy,&block),
               enemy (sf::Vector2f(0.08,0.05),sf::Vector2i(400,600),10,6),block(sf::Vector2i(400,600),9) {
}

Game::~Game() {


}

void Game::Update() {
    window.Update ();
    hero.Update ();
    enemy.Update ();
    block.Update ();
}


void Game::HandleInput() {
    hero.Jump ();
    enemy.Move ();


}


void Game::Render() {
    window.BeginDraw ();
    hero.Reneder (*window.GetRenderWindow ());
    enemy.Render (*window.GetRenderWindow ());
    block.Render (*window.GetRenderWindow ());
    window.EndDraw ();
}