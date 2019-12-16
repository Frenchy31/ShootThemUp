#include "PositionObject.h"

using namespace std;

// Constructeur(s)
PositionObject::PositionObject () : m_x(0) , m_y(0)
{

}

PositionObject::PositionObject (float x, float y) : m_x(x), m_y(y)
{

}

//Destructeur
PositionObject::~PositionObject ()
{
}

//Getters & SETTERS
void PositionObject::setX ( float x )
{
    m_x = x;
}

float PositionObject::getX()
{
    return m_x;
}

void PositionObject::setY ( float y )
{
    m_y = y;
}

float PositionObject::getY()
{
    return m_y;
}

string PositionObject::toString()
{
    stringstream ss;
    ss << "Pos X :" << m_x << endl;
    ss << "Pos y :" << m_y << endl;
    return ss.str();
}
