#include "Level.hpp"

using namespace std;

//CONSTRUCTOR
Level::Level() : m_levelNumber(0),m_boss(nullptr)
{}

Level::Level(unsigned int levelNumber) : m_levelNumber(levelNumber)
{}
//DESTRUCTOR
Level::~Level()
{
    if(m_boss!=nullptr)
        delete m_boss;

    for(auto bonus : m_bonus)
    {
        m_bonus.erase(bonus);
        delete bonus;
    }

    for(auto enemy : m_enemyShip)
    {
        m_enemyShip.erase(enemy);
        delete enemy;
    }

}
//GETTERS
unsigned int Level::getLevelNumber() const
{
    return m_levelNumber;
}

set<EnemyShip*> Level::getEnemyShip() const
{
    return m_enemyShip;
}

Boss* Level::getBoss() const
{
    return m_boss;
}

set<Bonus*> Level::getBonus() const
{
    return m_bonus;
}
//SETTERS
void Level::setLevelNumber(unsigned int levelNumber)
{
    m_levelNumber=levelNumber;
}
void Level::setEnemyShip( set<EnemyShip*> enemies)
{
    m_enemyShip=enemies;
}
void Level::setBoss(Boss* boss)
{
    m_boss=boss;
}

// Modifie le déplacement des ennemis sur l'axe des ordonnées aléatoirement
void Level::setDyEnemy()
{
    srand(time(NULL));
    int var=0;
    for(auto enemy : m_enemyShip)
    {
        var=(rand()%2);
        if( var==1 )
            enemy->setDy(4);
        else
            enemy->setDy(-2);
    }
}

// Génère le niveau aléatoirement en début de partie

void Level::generateEnemies()
{
    srand(time(NULL));
    bool libre  = true;
    int y = 0;
    int enemySpawningType;
    //Algorithmes de génération d'ennemis
    if(m_levelNumber==1)
    {
        // On génère un nombre d'ennemis aléatoire avec des caractéristiques aléatoires
        while(m_enemyShip.size()<4 && libre)
        {
            y = (rand()%53)*10;
            enemySpawningType= rand()%5;
            // On vérifie que la position est libre
            for(auto en :m_enemyShip)
            {
                if(en->getY() == y )
                    libre = false;
            }

            if(libre)
            {

                if(enemySpawningType==4)
                {
                    createEnemy(rand() % 1000 + 900 ,y,DEFAULT_ENEMY_SPEED,0,MEDIUM_ENEMY_LIFE,MEDIUM_ENEMY_PROJECTILE,"medium");
                }
                else
                {
                    createEnemy(rand() % 1000 + 900,y,DEFAULT_ENEMY_SPEED,0,EASY_ENEMY_LIFE,EASY_ENEMY_PROJECTILE,"easy");
                }
            }
            libre = true;
        }
    }
    else if(m_levelNumber==2)
    {
        while(m_enemyShip.size()<4 && libre)
        {
            y = (rand()%20)*10;
            enemySpawningType= rand()%6;
            // On vérifie que la position est libre
            for(auto enemy :m_enemyShip)
            {
                if(enemy->getY() == y )
                    libre = false;
            }

            if(libre)
            {
                if(enemySpawningType==5)
                {
                    createEnemy(rand() % 1000 + 900, y, DEFAULT_ENEMY_SPEED, 0,HARD_ENEMY_LIFE,HARD_ENEMY_PROJECTILE, "hard");
                }
                else if(enemySpawningType==4 || enemySpawningType==3)
                {
                    createEnemy(rand() % 1000 + 900,y,DEFAULT_ENEMY_SPEED,0,MEDIUM_ENEMY_LIFE,MEDIUM_ENEMY_PROJECTILE,"medium");
                }
                else
                {
                    createEnemy(rand() % 1000 + 900,y,DEFAULT_ENEMY_SPEED,0,EASY_ENEMY_LIFE,EASY_ENEMY_PROJECTILE,"easy");
                }
            }
            libre = true;
        }

    }
    else if(m_levelNumber==3)
    {
        while(m_enemyShip.size()<4 && libre)
        {
            y = (rand()%20)*10;
            enemySpawningType= rand()%5;
            // On vérifie que la position est libre
            for(auto en :m_enemyShip)
            {
                if(en->getY() == y )
                    libre = false;
            }

            if(libre)
            {
                if(enemySpawningType==5)
                {
                    createEnemy(rand() % 1000 + 900, y, DEFAULT_ENEMY_SPEED, 0,EASY_ENEMY_LIFE,EASY_ENEMY_PROJECTILE, "easy");

                }
                else if(enemySpawningType==4 || enemySpawningType==3)
                {
                    createEnemy(rand() % 1000 + 900,y,DEFAULT_ENEMY_SPEED, 0,HARD_ENEMY_LIFE,HARD_ENEMY_PROJECTILE, "hard");

                }
                else
                {
                    createEnemy(rand() % 1000 + 900,y,DEFAULT_ENEMY_SPEED,0,MEDIUM_ENEMY_LIFE,MEDIUM_ENEMY_PROJECTILE,"medium");
                }
            }
            libre = true;
        }
    }
    else if(m_levelNumber>3)
    {
        while(m_enemyShip.size()<5 && libre)
        {
            y = (rand()%20)*10;
            enemySpawningType= rand()%4;
            // On vérifie que la position est libre
            for(auto en :m_enemyShip)
            {
                if(en->getY() == y )
                    libre = false;
            }
            if(libre)
            {
                    createEnemy(rand() % 1000 + 900,y,DEFAULT_ENEMY_SPEED, 0,HARD_ENEMY_LIFE,HARD_ENEMY_PROJECTILE, "hard");
            }
            libre = true;
        }
    }
}
//Fonction insérant des ennemis dans le set de EnemyShip
void Level::createEnemy(float x, float y, float dx, float dy, int life, int projectileType, string type)
{
    m_enemyShip.insert(new EnemyShip(x,y,dx,dy,life,projectileType,type));
}
//Fonction créant le boss du niveau
void Level::createBoss(float x, float y, float dx, float dy,int life, int projectileType)
{
    m_boss = new Boss(x,y,dx,dy, life, projectileType);
}
//Fonction déplacant tous les ennemis du niveau
void Level::moveEnemies()
{
    setDyEnemy();
    for(auto enemy : m_enemyShip)
    {
        enemy->move();
    }
}
// Fonction gerant de faire tirer les enemis qui sont sur la carte aleatoirement
void Level::makeEnemiesShoot()
{
    for(auto enemy : m_enemyShip)
    {
        if(rand()%3==1 && enemy->getX()<SCREEN_WIDTH)
            enemy->shoot();
    }
}

