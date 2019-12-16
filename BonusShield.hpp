#ifndef BONUSSHIELD_HPP_INCLUDED
#define BONUSSHIELD_HPP_INCLUDED
#include "Bonus.hpp"

/*** CLASSE BONUSSHIELD ***/
/* La classe BonusShield est un bonus qui donne un */
/*        bouclier au joueur qui l'attrape         */

class BonusShield : public Bonus
{
public :
    //CONSTRUCTORS
    BonusShield();
    BonusShield(float x, float y, float dx, float dy, std::string type);
    //FUNCTION
    void effect(PlayerShip * player);

};

#endif // BONUSSHIELD_HPP_INCLUDED
