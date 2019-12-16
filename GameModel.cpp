#include "GameModel.hpp"




using namespace std;

// Constructeur(s)
GameModel::GameModel() :_result(false) , _hasLoseLife(false),_hasWon(false), _hasLost(false) ,
     _toNextLevel(false), m_w(SCREEN_WIDTH), m_h(SCREEN_HEIGHT), m_limitScore(5000),m_scorePlayer(0), m_level(new Level(1)),m_playerShip( new PlayerShip(0,300-HEIGHT_PLAYERSHIP,0,0, MAX_PLAYER_LIFE,1))
{
}

GameModel::GameModel(int w, int h) :  _result(false) , _hasLoseLife(false), _hasWon(false), _hasLost(false) ,_toNextLevel(false),
    m_w(w), m_h(h) ,m_limitScore(5000),m_scorePlayer(0),m_level(new Level(1)), m_playerShip( new PlayerShip(0,300-HEIGHT_PLAYERSHIP,0,0, MAX_PLAYER_LIFE,1))
{

}
//Destructeur
GameModel::~GameModel()
{
    if(m_playerShip!=nullptr)
        delete m_playerShip;

    if(m_level!=nullptr)
        delete m_level;
}

// Getters & Setters
PlayerShip* GameModel::getPlayerShip()
{
    return m_playerShip;
}

int GameModel::getScorePlayer()
{
    return m_scorePlayer;
}

Level* GameModel::getLevel()
{
    return m_level;
}

bool GameModel::getHasWon()
{
    return _hasWon;
}

void GameModel::setHasWon(bool hasWon)
{
    _hasWon=hasWon;
}

bool GameModel::getHasLost()
{
    return _hasLost;
}

void GameModel::setHasLost(bool hasLost)
{
    _hasLost=hasLost;
}

bool GameModel::getToNextLevel()
{
    return _toNextLevel;
}

void GameModel::setToNextLevel(bool toNextLevel)
{
    _toNextLevel=toNextLevel;
}

bool GameModel::getResult()
{
    return _result;
}

void GameModel::setResult(bool result)
{
    _result = result;
}

bool GameModel::getHasLoseLife()
{
    return _hasLoseLife;
}

void GameModel::setHasLoseLife(bool hasloselife)
{
    _hasLoseLife = hasloselife ;
}



// Passe à la frame suivante
void GameModel::nextStep()
{
    srand(time(NULL));


    //On génère les ennemis
    m_level->generateEnemies();
    //On les fait bouger
    m_level->moveEnemies();
    //On les fait tirer
    firingEnemies();

    //On fait bouger les projectiles du joueur
    m_playerShip->moveProjectile();
    //On fait bouger les projectiles des ennemis
    for(auto en: m_level->getEnemyShip())
        en->moveProjectile();

    //On vérifie si un ennemi n'est pas touché
    enemyShootSuccess();
    //On vérifie si le joueur n'est pas touché
    playerHit();

    //On fait bouger les bonus
    m_level->moveBonus();
    //On vérifie si le joueur attrape un bonus
    m_level->useBonus(m_playerShip);



    //On supprime tous les projectiles du joueur en dehors de l'écran
    m_playerShip->deleteOutProjectile();
    //On teste si les ennemis et bonus sortent de l'écran
    bonusAndEnemiesExitMap();

    //On teste si on est en fin de jeu ou de niveau
    nextLevel();
    //On teste si on a gagné
    victory();
    //On teste si on a perdu
    defeat();

}

// Réinitialise la partie
void GameModel::reset()
{
    m_playerShip = new PlayerShip(0,300-HEIGHT_PLAYERSHIP,0,10, MAX_PLAYER_LIFE,1);
    m_scorePlayer = 0;
    m_level->reset();
}

// Fonction testant si on est en codition de fin de jeu
void GameModel::defeat()
{
    if(m_playerShip->getLives()<=0)
    {
        _hasLost = true;
        _result=false;
        reset();
    }
}
//Fonction qui permet de recuperer la position d'un enemi passe en parametre
bool GameModel::getEnemyPos(float &x, float &y, EnemyShip *enemy) const
{
    set<EnemyShip*>::iterator it;
    for(it=m_level->getEnemyShip().begin(); it!=m_level->getEnemyShip().end(); it++)
    {
        if(*it==enemy)
        {
            x=enemy->getX();
            y=enemy->getY();
            return true;
        }
    }
    return false;
}

