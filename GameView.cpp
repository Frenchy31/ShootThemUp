#include "GameView.hpp"
#include <iostream>

using namespace std;

GameView::GameView(int w, int h, int bpp): _w(w), _h(h),_pos_x_bg_1(0),_pos_x_bg_2(SCREEN_WIDTH), _play(false), _menu(true), _lose(false), _won(false), _nextLevel(false)
{

    _window = new sf::RenderWindow(sf::VideoMode(w, h, bpp), "STUrfu", sf::Style::Close);
    _window->setFramerateLimit(60);

    if (!_Font.loadFromFile("fonts/arial.ttf"))
        cout << "Erreur : arial.ttf absent ou corrompu" << endl;

    if (!_Background.loadFromFile("img/background.png"))
        cout << "Erreur : background.png absent ou corrompu" << endl;

    if (!_Boutons.loadFromFile("img/boutons.png"))
        cout << "Erreur : boutons.png absent ou corrompu" << endl;

    if (!_BackgroundGame.loadFromFile("img/GameBackground.jpeg"))
        cout << "Erreur : GameBackground.jpeg absent ou corrompu" << endl;

    if(!_Player.loadFromFile("img/PlayerShip.png"))
        cout << "Erreur : PlayerShip.png absent ou corrompu" << endl;

    if(!_Projectile.loadFromFile("img/Projectile.png"))
        cout << "Erreur : Projectile.png absent ou corrompu" << endl;

    if(!_Enemy.loadFromFile("img/EnemyShip.png"))
        cout << "Erreur : EnemyShip.png absent ou corrompu" << endl;

    if(!_Bonus.loadFromFile("img/Bonus.png"))
        cout << "Erreur : Bonus.png absent ou corrompu" << endl;

    if(!_Miniature.loadFromFile("img/Miniatures.png"))
        cout << "Erreur : Miniatures.png absent ou corrompu" << endl;

    if(!_Shield.loadFromFile("img/Shield.png"))
        cout << "Erreur : Shield.png absent ou corrompu" << endl;



    _Sbackground.setTexture(_Background);
    _SbackgroundGame.setTexture(_BackgroundGame);
    _SbackgroundGame2.setTexture(_BackgroundGame);
      _SbackgroundGame2.setPosition(SCREEN_WIDTH,0);
    _SbutonPlay.setTexture(_Boutons);
    _SbutonQuit.setTexture(_Boutons);

    _Splayer.setTexture(_Player);
    _Senemy.setTexture(_Enemy);
    _Sprojectile.setTexture(_Projectile);
    _Sbonus.setTexture(_Bonus);
    _SminiLife.setTexture(_Miniature);
    _SminiBomb.setTexture(_Miniature);
    _Sshield.setTexture(_Shield);

    _SminiLife.setTextureRect(sf::IntRect(0,0,27,20));
    _SminiBomb.setTextureRect(sf::IntRect(0,23,27,24));

    _SbutonPlay.setTextureRect(sf::IntRect(0, 0, 200, 50));
    _SbutonPlay.setPosition(sf::Vector2f(300,250));

    _SbutonQuit.setTextureRect(sf::IntRect(0, 0, 200, 50));
    _SbutonQuit.setPosition(sf::Vector2f(300,350));

    _SbutonQuit.setTextureRect(sf::IntRect(0, 0, 200, 50));
    _SbutonQuit.setPosition(sf::Vector2f(300,350));

    _Tplay.setString("Jouer");
    _Tplay.setFont(_Font);
    _Tplay.setFillColor(sf::Color(80, 80, 80));
    _Tplay.setCharacterSize(28);
    _Tplay.setPosition(sf::Vector2f(365,255));

    _Tquit.setString("Quitter");
    _Tquit.setFont(_Font);
    _Tquit.setFillColor(sf::Color(80, 80, 80));
    _Tquit.setCharacterSize(28);
    _Tquit.setPosition(sf::Vector2f(360,355));

    _Thealth.setString("150/150");
    _Thealth.setFont(_Font);
    _Thealth.setFillColor(sf::Color(255,255,255));
    _Thealth.setCharacterSize(28);
    _Thealth.setPosition(sf::Vector2f(200,0));

    _Tscore.setString("0");
    _Tscore.setFont(_Font);
    _Tscore.setFillColor(sf::Color(255,255,255));
    _Tscore.setCharacterSize(28);
    _Tscore.setPosition(sf::Vector2f(400,0));

    _Tlevel.setString("Level : 1");
    _Tlevel.setFont(_Font);
    _Tlevel.setFillColor(sf::Color(255,255,255));
    _Tlevel.setCharacterSize(28);
    _Tlevel.setPosition(sf::Vector2f(600,0));

    _Tnotif.setString("");
    _Tnotif.setFont(_Font);
    _Tnotif.setFillColor(sf::Color(255,255,255));
    _Tnotif.setCharacterSize(28);
    _Tnotif.setPosition(sf::Vector2f(350,250));

    _Tdefeat.setString("GameOver");
    _Tdefeat.setFont(_Font);
    _Tdefeat.setFillColor(sf::Color(255,255,255));
    _Tdefeat.setCharacterSize(50);
    _Tdefeat.setPosition(sf::Vector2f(350,250));

    _Twon.setString("Victoire !");
    _Twon.setFont(_Font);
    _Twon.setFillColor(sf::Color(255,255,255));
    _Twon.setCharacterSize(50);
    _Twon.setPosition(sf::Vector2f(350,250));

    _TnextLevel.setString("Niveau suivant");
    _TnextLevel.setFont(_Font);
    _TnextLevel.setFillColor(sf::Color(255,255,255));
    _TnextLevel.setCharacterSize(50);
    _TnextLevel.setPosition(sf::Vector2f(350,250));


    _isDown = false;
    _isUp = false;
    _isRight = false;
    _isLeft = false;
    _isShooting = false;
}

