#include "EnemyShip.hpp"

using namespace std;

// CONSTRUCTORS
EnemyShip::EnemyShip () : Ship(), m_type("")
{
    //On affiche une erreur si le type est invalide
    assert(m_type!="hard" || m_type!="medium" || m_type!="easy");

    //On initialise les attributs des ennemis en focntion de leur type
    if(m_type == "hard")
    {
        m_scoreValue = HARD_ENEMY_VALUE;
        m_life = HARD_ENEMY_LIFE;
        m_projectileType = HARD_ENEMY_PROJECTILE;
    }
    else if(m_type=="medium")
    {
        m_scoreValue = MEDIUM_ENEMY_VALUE;
        m_life = MEDIUM_ENEMY_LIFE;
        m_projectileType = MEDIUM_ENEMY_PROJECTILE;
    }

    else
    {
        m_type = "easy";
        m_scoreValue = EASY_ENEMY_VALUE;
        m_life = EASY_ENEMY_LIFE;
        m_projectileType = EASY_ENEMY_PROJECTILE;
    }
}

EnemyShip::EnemyShip (float x, float y, float dx, float dy, int life, int projectileType,string type)
    : Ship(x,y,dx,dy,life, projectileType) , m_type(type)
{
    //On affiche une erreur si le type est invalide
    assert(m_type!="hard" || m_type!="medium" || m_type!="easy");

    //On initialise les attributs des ennemis en focntion de leur type
    if(m_type == "hard")
    {
        m_scoreValue = HARD_ENEMY_VALUE;
        m_life = HARD_ENEMY_LIFE;
        m_projectileType = HARD_ENEMY_PROJECTILE;
    }
    else if(m_type=="medium")
    {
        m_scoreValue = MEDIUM_ENEMY_VALUE;
        m_life = MEDIUM_ENEMY_LIFE;
        m_projectileType = MEDIUM_ENEMY_PROJECTILE;
    }
    else if(m_type=="easy")
    {
        m_scoreValue = EASY_ENEMY_VALUE;
        m_life = EASY_ENEMY_LIFE;
        m_projectileType = EASY_ENEMY_PROJECTILE;
    }
}

// Destructeur
EnemyShip::~EnemyShip ( )
{
}

//Getters & Setters
void EnemyShip::setType (string type)
{
    assert(m_type!="hard" || m_type!="medium" || m_type!="easy");
    // On modifie l'ennemi en fonction du type mis en parametre
    m_type=type;
}

string EnemyShip::getType ()
{
    return m_type;
}

int EnemyShip::getScoreValue()
{
    return m_scoreValue;
}

//Méthodes

//On fait tirer des projectiles différents en fonction du type de l'ennemi
void EnemyShip::shoot()
{
    if (m_type == "hard")
        m_projectile.insert(new Projectile(m_x +20,m_y +30,-5,0,3));
    else if(m_type == "medium")
        m_projectile.insert(new Projectile(m_x +20, m_y +30, -5, 0, 2));
    else
        m_projectile.insert(new Projectile(m_x +20, m_y + 30, -5, 0, 1));
}

//Fonction deplacant l'ennemi
void EnemyShip::move()
{
    m_x-=m_dx;
    int moveEnemy=rand()%3;
    if( m_y>=0 && m_y<=528 && moveEnemy==0)
    {
        m_y+=m_dy;
    }

}
// Fonction deplacant les tirs des enemis
void EnemyShip::moveProjectile()
{
    for(auto proj : getProjectile())
    {
        proj->move();
    }
}

string EnemyShip::toString()
{
    std::stringstream ss;
    ss << Ship::toString();
    ss << "Type : " << m_type << endl;
    ss << "Valeur en pts : " << m_scoreValue << endl;

    return ss.str();
}

//Fonction loseLife faisant perdre de la vie a un EnemyShip
//La fonction recupere les degats qu'inflige le projectile mis en paramètre
void EnemyShip::loseLife(Projectile *p)
{
    m_life-=p->getDamage();
}