// Si le playership touche un ennemi avec un de ses projectiles
void GameModel::enemyShootSuccess()
{
    for(auto enemy : m_level->getEnemyShip())
    {
        for(auto proj : m_playerShip->getProjectile())
        {
            if(proj->getX() >= enemy->getX()
                    && proj->getX() <= enemy->getX() + WIDTH_ENEMYSHIP
                    && proj->getY() >= enemy->getY()
                    && proj->getY() <= enemy->getY() + HEIGHT_ENEMYSHIP)
            {
                enemy->loseHealth(proj);
                if(enemy->getLife()<=0)
                {
                    m_scorePlayer+=enemy->getScoreValue();
                }
                m_playerShip->deleteProjectile(proj);
                m_level->deleteKilledEnemy(enemy);
            }
        }
    }
}
//Fonction qui gere les tirs enemis aleatoirement et sans qu'ils ne tirent tous en mem temps
void GameModel::firingEnemies()
{
    if(m_clock.GetElapsedTime() >= 0.3)
    {
        if(rand()%2 == 1)
            m_level->makeEnemiesShoot();

        m_clock.Reset();
    }
}
//Fonction gere le moment ou le joueur se fait toucher
void GameModel::playerHit()
{
    for(auto enemy : m_level->getEnemyShip())
    {
        for(auto proj : enemy->getProjectile())
        {
            if(proj->getX() >= m_playerShip->getX()
                    && proj->getX() <= m_playerShip->getX() + WIDTH_PLAYERSHIP
                    && proj->getY() >= m_playerShip->getY()
                    && proj->getY() <= m_playerShip->getY() + HEIGHT_PLAYERSHIP)
            {
                if(m_playerShip->getShield()>=0 && m_playerShip->getShield()<3)
                {
                    m_playerShip->takeHitOnShield();
                }
                else
                    m_playerShip->loseHealth(proj);

                enemy->deleteProjectile(proj);
                checkLife();
            }
        }
    }
}
//Fonction qui gere la destruction des enemis et des bonus qui sortent de la map
void GameModel::bonusAndEnemiesExitMap()
{
    if(m_level->enemyExitMap())
    {
        m_playerShip->loseLife();
        m_level->deleteOutEnemies();
        _hasLoseLife = true;
    }
    if(m_level->bonusExitMap())
    {
        m_level->deleteOutBonus();
    }
}

// Fonction qui gere le passage au niveau suivant
void GameModel::nextLevel()
{
    unsigned int next=m_level->getLevelNumber()+1;
    if(m_level->getLevelNumber()==1)
    {
        _toNextLevel=false;
        if(m_scorePlayer>=SCORE_TO_LEVEL_2)
        {
            m_level->setLevelNumber(next);
            m_level->deleteAllEnemies();
            m_level->deleteBonus();
            m_playerShip->resetHealth();
            m_playerShip->setX(0);
            m_playerShip->setY(300-HEIGHT_PLAYERSHIP);
            _toNextLevel=true;

        }
        cout << m_limitScore << endl;
    }
    else if(m_level->getLevelNumber()==2)
    {
        _toNextLevel=false;
        if(m_scorePlayer>=SCORE_TO_LEVEL_3)
        {
            m_level->setLevelNumber(next);
            m_level->deleteAllEnemies();
            m_level->deleteBonus();
            m_playerShip->resetHealth();
            m_playerShip->setX(0);
            m_playerShip->setY(300-HEIGHT_PLAYERSHIP);
            _toNextLevel=true;
        }
        cout << m_limitScore << endl;
    }
    else if(m_level->getLevelNumber()>=3)
    {
        _toNextLevel=false;
        cout << m_limitScore << endl;
        if(m_scorePlayer>=m_limitScore)
        {
            m_level->setLevelNumber(next);
            m_level->deleteAllEnemies();
            m_level->deleteBonus();
            m_playerShip->resetHealth();
            m_playerShip->setX(0);
            m_playerShip->setY(300-HEIGHT_PLAYERSHIP);
            m_limitScore+=SCORE_TO_NEXT;
            _toNextLevel=true;
        }
    }
}
// Fonction qui gere la victoire
void GameModel::victory()
{
    if(m_scorePlayer>=SCORE_TO_WIN)
    {
        _hasWon=true;
        _result = false;
    }
}
//Fonction qui verifie la vie de joueur
void GameModel::checkLife()
{
    if(m_playerShip->getLife()<=0)
    {
        m_playerShip->loseLife();
        m_playerShip->setLife(MAX_PLAYER_LIFE);
        _hasLoseLife = true;
    }
}
//Fonction qui utilise la bombe du joueur
void GameModel::useBomb()
{
    if(m_playerShip->getBombs()>0)
    {
        m_playerShip->useBomb();
        m_scorePlayer+=m_level->getAllEnemiesScore();
        m_level->deleteAllEnemies();
    }
}

