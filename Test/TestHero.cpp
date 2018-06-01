//
// Created by francesco on 30/05/18.
//


#include "gtest/gtest.h"
#include "../Hero.h"


TEST (Hero, testColor) {
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    sf::Color color = hero.GetColor ();
    if (hero.GetDeath ()) {
        ASSERT_EQ (sf::Color::Black, color);
    }
    if (!hero.GetDeath ()) {
        ASSERT_EQ (sf::Color (144, 238, 144), color);
    }

    //controllo il colore di hero
}

TEST (Hero, testPosition) {
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    ASSERT_EQ (15000, hero.GetPosy ());
    float velocity = hero.Getvelocity ();
    hero.Setvelocity ();
    float vel = 0.1f;
    ASSERT_EQ (vel, velocity);
    ASSERT_TRUE (vel > hero.Jump ());

    //controllo posizione iniziale e velocita
}

TEST (Hero, testSetvariable) {
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    
    ASSERT_EQ (0, hero.Setpoint (0));
    ASSERT_EQ (1, hero.SetKillYellow ());
    ASSERT_EQ (1, hero.Setnumbullet ());
    ASSERT_EQ (1, hero.SetKillGreen ());
    ASSERT_EQ (1, hero.SetJump ());
    //controllo se i set sono corretti

}