//Fonction deplacant tous les bonus du niveau
void Level::moveBonus()
{
    for(auto bonus : m_bonus)
    {
        bonus->move();
    }
}
//Fonction activant l'effet du bonus rammassé par le joueur
void Level::useBonus(PlayerShip * player)
{
    for(auto bonus : m_bonus)
    {
        if(bonus->getX() >= player->getX()
                && bonus->getX() <= player->getX() + 90
                && bonus->getY() >= player->getY()
                && bonus->getY() <= player->getY() + 71)
        {
            bonus->effect(player);
            m_bonus.erase(bonus);
            delete bonus;
        }
    }
}
//Fonction renvoyant vrai si un ennemi sort de l'ecran
bool Level::enemyExitMap()
{
    for(auto enemy : m_enemyShip)
        if(enemy->getX()<=-72)
            return true;
    return false;
}
//Fonction renvoyant vrai si un bonus sort de l'ecran
bool Level::bonusExitMap()
{
    for(auto bonus : m_bonus)
        if(bonus->getX()<=-78)
            return true;
    return false;
}

//Fonction supprimant les ennemis qui sortent de l'ecran
void Level::deleteOutEnemies()
{
    for(auto enemy : m_enemyShip)
    {
        if(enemy->getX()<=-72)
        {
            m_enemyShip.erase(enemy);
            delete enemy;
        }
    }
}
//Fonction supprimant les bonus qui sortent de l'ecran
void Level::deleteOutBonus()
{
    for(auto bonus : m_bonus)
    {
        if(bonus->getX()<=0)
        {
            m_bonus.erase(bonus);
            delete bonus;
        }
    }

}
//Fonction supprimant l'ennemi tué par le joueur
void Level::deleteKilledEnemy(EnemyShip* enemy)
{
    if(enemy->getLife()<=0)
    {
        dropBonus(enemy);
        m_enemyShip.erase(enemy);
        delete enemy;
    }

}
//Fonction supprimant tous les ennemis
void Level::deleteAllEnemies()
{
    for(auto enemy : m_enemyShip)
    {
        m_enemyShip.erase(enemy);
        delete enemy;
    }
}
//Fonction qui permet de detruire tous les bonus du niveau
void Level::deleteBonus()
{
    for(auto bonus : m_bonus)
    {
        m_bonus.erase(bonus);
        delete bonus;
    }
}
// Fonction qui relance le jeu et le remet a 0
void Level::reset()
{
    deleteBonus();
    deleteAllEnemies();
    m_levelNumber=1;
}
//Fonction retournant la somme des scores de tous les ennemis présents à l'écran
int Level::getAllEnemiesScore()
{
    int totalScore=0;
    for(auto enemy : m_enemyShip )
        totalScore+=enemy->getScoreValue();
    return totalScore;
}
//Fonction créant un bonus à l'endroit ou meurt l'ennemi
void Level::dropBonus(EnemyShip * enemy)
{
    int bonus = rand()%10;
    switch(bonus)
    {
    case 1 :
        m_bonus.insert(new BonusBomb(enemy->getX(),enemy->getY()+25, 7,0,"Bomb"));
        break;
    case 2 :
        m_bonus.insert(new BonusHeal(enemy->getX(), enemy->getY()+25, 7, 0, "Heal"));
        break;
    case 3 :
        m_bonus.insert(new BonusProjectile(enemy->getX(), enemy->getY()+25, 7, 0, "Projectile"));
        break;
    case 4 :
        m_bonus.insert(new BonusShield(enemy->getX(), enemy->getY()+25, 7, 0, "Shield"));
        break;
    default :
        break;
    }
}


