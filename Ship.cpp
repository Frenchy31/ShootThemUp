#include "Ship.hpp"
#include "Projectile.hpp"

using namespace std;

// Constructeur(s)
Ship::Ship () : MovableObject() , m_life(0), m_projectileType(1)
{
}

Ship::Ship (float x, float y, float dx, float dy, int life, int projectileType)
    : MovableObject(x,y,dx,dy),m_life(life), m_projectileType(projectileType)
{

}

// Destructeur
Ship::~Ship ()
{
    for(auto proj : m_projectile)
    {
        m_projectile.erase(proj);
        delete proj;
    }

}

// Getter & setters
void Ship::setLife (int life)
{
    m_life = life;
}

int Ship::getLife ()
{
    return m_life;
}

int Ship::getProjectileType()
{
    return m_projectileType;
}

set<Projectile*> Ship::getProjectile()
{
    return m_projectile;
}

//Méthodes

string Ship::toString()
{
    stringstream ss;
    ss << MovableObject::toString();
    ss << "Vie : " << m_life << endl;

    return ss.str();
}

//Fonction faisant perdre de la sante au joueur en fonction du type de
//projectile qu'il recoit
void Ship::loseHealth(Projectile * p)
{
    m_life-=p->getDamage();
}

void Ship::shoot()
{
}
//Fonction supprimant tous les projectiles que le vaisseau a tire
void Ship::deleteOutProjectile()
{
    for(auto p : m_projectile)
    {
        if(p->getX()>SCREEN_WIDTH)
        {
            m_projectile.erase(p);
            delete p;
        }
    }
}

void Ship::deleteProjectile(Projectile * p)
{
    m_projectile.erase(p);
    delete p;
}
//Fonction augmentant le type de projectile tire
void Ship::increaseProjectileType()
{
    m_projectileType++;
}

void Ship::resetProjectileType()
{
    m_projectileType=1;
}


