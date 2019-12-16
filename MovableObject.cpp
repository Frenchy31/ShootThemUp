#include "MovableObject.hpp"

using namespace std;

// Constructeur(s)
MovableObject::MovableObject() : PositionObject() , m_dx(0), m_dy(1)
{

}

MovableObject::MovableObject (float x, float y, float dx, float dy ) : PositionObject(x,y) , m_dx(dx), m_dy(dy)
{

}

//Destructeur
MovableObject::~MovableObject ()
{
}

//Getters & Setters
void MovableObject::setDx ( float dx )
{
    m_dx = dx;
}

float MovableObject::getDx ()
{
    return m_dx;
}

void MovableObject::setDy ( float dy )
{
    m_dy = dy;
}

float MovableObject::getDy ()
{
    return m_dy;
}

//Méthodes
string MovableObject::toString()
{
    stringstream ss;
    ss << PositionObject::toString();
    ss << "Deplacement X :" << m_dx << endl;
    ss << "Deplacement y :" << m_dy << endl;
    return ss.str();
}
