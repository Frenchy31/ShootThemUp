#include "BonusBomb.hpp"

using namespace std;
//CONSTRUCTOR
BonusBomb::BonusBomb():Bonus()
{}

BonusBomb::BonusBomb(float x, float y, float dx, float dy, string type):Bonus(x,y,dx,dy, type)
{}

//Appel de la fonction recoverBomb de PlayerShip qui donne une bombe au joueur
void BonusBomb::effect(PlayerShip * player)
{
    player->recoverBomb();
}
