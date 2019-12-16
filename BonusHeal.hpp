#ifndef BONUSHEAL_HPP_INCLUDED
#define BONUSHEAL_HPP_INCLUDED
#include "Bonus.hpp"

/*** CLASSE BONUSHEAL***/
/* La classe BonusHeal est un bonus qui rend de  */
/*      40% de vie au joueur qui l'attrape       */

class BonusHeal : public Bonus
{
public :
    //CONSTRUCTORS
    BonusHeal();
    BonusHeal(float x, float y, float dx, float dy, std::string type);
    //FUNCTION
    virtual void effect(PlayerShip * player);

};

#endif // BONUSHEAL_HPP_INCLUDED
