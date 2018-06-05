//
// Created by francesco on 30/05/18.
//


#include "gtest/gtest.h"
#include "../Enemy.h"


TEST (Enemy, TestEnemy) {
    StrategyMove *move = nullptr;
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    Enemy enemy (sf::Vector2f (0.0, 0.1), sf::Vector2i (500, 16000), 7, 6, move, hero);
    const int max_enemy = 10;
    const int max_rangey = 100;




    ASSERT_TRUE (max_enemy >= enemy.SetEnemy ());
    ASSERT_TRUE (max_rangey > enemy.Getposy ());
    ASSERT_TRUE (max_rangey > enemy.Getposy2 ());
    ASSERT_TRUE (max_enemy > enemy.GetSizeEn1 ());
    ASSERT_TRUE (max_enemy > enemy.GetSizeEn2 ());
    //controllo che setta il numero corretto di nemici e che li setta senza uscire dal range stabilito


}


TEST (Enemy,TestEnemy1){
    StrategyMove *move = nullptr;
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    Enemy enemy (sf::Vector2f (0.0, 0.1), sf::Vector2i (500, 16000), 7, 6, move, hero);


    const int distance = 300;
    const int first=0;
    const int testpos=-10000;
    sf::CircleShape bullettest;
    bullettest.setRadius (5);
    int sizeen1=enemy.GetSizeEn1 ();
    int sizeen3=enemy.GetSizeEn3 ();

    bullettest.setPosition (enemy.SetposEntest (first));

    if (enemy.TestRectEn1 (first).intersects (bullettest.getGlobalBounds ())) {
        enemy.EraseEn1 (first);
        ASSERT_TRUE (sizeen1> enemy.GetSizeEn1 ());
        enemy.Death_En1 (true);
        ASSERT_TRUE (sizeen3<enemy.GetSizeEn3 ());
    }

    sf::RectangleShape herotest;
    herotest.setSize (sf::Vector2f(20,40));
    herotest.setPosition (enemy.SetposEntest (first));

    if(enemy.TestRectEn1 (first).intersects (herotest.getGlobalBounds ())){
        hero.GameOver (true);//CONTROLLA SE HERO MUORE DIVENTA NERO
        ASSERT_EQ (sf::Color::Black,hero.GetColor ());
    }


    herotest.setPosition (hero.SetPositionTest (testpos));

    if (enemy.SetposEntest (first).y > herotest.getPosition ().y + distance) {
        ASSERT_EQ (0, enemy.GetSizeEn1 ());//CONTROLLA SE FA L'ERASE
    }



}


TEST (Enemy,TestEnemy2){
    StrategyMove *move = nullptr;
    Hero hero (0.00002f, 0.3f, sf::Vector2f (0.1, 0.1), 0, 0, 0, 0);
    Enemy enemy (sf::Vector2f (0.0, 0.1), sf::Vector2i (500, 16000), 7, 6, move, hero);

    const int first=0;
    int sizen2=enemy.GetSizeEn2 ();
    sf::RectangleShape testenemyshape;
    testenemyshape.setSize (sf::Vector2f(20,40));

    testenemyshape.setPosition (enemy.SetposEn2test (first));
    float posx=testenemyshape.getPosition ().x;
    if (testenemyshape.getPosition ().x > hero.GetPosx ()) {
        move = new StrategyDefenseRight (0.5, 0, false, 0);
        testenemyshape.move (move->Strategy_move ());
        ASSERT_TRUE (testenemyshape.getPosition ().x < posx);
        delete move;//CONTROLLA SE FA CORRETTEMENTE LO STRATEGY
    }
    else if (testenemyshape.getPosition ().x < hero.GetPosx ()) {
        move = new StrategyDefenseLeft (0.5, 0, false, 0);
        testenemyshape.move (move->Strategy_move ());
        ASSERT_TRUE (testenemyshape.getPosition ().x > posx);
        delete move;
    }

    sf::CircleShape bullettest;
    bullettest.setRadius (5);

    bullettest.setPosition (enemy.SetposEn2test (first));

    if(enemy.TestRectEn2 (first).intersects (bullettest.getGlobalBounds ())){
        enemy.EraseEn2 (first);
        ASSERT_TRUE (sizen2>enemy.GetSizeEn2 ());//CONTROLLO SE FA L'ERASE QUANDO INTERSECT CON BLOCK
    }


    testenemyshape.setPosition (enemy.SetposEn2test (first));

    if(enemy.TestRectEn2 (first).intersects (testenemyshape.getGlobalBounds ())){
        hero.GameOver (true);
        ASSERT_EQ (sf::Color::Black,hero.GetColor ());//CONTROLLO SE HERO DIVENTA NERO SE MUORE
    }

}


