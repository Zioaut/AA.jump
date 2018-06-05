//
// Created by francesco on 30/05/18.
//


#include "gtest/gtest.h"
#include "../Hero.h"
#include "../Achievments.h"

TEST (Hero, testColor) {
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    if (hero.GameOver (true)) {
        ASSERT_EQ (sf::Color::Black, hero.GetColor ());
    } else
        ASSERT_EQ (sf::Color (144, 238, 144), hero.GetColor ());

}

//controllo il colore di hero


TEST (Hero, testPosition) {
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    ASSERT_EQ (15000, hero.GetPosy ());
    float velocity = hero.Getvelocity ();
    float vel = 0.1f;
    const int maxsizewindow = 500;
    ASSERT_EQ (vel, velocity);

    hero.SetPositionTest (maxsizewindow);//setto posizione  di x hero >windowsize e controllo se la posizione viene messa a 0
    if (hero.Collision ()) {

        ASSERT_EQ (0, hero.GetPosx ());
    }
    hero.SetPositionTest (-maxsizewindow);//setto posizione di x hero<0 e controllo se la posizione viene messa a windowsize.x

    if (hero.Collision ()) {
        ASSERT_EQ (maxsizewindow, hero.GetPosx ());
    }

    //controllo posizione iniziale e velocita
}

TEST (Hero, testSetvariable) {
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);

    ASSERT_EQ (0, hero.Setpoint (0));
    ASSERT_EQ (1, hero.SetKillYellow ());
    ASSERT_EQ (1, hero.Setnumbullet ());
    ASSERT_EQ (1, hero.SetKillGreen ());
    ASSERT_EQ (1, hero.SetJump ());
    ASSERT_EQ (0, hero.GetBulletsize ());
    //controllo se i set sono corretti
}



