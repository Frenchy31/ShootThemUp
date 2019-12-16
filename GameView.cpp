#include "GameView.hpp"
#include <iostream>

using namespace std;

GameView::GameView(int w, int h, int bpp): _w(w), _h(h),_pos_x_bg_1(0),_pos_x_bg_2(SCREEN_WIDTH), _play(false), _menu(true), _lose(false), _won(false), _nextLevel(false)
{

    _window = new sf::RenderWindow(sf::VideoMode(w, h, bpp), "STUrfu", sf::Style::Close);
    _window->SetFramerateLimit(60);

    if (!_Font.LoadFromFile("fonts/arial.ttf"))
        cout << "Erreur : arial.ttf absent ou corrompu" << endl;

    if (!_Background.LoadFromFile("img/background.png"))
        cout << "Erreur : background.png absent ou corrompu" << endl;

    if (!_Boutons.LoadFromFile("img/boutons.png"))
        cout << "Erreur : boutons.png absent ou corrompu" << endl;

    if (!_BackgroundGame.LoadFromFile("img/GameBackground.jpeg"))
        cout << "Erreur : GameBackground.jpeg absent ou corrompu" << endl;

    if(!_Player.LoadFromFile("img/PlayerShip.png"))
        cout << "Erreur : PlayerShip.png absent ou corrompu" << endl;

    if(!_Projectile.LoadFromFile("img/Projectile.png"))
        cout << "Erreur : Projectile.png absent ou corrompu" << endl;

    if(!_Enemy.LoadFromFile("img/EnemyShip.png"))
        cout << "Erreur : EnemyShip.png absent ou corrompu" << endl;

    if(!_Bonus.LoadFromFile("img/Bonus.png"))
        cout << "Erreur : Bonus.png absent ou corrompu" << endl;

    if(!_Miniature.LoadFromFile("img/Miniatures.png"))
        cout << "Erreur : Miniatures.png absent ou corrompu" << endl;

    if(!_Shield.LoadFromFile("img/Shield.png"))
        cout << "Erreur : Shield.png absent ou corrompu" << endl;



    _Sbackground.SetImage(_Background);
    _SbackgroundGame.SetImage(_BackgroundGame);
    _SbackgroundGame2.SetImage(_BackgroundGame);
      _SbackgroundGame2.SetPosition(SCREEN_WIDTH,0);
    _SbutonPlay.SetImage(_Boutons);
    _SbutonQuit.SetImage(_Boutons);

    _Splayer.SetImage(_Player);
    _Senemy.SetImage(_Enemy);
    _Sprojectile.SetImage(_Projectile);
    _Sbonus.SetImage(_Bonus);
    _SminiLife.SetImage(_Miniature);
    _SminiBomb.SetImage(_Miniature);
    _Sshield.SetImage(_Shield);

    _SminiLife.SetSubRect(sf::IntRect(0,0,27,20));
    _SminiBomb.SetSubRect(sf::IntRect(0,23,27,47));

    _SbutonPlay.SetSubRect(sf::IntRect(0, 0, 200, 50));
    _SbutonPlay.SetPosition(sf::Vector2f(300,250));

    _SbutonQuit.SetSubRect(sf::IntRect(0, 0, 200, 50));
    _SbutonQuit.SetPosition(sf::Vector2f(300,350));

    _SbutonQuit.SetSubRect(sf::IntRect(0, 0, 200, 50));
    _SbutonQuit.SetPosition(sf::Vector2f(300,350));

    _Tplay.SetText("Jouer");
    _Tplay.SetFont(_Font);
    _Tplay.SetColor(sf::Color(80, 80, 80));
    _Tplay.SetSize(28);
    _Tplay.SetPosition(sf::Vector2f(365,255));

    _Tquit.SetText("Quitter");
    _Tquit.SetFont(_Font);
    _Tquit.SetColor(sf::Color(80, 80, 80));
    _Tquit.SetSize(28);
    _Tquit.SetPosition(sf::Vector2f(360,355));

    _Thealth.SetText("150/150");
    _Thealth.SetFont(_Font);
    _Thealth.SetColor(sf::Color(255,255,255));
    _Thealth.SetSize(28);
    _Thealth.SetPosition(sf::Vector2f(200,0));

    _Tscore.SetText("0");
    _Tscore.SetFont(_Font);
    _Tscore.SetColor(sf::Color(255,255,255));
    _Tscore.SetSize(28);
    _Tscore.SetPosition(sf::Vector2f(400,0));

    _Tlevel.SetText("Level : 1");
    _Tlevel.SetFont(_Font);
    _Tlevel.SetColor(sf::Color(255,255,255));
    _Tlevel.SetSize(28);
    _Tlevel.SetPosition(sf::Vector2f(600,0));

    _Tnotif.SetText("");
    _Tnotif.SetFont(_Font);
    _Tnotif.SetColor(sf::Color(255,255,255));
    _Tnotif.SetSize(28);
    _Tnotif.SetPosition(sf::Vector2f(350,250));

    _Tdefeat.SetText("GameOver");
    _Tdefeat.SetFont(_Font);
    _Tdefeat.SetColor(sf::Color(255,255,255));
    _Tdefeat.SetSize(50);
    _Tdefeat.SetPosition(sf::Vector2f(350,250));

    _Twon.SetText("Victoire !");
    _Twon.SetFont(_Font);
    _Twon.SetColor(sf::Color(255,255,255));
    _Twon.SetSize(50);
    _Twon.SetPosition(sf::Vector2f(350,250));

    _TnextLevel.SetText("Niveau suivant");
    _TnextLevel.SetFont(_Font);
    _TnextLevel.SetColor(sf::Color(255,255,255));
    _TnextLevel.SetSize(50);
    _TnextLevel.SetPosition(sf::Vector2f(350,250));


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
    _window->Clear();

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

    _window->Display();
}

