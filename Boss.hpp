#ifndef BOSS_HPP_INCLUDED
#define BOSS_HPP_INCLUDED

#define BOSS_LIFE 300
#include "Ship.hpp"
#include <set>
#include <string>

/*** CLASSE BOSS ***/
/* La classe Boss est un Ship qui apparait en fin de niveau */


class Boss : public Ship
{
public:
    //CONSTRUCTORS
    Boss ();
    Boss (float x, float y, float dx, float dy, int life, int projectileType);
    //DESTRUCTOR
    virtual ~Boss ();
    //FUNCTIONS
    void shoot();
    virtual void move();
    virtual void moveProjectile();

};
#endif // BOSS_HPP_INCLUDED
