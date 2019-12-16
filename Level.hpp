#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED
#include <set>
#include <string>
#include <time.h>
#include "EnemyShip.hpp"
#include "Bonus.hpp"
#include "BonusBomb.hpp"
#include "BonusHeal.hpp"
#include "BonusProjectile.hpp"
#include "BonusShield.hpp"
#include "Boss.hpp"



class Level
{

private :
    unsigned int m_levelNumber;
    std::set<EnemyShip *> m_enemyShip;
    Boss *m_boss;
    std::set<Bonus*> m_bonus;

public :
    //CONSTRUCTORS
    Level();
    Level(unsigned int levelNumber);
    //DESTRUCTOR
    ~Level();

    //GETTERS & SETTERS
    unsigned int getLevelNumber() const;
    std::set<EnemyShip*> getEnemyShip() const;
    Boss* getBoss() const;
    std::set<Bonus*>getBonus() const;
    void setLevelNumber(unsigned int levelNumber);
    void setEnemyShip(std::set<EnemyShip*> enemies);
    void setBoss(Boss* boss);

    //FUNCTIONS
    void setDyEnemy();
    void generateEnemies();
    void createEnemy(float x, float y, float dx, float dy,int life, int projectileType, std::string type);
    void createBoss(float x, float y, float dx, float dy, int life, int projectileType);
    void moveEnemies();
    void moveBonus();
    void repopEnemy();
    void makeEnemiesShoot();
    bool enemyExitMap();
    bool bonusExitMap();
    void useBonus(PlayerShip * player);
    void deleteOutEnemies();
    void deleteOutBonus();
    void deleteKilledEnemy(EnemyShip* enemy);
    void deleteAllEnemies();
    void deleteBonus();
    void reset();
    void dropBonus(EnemyShip * enemy);
    int getAllEnemiesScore();
};



#endif // LEVEL_HPP_INCLUDED
