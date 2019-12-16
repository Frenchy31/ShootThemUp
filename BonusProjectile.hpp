#ifndef BONUSPROJECTILE_HPP_INCLUDED
#define BONUSPROJECTILE_HPP_INCLUDED
#include "Bonus.hpp"

/*** CLASSE BONUSPROJECTILE ***/
/* La classe BonusProjectile est un bonus qui augmente */
/*        le niveau de tir du joueur qui l'attrape     */

class BonusProjectile : public Bonus
{
public :
    //CONSTRUCTORS
    BonusProjectile();
    BonusProjectile(float x, float y, float dx, float dy, std::string type);
    //FUNCTION
    virtual void effect(PlayerShip * player);

};

#endif // BONUSPROJECTILE_HPP_INCLUDED