GameView::~GameView()
{
    if(_window!= nullptr)
        delete _window;
}

void GameView::draw()
{
    _window->clear();

    if(_menu)
    {
        drawMenu();
    }
    else if(_play)
    {
        drawGame();
    }
    else if(_nextLevel)
    {
        drawNextLevel();
    }
    else if(_lose)
    {
        drawLose();
    }
    else if(_won)
    {
        drawWin();
    }

    _window->display();
}

void GameView::drawMenu()
{
    _window->draw(_Sbackground);
    _window->draw(_SbutonPlay);
    _window->draw(_SbutonQuit);
    _window->draw(_Tplay);
    _window->draw(_Tquit);
}

void GameView::drawGame()
{
    _window->draw(_SbackgroundGame);
    _window->draw(_SbackgroundGame2);
    _window->draw(_Thealth);
    _window->draw(_Tscore);
    _window->draw(_Tlevel);
    _window->draw(_Tnotif);

    for(int i=0; i < _model->getPlayerShip()->getLives(); i++)
    {
        _SminiLife.setPosition(sf::Vector2f(i*27,0));
        _window->draw(_SminiLife);
    }

    for(int i=0; i < _model->getPlayerShip()->getBombs(); i++)
    {
        _SminiBomb.setPosition(sf::Vector2f(i*30,30));
        _window->draw(_SminiBomb);
    }
    if(_model->getPlayerShip()->getShield()>=0 && _model->getPlayerShip()->getShield()<3)
    {
        _Sshield.setPosition(sf::Vector2f(_model->getPlayerShip()->getX()-50,_model->getPlayerShip()->getY()-50));
        _window->draw(_Sshield);
    }


    for (auto proj : _model->getPlayerShip()->getProjectile())
    {
        _Sprojectile.setPosition(sf::Vector2f(proj->getX(), proj->getY()));

        switch(proj->getType_projectile())
        {
        case 1 :
            _Sprojectile.setTextureRect(sf::IntRect(50,0,25,5));
            break;
        case 2 :
            _Sprojectile.setTextureRect(sf::IntRect(25,0,25,5));
            break;
        case 3 :
            _Sprojectile.setTextureRect(sf::IntRect(0,0,25,5));
            break;
        }
        _window->draw(_Sprojectile);
    }

    for (auto en : _model->getLevel()->getEnemyShip())
    {
        _Senemy.setPosition(sf::Vector2f(en->getX(),en->getY()));

        if (en->getType() == "easy")
            _Senemy.setTextureRect(sf::IntRect(0,0,72,72));
        else if (en->getType() == "medium")
            _Senemy.setTextureRect(sf::IntRect(0,72,72,72));
        else
            _Senemy.setTextureRect(sf::IntRect(0,144,72,72));

        _window->draw(_Senemy);

        for(auto proj : en->getProjectile())
        {
            _Sprojectile.setPosition(sf::Vector2f(proj->getX()-45, proj->getY()));

            switch(proj->getType_projectile())
            {
            case 1 :
                _Sprojectile.setTextureRect(sf::IntRect(50,0,25,5));
                break;
            case 2 :
                _Sprojectile.setTextureRect(sf::IntRect(25,0,25,5));
                break;
            case 3 :

                _Sprojectile.setTextureRect(sf::IntRect(0,0,25,5));
                break;
            }
            _window->draw(_Sprojectile);
        }
    }
    for(auto bonus : _model->getLevel()->getBonus() )
    {
        _Sbonus.setPosition(sf::Vector2f(bonus->getX(), bonus->getY()));

        if(bonus->getType() == "Heal")
            _Sbonus.setTextureRect(sf::IntRect(0,0,24,25));
        else if(bonus->getType() == "Bomb")
            _Sbonus.setTextureRect(sf::IntRect(0,25,24,25));
        else if(bonus->getType() == "Shield")
            _Sbonus.setTextureRect(sf::IntRect(0,50,24,25));
        else if(bonus->getType() == "Projectile")
            _Sbonus.setTextureRect(sf::IntRect(0,75,24,26));

        _window->draw(_Sbonus);
    }

    _window->draw(_Splayer);
}

