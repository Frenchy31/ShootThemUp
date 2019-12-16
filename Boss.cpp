#include "Boss.hpp"



/****   CLASSE INUTILE   ****/
using namespace std;

Boss::Boss ()
{
}

Boss::Boss(float x,float y,float dx,float dy, int life, int projectileType): Ship(x,y,dx,dy,life,projectileType)
{
    m_life=BOSS_LIFE;
}

Boss::~Boss ()
{
}

void Boss::shoot()
{
    m_projectile.insert(new Projectile(m_x,m_y+10,0,0,1));
    m_projectile.insert(new Projectile(m_x,m_y,0,0,1));
    m_projectile.insert(new Projectile(m_x,m_y-10,0,0,1));
    cout << "Tirs du Boss : ";
    for(auto p : m_projectile)
    {
        cout << "{" << p->getX() << "," << p->getY() << "} ";
    }
    cout << endl;
}

void Boss::move()
{}

void Boss::moveProjectile()
{

}