void GameView::drawMenu()
{
    _window->Draw(_Sbackground);
    _window->Draw(_SbutonPlay);
    _window->Draw(_SbutonQuit);
    _window->Draw(_Tplay);
    _window->Draw(_Tquit);
}

void GameView::drawGame()
{
    _window->Draw(_SbackgroundGame);
    _window->Draw(_SbackgroundGame2);
    _window->Draw(_Thealth);
    _window->Draw(_Tscore);
    _window->Draw(_Tlevel);
    _window->Draw(_Tnotif);

    for(int i=0; i < _model->getPlayerShip()->getLives(); i++)
    {
        _SminiLife.SetPosition(sf::Vector2f(i*27,0));
        _window->Draw(_SminiLife);
    }

    for(int i=0; i < _model->getPlayerShip()->getBombs(); i++)
    {
        _SminiBomb.SetPosition(sf::Vector2f(i*30,30));
        _window->Draw(_SminiBomb);
    }
    if(_model->getPlayerShip()->getShield()>=0 && _model->getPlayerShip()->getShield()<3)
    {
        _Sshield.SetPosition(sf::Vector2f(_model->getPlayerShip()->getX()-50,_model->getPlayerShip()->getY()-50));
        _window->Draw(_Sshield);
    }


    for (auto proj : _model->getPlayerShip()->getProjectile())
    {
        _Sprojectile.SetPosition(sf::Vector2f(proj->getX(), proj->getY()));

        switch(proj->getType_projectile())
        {
        case 1 :
            _Sprojectile.SetSubRect(sf::IntRect(50,0,75,5));
            break;
        case 2 :
            _Sprojectile.SetSubRect(sf::IntRect(25,0,50,5));
            break;
        case 3 :
            _Sprojectile.SetSubRect(sf::IntRect(0,0,25,5));
            break;
        }
        _window->Draw(_Sprojectile);
    }

    for (auto en : _model->getLevel()->getEnemyShip())
    {
        _Senemy.SetPosition(sf::Vector2f(en->getX(),en->getY()));

        if (en->getType() == "easy")
            _Senemy.SetSubRect(sf::IntRect(0,0,72,72));
        else if (en->getType() == "medium")
            _Senemy.SetSubRect(sf::IntRect(0,72,72,144));
        else
            _Senemy.SetSubRect(sf::IntRect(0,144,72,216));

        _window->Draw(_Senemy);

        for(auto proj : en->getProjectile())
        {
            _Sprojectile.SetPosition(sf::Vector2f(proj->getX()-45, proj->getY()));

            switch(proj->getType_projectile())
            {
            case 1 :
                _Sprojectile.SetSubRect(sf::IntRect(50,0,75,5));
                break;
            case 2 :
                _Sprojectile.SetSubRect(sf::IntRect(25,0,50,5));
                break;
            case 3 :

                _Sprojectile.SetSubRect(sf::IntRect(0,0,25,5));
                break;
            }
            _window->Draw(_Sprojectile);
        }
    }
    for(auto bonus : _model->getLevel()->getBonus() )
    {
        _Sbonus.SetPosition(sf::Vector2f(bonus->getX(), bonus->getY()));

        if(bonus->getType() == "Heal")
            _Sbonus.SetSubRect(sf::IntRect(0,0,24,25.25));
        else if(bonus->getType() == "Bomb")
            _Sbonus.SetSubRect(sf::IntRect(0,25.25,24,50.5));
        else if(bonus->getType() == "Shield")
            _Sbonus.SetSubRect(sf::IntRect(0,50.5,24,75.75));
        else if(bonus->getType() == "Projectile")
            _Sbonus.SetSubRect(sf::IntRect(0,75.75,24,101));

        _window->Draw(_Sbonus);
    }

    _window->Draw(_Splayer);
}

void GameView::drawNextLevel()
{
    _window->Clear();
    _window->Draw(_TnextLevel);
    m_clockNotif.Reset();
    while(m_clockNotif.GetElapsedTime()<=1.5)
    {
        _window->Display();
    }
}

void GameView::drawLose()
{
    _window->Clear();
    _window->Draw(_Tdefeat);
    m_clockNotif.Reset();
    while(m_clockNotif.GetElapsedTime()<=3)
    {
        _window->Display();
    }
}

