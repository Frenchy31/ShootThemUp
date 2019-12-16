#ifndef BONUSBOMB_HPP_INCLUDED
#define BONUSBOMB_HPP_INCLUDED
#include "Bonus.hpp"

/*** CLASSE BONUSBOMB ***/
/* La classe BonusBomb est un bonus qui rend une */
/*        bombe au joueur qui l'attrape          */

class BonusBomb : public Bonus
{
public :
    //CONSTRUCTORS
    BonusBomb();
    BonusBomb(float x, float y, float dx, float dy, std::string type);
    //FUNCTION
    virtual void effect(PlayerShip * player);

};

#endif // BONUSBOMB_HPP_INCLUDED
