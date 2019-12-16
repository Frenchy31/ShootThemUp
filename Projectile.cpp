#include "Projectile.hpp"

using namespace std;

// Constructeur(s)
Projectile::Projectile () : MovableObject() , m_type_projectile(1)
{
    if(m_type_projectile == 3)
        m_damage = 100;
    else if (m_type_projectile == 2)
        m_damage = 50;
    else
        m_damage = 25;
}

Projectile::Projectile (float x, float y, float dx, float dy, unsigned int type_projectile)
    : MovableObject(x,y,dx,dy), m_type_projectile(type_projectile)
{
    if(m_type_projectile == 3)
        m_damage = 75;
    else if (m_type_projectile == 2)
        m_damage = 50;
    else
    {
        m_type_projectile = 1;
        m_damage = 25;
    }

}

//Destructeur
Projectile::~Projectile ()
{
}

//Getters & setters
void Projectile::setType_projectile ( unsigned int type_projectile )
{
    if(type_projectile == 3)
    {
        m_type_projectile = type_projectile;
        m_damage = 100;
    }

    else if (type_projectile == 2)
    {
        m_type_projectile = type_projectile;
        m_damage = 50;
    }

    else
    {
        m_type_projectile = 1;
        m_damage = 25;
    }

}

unsigned int  Projectile::getType_projectile()
{
    return m_type_projectile;
}

unsigned int Projectile::getDamage()
{
    return m_damage;
}

void Projectile::move()
{
    m_x+=m_dx;
}


