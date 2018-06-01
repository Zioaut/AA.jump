//
// Created by francesco on 30/05/18.
//


#include "gtest/gtest.h"
#include "../Enemy.h"




TEST (Enemy, TestEnemy) {
    StrategyMove *move = nullptr;
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    Enemy enemy (sf::Vector2f (0.0, 0.1), sf::Vector2i (500, 16000), 7, 6, move, hero);
    const int max_enemy=9;
    const int max_rangey=100;

    ASSERT_TRUE (max_enemy > enemy.SetEnemy ());
    ASSERT_TRUE (max_rangey>enemy.Getposy ());
    ASSERT_TRUE (max_rangey>enemy.Getposy2 ());
    ASSERT_TRUE (max_enemy>enemy.GetSizeEn1 ());
    ASSERT_TRUE (max_enemy>enemy.GetSizeEn2 ());
    ASSERT_TRUE (max_enemy>enemy.GetSizeEn3 ());
    //controllo che setta il numero corretto di nemici e che li setta senza uscire dal range stabilito
}