void GameView::drawWin()
{
    _window->Clear();
    _window->Draw(_Twon);
    m_clockNotif.Reset();
    while(m_clockNotif.GetElapsedTime()<=3)
    {
        _window->Display();
    }
}

bool GameView::treatEvents()
{
    bool result = false;
    if(_window->IsOpened())
    {
        result = true;
        sf::Event event;
        while (_window->GetEvent(event))
        {
            if(event.Type == sf::Event::KeyPressed)
            {
                if ((event.Type == sf::Event::Closed) ||
                        ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape)))
                {
                    _window->Close();
                    result = false;
                }
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
            if(m_clock.GetElapsedTime() >= 0.2)
            {
                _model->getPlayerShip()->shoot();
                m_clock.Reset();
            }
        }
    }
    return result;
}

void GameView::eventMenu(sf::Event const&event, bool &result)
{
    if(event.Type == sf::Event::MouseMoved)
    {
        if(mouseCollision(event.MouseMove.X,event.MouseMove.Y, _SbutonPlay))
            _SbutonPlay.SetSubRect(sf::IntRect(0, 50, 200, 100));
        else
            _SbutonPlay.SetSubRect(sf::IntRect(0, 0, 200, 50));

        if(mouseCollision(event.MouseMove.X,event.MouseMove.Y, _SbutonQuit))
            _SbutonQuit.SetSubRect(sf::IntRect(0, 50, 200, 100));
        else
            _SbutonQuit.SetSubRect(sf::IntRect(0, 0, 200, 50));
    }

    if(event.Type == sf::Event::MouseButtonPressed)
    {
        if(mouseCollision(event.MouseButton.X,event.MouseButton.Y, _SbutonQuit))
            result = false;

        if(mouseCollision(event.MouseButton.X,event.MouseButton.Y, _SbutonPlay))
        {
            _menu = false ;
            _play = true;
        }
    }
}

void GameView::eventGame(sf::Event const&event, bool &result)
{

    if(event.Type == sf::Event::KeyPressed)
    {
        switch(event.Key.Code)
        {
        case sf::Key::Up :
            _isUp = true;
            _model->getPlayerShip()->setDy(-7);
            break;

        case sf::Key::Down :
            _isDown = true;
            _model->getPlayerShip()->setDy(7);
            break;

        case sf::Key::Right :
            _isRight = true;
            _model->getPlayerShip()->setDx(7);
            break;

        case sf::Key::Left :
            _model->getPlayerShip()->setDx(-7);
            _isLeft = true;
            break;
        case sf::Key::Space :
            _isShooting = true;
            break;
        case sf::Key::RControl :
            if(m_clock.GetElapsedTime()>=0.2)
            {
                _model->useBomb();
                m_clock.Reset();
            }
            break;

        default :
            break;
        }
    }

    if(event.Type == sf::Event::KeyReleased)
    {
        switch(event.Key.Code)
        {
        case sf::Key::Up :
            _isUp = false;
            _model->getPlayerShip()->setDy(0);
            break;

        case sf::Key::Down :
            _isDown = false;
            _model->getPlayerShip()->setDy(0);
            break;
        case sf::Key::Right :
            _isRight = false;
            _model->getPlayerShip()->setDx(0);
            break;

        case sf::Key::Left :
            _isLeft = false;
            _model->getPlayerShip()->setDx(0);
            break;
        case sf::Key::Space :
            _isShooting = false;
            break;

        default :
            break;
        }
    }
}

bool GameView::mouseCollision(float cursorX, float cursorY, sf::Sprite const&s) const
{
    if (cursorX >= s.GetPosition().x
            && cursorX < s.GetPosition().y  + s.GetSize().x
            && cursorY >= s.GetPosition().y && cursorY < s.GetPosition().y + s.GetSize().y)
        return true;
    else
        return false;
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
    _Splayer.SetPosition(sf::Vector2f(_model->getPlayerShip()->getX() , _model->getPlayerShip()->getY()));
    _Thealth.SetText(to_string(_model->getPlayerShip()->getLife())+ "/" + to_string(MAX_PLAYER_LIFE));
    _Tscore.SetText(to_string(_model->getScorePlayer()));
    _Tlevel.SetText("Level : " + to_string(_model->getLevel()->getLevelNumber()));
    if(_model->getHasLoseLife())
    {
        _Tnotif.SetText("Vie perdue !");
        _model->setHasLoseLife(false);
        m_clockNotif.Reset();
    }
    else
    {
        if(m_clockNotif.GetElapsedTime() >= 1 )
            _Tnotif.SetText("");
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
    _SbackgroundGame.SetPosition(_pos_x_bg_1,0);
    _SbackgroundGame2.SetPosition(_pos_x_bg_2,0);

    if(_pos_x_bg_1 < -SCREEN_WIDTH)
    {
        _pos_x_bg_1 = SCREEN_WIDTH;
    }

    if(_pos_x_bg_2 < -SCREEN_WIDTH)
    {
        _pos_x_bg_2 = SCREEN_WIDTH;
    }

}
