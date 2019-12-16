#ifndef PROJECTILE_HPP_INCLUDED
#define PROJECTILE_HPP_INCLUDED

#include "MovableObject.hpp"

#include <string>
class Projectile : public MovableObject
{
public:

    // Constucteurs & destructeur
    Projectile ();
    Projectile (float x, float y, float dx, float dy, unsigned int type_projectile);
    virtual ~Projectile ();

    // Accesseurs
    unsigned int getType_projectile();
    unsigned int getDamage();

    // Méthode(s)
    virtual void move();
    void setType_projectile ( unsigned int type_projectile );

private:

    unsigned int m_type_projectile;
    unsigned int m_damage;

};

#endif // PROJECTILE_HPP_INCLUDED
