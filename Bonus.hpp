#ifndef BONUS_HPP_INCLUDED
#define BONUS_HPP_INCLUDED

#include "MovableObject.hpp"
#include "PlayerShip.hpp"

#include <string>

/*** CLASSE BONUS ***/
/*   La classe bonus est une classe virtuelle pure   */
/* Attributs : type -> chaine de caractère permettant*/
/*                     de différencier les différents*/
/*                     bonus entre eux               */

class PlayerShip;

class Bonus : public MovableObject
{
protected :
    std::string m_type;

public:
    //CONSTRUCTORS
    Bonus ();
    Bonus (float x, float y, float dx, float dy, std::string type);
    //DESTRUCTOR
    virtual ~Bonus ();
    //GETTER
    std::string getType() const;
    //FUNCTIONS
    virtual void effect(PlayerShip * player)=0;
    void move();
};
#endif // BONUS_HPP_INCLUDED
