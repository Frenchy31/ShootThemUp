#ifndef GAMEMODEL_HPP_INCLUDED
#define GAMEMODEL_HPP_INCLUDED

#include <time.h>
#include <string>
#include <set>
#include <iostream>
#include "EnemyShip.hpp"
#include "PlayerShip.hpp"
#include "Boss.hpp"
#include "Level.hpp"

#define SCORE_TO_LEVEL_2 1000
#define SCORE_TO_LEVEL_3 2500
#define SCORE_TO_NEXT 2500
#define SCORE_TO_WIN 100000

/*** CLASSE GAMEMODEL ***/
/* La classe GameModel est la classe qui permet de gerer*/
/*  les parties du jeu dans lesquelles il n'y a pas  */
/*              d'interactions avec l'utilisateur    */
class GameModel
{
public:
    //CONSTRUCTORS
    GameModel ();
    GameModel(int w, int h);
    virtual ~GameModel ();

    //GETTERS & SETTERS
    void setM_playerShip (PlayerShip* joueur);
    PlayerShip *getPlayerShip();
    int getScorePlayer();
    Level* getLevel();
    bool getHasWon();
    void setHasWon(bool hasWon);
    bool getHasLost();
    void setHasLost(bool hasLost);
    bool getResult();
    void setResult(bool result);
    bool getHasLoseLife();
    void setHasLoseLife(bool hasloselife);
    bool getToNextLevel();
    void setToNextLevel(bool toNextLevel);

    //FUNCTIONS
    void nextStep();
    bool getEnemyPos(float &x, float &y, EnemyShip *enemy) const;
    void firingEnemies();
    void enemyShootSuccess();
    void playerHit();
    void nextLevel();
    void reset();
    void bonusAndEnemiesExitMap();
    void useBomb();
    void defeat();
    void victory();
    void activateBonus();
    void checkLife();



private:
    //ATTRIBUTES
    bool _result;
    bool _hasLoseLife;
    bool _hasWon;
    bool _hasLost;
    bool _toNextLevel;



    int m_w,m_h;
    int m_limitScore;
    int m_scorePlayer;

    Level* m_level;
    PlayerShip *m_playerShip;

    sf::Clock m_clock;
    sf::Clock m_clockMove;



};
#endif // GAMEMODEL_HPP_INCLUDED
