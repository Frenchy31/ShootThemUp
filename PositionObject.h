#ifndef POSITIONOBJECT_H
#define POSITIONOBJECT_H

#include <string>
#include <sstream>

class PositionObject
{
public:

    // Constructeur(s) & destructeur
    PositionObject ();
    PositionObject (float x, float y);
    virtual ~PositionObject ( );

    // Accesseurs
    void setX ( float x );
    float getX();
    void setY ( float y );
    float getY ();

    //Méthode(s)
    std::string toString();

protected:

    float m_x;
    float m_y;

};

#endif // POSITIONOBJECT_H
