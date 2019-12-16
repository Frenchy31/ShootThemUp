#include "BonusProjectile.hpp"

using namespace std;
//CONSTRUCTOR
BonusProjectile::BonusProjectile():Bonus()
{}

BonusProjectile::BonusProjectile(float x, float y, float dx, float dy, string type):Bonus(x,y,dx,dy,type)
{}

//Fonction appelant increaseProjectileType de PlayerShip qui augmente le niveau de son tir de 1
void BonusProjectile::effect(PlayerShip* player)
{
    if(player->getProjectileType()<3)
        player->increaseProjectileType();
}
