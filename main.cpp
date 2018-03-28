#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    Game game;
    Hero hero;
    while (!game.GetWindow ()->IsDone ()) {
        game.Render ();
        game.HandleInput ();
        game.Update ();
    }
}