#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include "MovableObject.hpp"
#include "Projectile.hpp"
#include <set>

#include <iostream>
#include <string>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


class Ship : public MovableObject
{
public:

    // CONSTRUCTORS
    Ship ();
    Ship (float x, float y, float dx, float dy, int life, int projectileType) ;
    // DESTRUCTOR
    virtual ~Ship ();

    //SETTERS & GETTERS
    void setLife (int life);
    int getLife ();
    int getProjectileType();
    std::set<Projectile*> getProjectile();

    // FUNCTIONS
    virtual void shoot();
    virtual void move() = 0;
    virtual void moveProjectile() = 0;
    void loseHealth(Projectile * p);
    std::string toString();
    void deleteProjectile(Projectile * p);
    void deleteOutProjectile();
    void increaseProjectileType();
    void resetProjectileType();

protected:
    //ATTRIBUTES
    int m_life;
    int m_projectileType;
    std::set<Projectile*> m_projectile;
};
#endif // SHIP_HPP_INCLUDED
