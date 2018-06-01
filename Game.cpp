//
// Created by francesco on 15/03/18.
//

#include "Game.h"


Game::Game() : window ("", sf::Vector2u (500, 16000)),
               hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0),
               enemy (sf::Vector2f (0.0, 0.1), sf::Vector2i (500, 16000), 7, 6, move, hero),
               block (sf::Vector2i (500, 16000), 9, enemy, maps, hero),
               maps (sf::Vector2f (500, 16000), 0, hero),
               achievments (&hero) {


}

Game::~Game() {

}

void Game::Update() {
    window.Update ();
    hero.Update ();
    enemy.Update ();
    block.Update ();
    maps.Update ();

}


void Game::HandleInput() {
    hero.Jump ();
    enemy.Move ();
    enemy.Move3 ();
    block.Move ();
}


void Game::Render() {
    window.BeginDraw ();
    hero.Reneder (*window.GetRenderWindow ());
    enemy.Render (*window.GetRenderWindow ());
    block.Render (*window.GetRenderWindow ());
    maps.Render (*window.GetRenderWindow ());
    window.EndDraw ();
}
