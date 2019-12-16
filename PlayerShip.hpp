#ifndef PLAYERSHIP_HPP_INCLUDED
#define PLAYERSHIP_HPP_INCLUDED

#include "Ship.hpp"
#include "Bonus.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

#define MAX_PLAYER_LIFE 250
#define MAX_PLAYER_LIVES 3
#define DEFAULT_PLAYER_PROJECTILE 1
#define HEIGHT_PLAYERSHIP 71
#define WIDTH_PLAYERSHIP 100



class PlayerShip : public Ship
{
public:

    //CONSTRUCTORS & DESTRUCTORS
    PlayerShip ();
    PlayerShip (float x, float y, float dx, float dy, int life, int projectileType);
    virtual ~PlayerShip ();

    //GETTERS & SETTERS
    int getLives();
    unsigned int getShootLevel();
    int getShield();
    int getBombs();

    //FUNCTIONS
    virtual void shoot();
    virtual void move();
    virtual void moveProjectile();
    std::string toString();
    void loseLife();
    void resetLives();
    void resetHealth();
    void useBomb();
    void recoverBomb();
    void activateShield();
    void takeHitOnShield();
    void deleteShield();

private:
    //ATTRIBUTES
    unsigned int m_shootLevel;
    int m_lives;
    int m_bombs;
    int m_shield;


};
#endif // PLAYERSHIP_HPP_INCLUDED
