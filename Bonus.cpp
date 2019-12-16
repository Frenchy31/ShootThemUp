#include "Bonus.hpp"

using namespace std;

//CONSTRUCTOR
Bonus::Bonus ():MovableObject()
{}

Bonus::Bonus(float x, float y, float dx, float dy, string type):MovableObject(x,y,dx,dy), m_type(type)
{}
//DESTRUCTOR
Bonus::~Bonus()
{}
//GETTERS
string Bonus::getType() const
{
    return m_type;
}
//Fonction virtuelle effect redéfinie plus bas dans la hiérarchie
void Bonus::effect(PlayerShip * player)
{}

//Fonction deplacant le bonus
void Bonus::move()
{
    m_x-=m_dx;
}
