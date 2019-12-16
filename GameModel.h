#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <time.h>
#include <string>
#include <set>
#include <iostream>
#include "EnemyShip.hpp"
#include "PlayerShip.h"
#include "Boss.hpp"
#include "Level.hpp"

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

    //FUNCTIONS
    void nextStep();
    void getPlayerPos(float &x, float &y) const;
    bool getEnemyPos(float &x, float &y, EnemyShip *enemy) const;
    EnemyShip * enemyShootSuccess();
    void playerHit();
    void nextLevel();
    void reset();
    void bonusAndEnemiesExitMap();
    void enemyShoot();
    void defeat();
    void victory();
    void activateBonus();
    bool getResult();


private:
    //ATTRIBUTES
    bool _result;
    int m_w,m_h;
    Level* m_level;
    PlayerShip *m_playerShip;
    int m_scorePlayer;
    std::set<Bonus*>  m_bonus;



};

#endif // GAMEMODEL_H
