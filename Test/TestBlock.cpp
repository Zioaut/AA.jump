//
// Created by francesco on 30/05/18.
//


#include "gtest/gtest.h"
#include "../Block.h"


TEST (Block, TestBlock) {
    StrategyMove *move;
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    Enemy enemy (sf::Vector2f (0.0, 0.1), sf::Vector2i (500, 16000), 7, 6, move, hero);
    Maps maps (sf::Vector2f (500, 16000), 0, hero);
    Block block (sf::Vector2i (500, 16000), 9, enemy, maps, hero);

        const int max_block=100;
        const int decision=11;
        const int maxrandomx=500;
        const int maxrandomy=100;


    ASSERT_EQ (max_block, block.SetBlock ());
    ASSERT_TRUE (decision > block.Getdecision ());
    ASSERT_TRUE (maxrandomy > block.Getrandomy ());
    ASSERT_TRUE (maxrandomx > block.GetrandomX ());
    ASSERT_TRUE (max_block>block.GetSizeBlock1 ());
    ASSERT_TRUE (max_block>block.GetSizeBlock2 ());
    //controllo se crea il numero corretto di blocchi dentro i range stabiliti

}


