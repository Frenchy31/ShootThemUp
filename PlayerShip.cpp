#include "PlayerShip.hpp"


using namespace std;

// Constructeur(s)
PlayerShip::PlayerShip () : Ship(), m_lives(3), m_bombs(2)
{
}

PlayerShip::PlayerShip (float x, float y, float dx, float dy, int life, int projectileType )
    : Ship(x,y,dx,dy,life,projectileType) , m_lives(3), m_bombs(2), m_shield(-1)
{

}

// Destructeur
PlayerShip::~PlayerShip ()
{

}

//Accesseurs

int PlayerShip::getLives()
{
    return m_lives;
}

int PlayerShip::getShield()
{
    return m_shield;
}

int PlayerShip::getBombs()
{
    return m_bombs;
}
//Fonction inserant un Projectile dans le set de Projectile du joueur
void PlayerShip::shoot()
{
    m_projectile.insert(new Projectile(m_x +90,m_y + 35,10,0,m_projectileType));
}
//Fonction deplacant le joueur sur l'axe des ordonnees
void PlayerShip::move()
{
    m_x+=m_dx;
    m_y+=m_dy;

    if(m_x <0)
        m_x=0;
    if(m_x> SCREEN_WIDTH - WIDTH_PLAYERSHIP)
        m_x=SCREEN_WIDTH-WIDTH_PLAYERSHIP;
    if(m_y < 0)
        m_y =0;
    else if( m_y > SCREEN_HEIGHT-HEIGHT_PLAYERSHIP)
        m_y = SCREEN_HEIGHT-HEIGHT_PLAYERSHIP;
}

void PlayerShip::moveProjectile()
{
    for(auto proj : m_projectile)
    {
        proj->move();
    }
}

//Fonction retirant une vie au joueur
void PlayerShip::loseLife()
{
    resetProjectileType();
    m_lives--;
}

void PlayerShip::resetLives()
{
    m_lives = MAX_PLAYER_LIVES;
}

void PlayerShip::resetHealth()
{
    m_life = MAX_PLAYER_LIFE;
}
//Fonction retirant une bombe au joueur
void PlayerShip::useBomb()
{
    m_bombs--;
}
//Fonction ajoutant une bombe au joueur
void PlayerShip::recoverBomb()
{
    m_bombs++;
}
//Fonction activant le bouclier du joueur
void PlayerShip::activateShield()
{
    m_shield=0;
}

// Fonction qui gere le nom de bouclier que le joueur peut avoir durant le jeu
void PlayerShip::takeHitOnShield()
{
    m_shield++;
    if(m_shield>3)
        m_shield=-1;

}
//Fonction supprimant le bouclier au joueur
void PlayerShip::deleteShield()
{
    m_shield=false;
}
//ToString
string PlayerShip::toString()
{
    std::stringstream ss;
    ss << Ship::toString();

    return ss.str();
}

