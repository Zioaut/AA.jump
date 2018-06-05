//
// Created by francesco on 30/05/18.
//

#include "gtest/gtest.h"
#include "../Maps.h"

TEST (Maps,TestMap){
    Hero hero(0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    Maps maps(sf::Vector2f (500, 16000), 0, hero);

    int startpointmap=16000;
    float score=0.0f;
    const int distance=300;
    const int testpos=-3000;

    ASSERT_TRUE (startpointmap>maps.Gettextpositiony ());
    ASSERT_EQ (maps.GetviewCenter (),hero.GetPosy ());
    ASSERT_EQ (score,maps.GetScore () );
    //controllo la view e score al run time


    sf::RectangleShape herotest;
    herotest.setPosition (hero.SetPositionTest (testpos));
    maps.View (true);
    ASSERT_EQ (maps.Gettextpositiony (),herotest.getPosition ().y-distance);//CONTROLLO CORRETTA POS DI TEXT VARIARE DI HERO
}