void GameView::drawNextLevel()
{
    _window->clear();
    _window->draw(_TnextLevel);
    m_clockNotif.restart();
    while(m_clockNotif.getElapsedTime().asSeconds()<=1.5)
    {
        _window->display();
    }
}

void GameView::drawLose()
{
    _window->clear();
    _window->draw(_Tdefeat);
    m_clockNotif.restart();
    while(m_clockNotif.getElapsedTime().asSeconds()<=3)
    {
        _window->display();
    }
}

void GameView::drawWin()
{
    _window->clear();
    _window->draw(_Twon);
    m_clockNotif.restart();
    while(m_clockNotif.getElapsedTime().asSeconds()<=3)
    {
        _window->display();
    }
}

bool GameView::treatEvents()
{
    bool result = false;
    if(_window->isOpen())
    {
        result = true;
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                _window->close();
                result = false;
            }
            if(_menu)
                eventMenu(event,result);
            else
                eventGame(event,result);
        }

        if(_isUp)
        {
            _model->getPlayerShip()->move();
        }
        if(_isDown)
        {
            _model->getPlayerShip()->move();
        }
        if(_isRight)
        {
            _model->getPlayerShip()->move();
        }
        if(_isLeft)
        {
            _model->getPlayerShip()->move();
        }
        if(_isShooting)
        {
            if(m_clock.getElapsedTime().asSeconds() >= 0.2)
            {
                _model->getPlayerShip()->shoot();
                m_clock.restart();
            }
        }
    }
    return result;
}

void GameView::eventMenu(sf::Event const&event, bool &result)
{
    if(event.type == sf::Event::MouseMoved)
    {
        if(mouseCollision(event.mouseMove.x,event.mouseMove.y, _SbutonPlay))
            _SbutonPlay.setTextureRect(sf::IntRect(0, 50, 200, 50));
        else
            _SbutonPlay.setTextureRect(sf::IntRect(0, 0, 200, 50));

        if(mouseCollision(event.mouseMove.x,event.mouseMove.y, _SbutonQuit))
            _SbutonQuit.setTextureRect(sf::IntRect(0, 50, 200, 50));
        else
            _SbutonQuit.setTextureRect(sf::IntRect(0, 0, 200, 50));
    }

    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(mouseCollision(event.mouseButton.x,event.mouseButton.y, _SbutonQuit))
            result = false;

        if(mouseCollision(event.mouseButton.x,event.mouseButton.y, _SbutonPlay))
        {
            _menu = false ;
            _play = true;
        }
    }
}

