#ifndef MOVABLEOBJECT_HPP_INCLUDED
#define MOVABLEOBJECT_HPP_INCLUDED

#include "PositionObject.h"

#include <string>

class MovableObject : public PositionObject
{
public:

    //Constructeurs & destructeur
    MovableObject();
    MovableObject (float x, float y, float dx, float dy );
    virtual ~MovableObject ( );

    // Accesseurs
    void setDx ( float dx );
    float getDx();
    void setDy ( float dy );
    float getDy ();

    // Méthode(s)
    virtual void move() = 0;
    std::string toString();

protected:

    float m_dx;
    float m_dy;

};
#endif // MOVABLEOBJECT_HPP_INCLUDED
