#include "BonusHeal.hpp"

using namespace std;
//CONSTRUCTOR
BonusHeal::BonusHeal():Bonus()
{}

BonusHeal::BonusHeal(float x, float y, float dx, float dy, string type):Bonus(x,y,dx,dy,type)
{}

//Creation d'un entier heal qui contiendra 40% de la vie totale du joueur
//plus la vie restante du joueur. heal ne peut depasser la vie max du joueur
//On applique ensuite cet entier a la vie du joueur

void BonusHeal::effect(PlayerShip* player)
{

    player->resetHealth();

}
