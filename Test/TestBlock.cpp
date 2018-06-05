//
// Created by francesco on 30/05/18.
//


#include "gtest/gtest.h"
#include "../Block.h"


TEST (Block, TestBlock) {
    StrategyMove *move;
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.11), 0, 0, 0, 0);
    Enemy enemy (sf::Vector2f (0.0, 0.1), sf::Vector2i (500, 16000), 7, 6, move, hero);
    Maps maps (sf::Vector2f (500, 16000), 0, hero);
    Block block (sf::Vector2i (500, 16000), 9, enemy, maps, hero);

    const int max_block = 100;
    const int decision = 11;
    const int maxrandomx = 500;
    const int maxrandomy = 100;

    ASSERT_EQ (max_block, block.SetBlock ());
    ASSERT_TRUE (decision > block.Getdecision ());
    ASSERT_TRUE (maxrandomy >= block.Getrandomy ());
    ASSERT_TRUE (maxrandomx > block.GetrandomX ());
    ASSERT_TRUE (max_block > block.GetSizeBlock1 ());
    ASSERT_TRUE (max_block > block.GetSizeBlock2 ());
    //controllo se crea il numero corretto di blocchi dentro i range stabiliti
    sf::RectangleShape testblock;

    testblock.setSize (sf::Vector2f (20, 40));
    testblock.setPosition (hero.GetPosx (), hero.GetPosy ());

    if (testblock.getGlobalBounds ().intersects (hero.GetBound ())) {//controllo se il sistema riconosce intersect
        block.Collision (true);
        ASSERT_EQ (0.1f, hero.Getvelocity ());
    }

}


TEST (Block, TestBlock1) {
    StrategyMove *move = nullptr;
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.11), 0, 0, 0, 0);
    Enemy enemy (sf::Vector2f (0.0, 0.1), sf::Vector2i (500, 16000), 7, 6, move, hero);
    Maps maps (sf::Vector2f (500, 16000), 0, hero);
    Block block (sf::Vector2i (500, 16000), 9, enemy, maps, hero);

    const int range = 300;
    const int first = 0;
    int sizeblock = block.GetSizeBlock1 ();


    if (block.GetposBlock (first) >
        hero.GetPosy () + range) {//controllo se il block viene eliminaro quando la sua y > del range stabilito
        block.Erase (first);
        ASSERT_TRUE (sizeblock > block.GetSizeBlock1 ());//CONTROLLO CHE HA FATTO ERASE
    }


}


TEST (Block, TestBlock2) {
    StrategyMove *move = nullptr;
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.11), 0, 0, 0, 0);
    Enemy enemy (sf::Vector2f (0.0, 0.1), sf::Vector2i (500, 16000), 7, 6, move, hero);
    Maps maps (sf::Vector2f (500, 16000), 0, hero);
    Block block (sf::Vector2i (500, 16000), 9, enemy, maps, hero);


    const int range = 300;
    const int first = 0;
    int sizeblock = block.GetSizeBlock2 ();
    const int maxrandomx = 500;

    sf::RectangleShape testblock;

    testblock.setSize (sf::Vector2f (20, 40));

    testblock.setPosition (block.TesPosBlock2 (0, maxrandomx));

    if (block.Move ()) {//CONTROLLO REPOSIZIONAMENTO DI BLOCK2
        testblock.setPosition (block.GetBlock2posx (first), testblock.getPosition ().y);
        ASSERT_EQ (0, testblock.getPosition ().x);
    }

    testblock.setPosition (block.TesPosBlock2 (first, maxrandomx));
    if (testblock.getPosition ().y >
        hero.GetPosy () + range) {//controllo se il block viene eliminaro quando la sua y > del range stabilito
        block.Erase2 (first);
        ASSERT_TRUE (sizeblock > block.GetSizeBlock2 ());
    }

}