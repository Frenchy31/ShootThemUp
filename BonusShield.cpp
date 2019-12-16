#include "BonusShield.hpp"

using namespace std;

//CONSTRUCTOR
BonusShield::BonusShield():Bonus()
{}

BonusShield::BonusShield(float x, float y, float dx, float dy, string type):Bonus(x,y,dx,dy,type)
{}

//Fonction appelant activateShield de PlayerShip qui met un bouclier au joueur
void BonusShield::effect(PlayerShip * player)
{
    player->activateShield();
}
