//
// Created by francesco on 15/03/18.
//

#include "Game.h"


Game::Game() : window ("", sf::Vector2u (500,5600)), hero (0.00002f,0.09f,sf::Vector2f(0.1,0.1),0,0,0,0),
               enemy (sf::Vector2f(0.1,0.1),sf::Vector2i(500,5600),7,6,&hero,move),
               block(sf::Vector2i(500,5600),9,&hero,&enemy,&maps),
               maps(sf::Vector2f(500,5600),0,&hero),
               achievments(&hero) {


}

Game::~Game() {



}

void Game::Update() {
    window.Update ();
    if(window.GetWindowSize ().y-hero.GetPosy ()>400){
        window.SetActive;
    }
    hero.Update ();
    enemy.Update ();
    block.Update ();
    maps.Update ();
}


void Game::HandleInput() {
    hero.Jump ();
    enemy.Move ();
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