void GameView::eventGame(sf::Event const&event, bool &result)
{

    if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
        case sf::Keyboard::Up :
            _isUp = true;
            _model->getPlayerShip()->setDy(-7);
            break;

        case sf::Keyboard::Down :
            _isDown = true;
            _model->getPlayerShip()->setDy(7);
            break;

        case sf::Keyboard::Right :
            _isRight = true;
            _model->getPlayerShip()->setDx(7);
            break;

        case sf::Keyboard::Left :
            _model->getPlayerShip()->setDx(-7);
            _isLeft = true;
            break;
        case sf::Keyboard::Space :
            _isShooting = true;
            break;
        case sf::Keyboard::RControl :
            if(m_clock.getElapsedTime().asSeconds()>=0.2)
            {
                _model->useBomb();
                m_clock.restart();
            }
            break;

        default :
            break;
        }
    }

    if(event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
        case sf::Keyboard::Up :
            _isUp = false;
            _model->getPlayerShip()->setDy(0);
            break;

        case sf::Keyboard::Down :
            _isDown = false;
            _model->getPlayerShip()->setDy(0);
            break;
        case sf::Keyboard::Right :
            _isRight = false;
            _model->getPlayerShip()->setDx(0);
            break;

        case sf::Keyboard::Left :
            _isLeft = false;
            _model->getPlayerShip()->setDx(0);
            break;
        case sf::Keyboard::Space :
            _isShooting = false;
            break;

        default :
            break;
        }
    }
}

bool GameView::mouseCollision(float cursorX, float cursorY, sf::Sprite const&s) const
{
    return s.getGlobalBounds().contains(cursorX, cursorY);
}

void GameView::setModel(GameModel * model)
{
    _model = model;
}

void GameView::synchronize()
{
    if(_play)
    {
        synchronizeGame();
    }
    else if(_nextLevel)
    {
        synchronizeNextLevel();
    }
    else if(_lose)
    {
        synchronizeLose();
    }
    else if(_won)
    {
        synchronizeWin();
    }
}

void GameView::synchronizeGame()
{
    _Splayer.setPosition(sf::Vector2f(_model->getPlayerShip()->getX() , _model->getPlayerShip()->getY()));
    _Thealth.setString(to_string(_model->getPlayerShip()->getLife())+ "/" + to_string(MAX_PLAYER_LIFE));
    _Tscore.setString(to_string(_model->getScorePlayer()));
    _Tlevel.setString("Level : " + to_string(_model->getLevel()->getLevelNumber()));
    if(_model->getHasLoseLife())
    {
        _Tnotif.setString("Vie perdue !");
        _model->setHasLoseLife(false);
        m_clockNotif.restart();
    }
    else
    {
        if(m_clockNotif.getElapsedTime().asSeconds() >= 1 )
            _Tnotif.setString("");
    }
    animateBackground();
    _model->setResult(true);
    _model->nextStep();
    _won = _model->getHasWon();
    _lose = _model->getHasLost();
    _nextLevel = _model->getToNextLevel();
    _play = _model->getResult();
    if(_model->getToNextLevel())
    {
        _play=false;

    }
}

void GameView::synchronizeLose()
{
    _menu=true;
    _model->setHasLost(false);
    _lose=_model->getHasLost();
    _model->reset();
}

void GameView::synchronizeNextLevel()
{
    _play=true;
    _model->setToNextLevel(false);
    _nextLevel=_model->getToNextLevel();
}

void GameView::synchronizeWin()
{
    _menu=true;
    _model->setHasWon(false);
    _won=_model->getHasWon();
    _model->reset();
}

void GameView::animateBackground()
{
    _pos_x_bg_1--;
    _pos_x_bg_2--;
    _SbackgroundGame.setPosition(_pos_x_bg_1,0);
    _SbackgroundGame2.setPosition(_pos_x_bg_2,0);

    if(_pos_x_bg_1 < -SCREEN_WIDTH)
    {
        _pos_x_bg_1 = SCREEN_WIDTH;
    }

    if(_pos_x_bg_2 < -SCREEN_WIDTH)
    {
        _pos_x_bg_2 = SCREEN_WIDTH;
    }

}
