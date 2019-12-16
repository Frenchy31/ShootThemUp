#ifndef ENEMYSHIP_HPP_INCLUDED
#define ENEMYSHIP_HPP_INCLUDED

#include "Ship.hpp"

#include <string>
#include <assert.h>
//Constantes correspondant aux attributs a insérer aux ennemis
#define EASY_ENEMY_LIFE 100
#define EASY_ENEMY_VALUE 25
#define EASY_ENEMY_PROJECTILE 1

#define MEDIUM_ENEMY_LIFE 150
#define MEDIUM_ENEMY_VALUE 50
#define MEDIUM_ENEMY_PROJECTILE 2

#define HARD_ENEMY_LIFE 200
#define HARD_ENEMY_VALUE 100
#define HARD_ENEMY_PROJECTILE 3

#define DEFAULT_ENEMY_SPEED 2

#define HEIGHT_ENEMYSHIP 72
#define WIDTH_ENEMYSHIP 72

/*** CLASSE ENEMYSHIP ***/
/* La classe EnemyShip est un Ship                   */
/* Les attributs sont différemment initialisés selon */
/*              le type de l'ennemi.                 */
class EnemyShip : public Ship
{
public:

    // CONSTRUCTORS
    EnemyShip();
    EnemyShip (float x, float y, float dx, float dy,int life, int projectileType, std::string type );
    //DESTRUCTOR
    virtual ~EnemyShip ();

    //GETTERS & SETTERS
    void setType (std::string type);
    std::string getType();
    int getScoreValue();

    //FUNCTIONS
    virtual void shoot();
    virtual void move();
    virtual void moveProjectile();
    void loseLife(Projectile *p);
    std::string toString();

protected:
    //ATTRIBUTES
    std::string m_type;
    int m_scoreValue;
};
#endif // ENEMYSHIP_HPP_INCLUDED
