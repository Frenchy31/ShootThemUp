#ifndef GAMEVIEW_HPP_INCLUDED
#define GAMEVIEW_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include "GameModel.hpp"



//class GameModel;

class GameView
{

public:

    //CONSTRUCTOR
    GameView(int w, int h, int bpp);

    //DESTRUCTOR
    ~GameView();

    //MODEL SETTER
    void setModel(GameModel * model);

    //Fonctions insérant les images sur l'écran
    void draw();
    void drawMenu();
    void drawGame();
    void drawNextLevel();
    void drawLose();
    void drawWin();

    //Fonctions synchronisants la vue et le modèle
    void synchronize();
    void synchronizeGame();
    void synchronizeNextLevel();
    void synchronizeLose();
    void synchronizeWin();

    //Fonctions qui gèrent les évènements clavier
    void eventMenu(sf::Event const&event, bool &result);
    void eventGame(sf::Event const&event, bool &result);

    //Fonctions de traitement des évènements et de detection de la position de la souris
    bool mouseCollision(float cursorX, float cursorY, sf::Sprite const&s) const;
    bool treatEvents();

    void animateBackground();

private:

    //Attributs de resolution
    int _w, _h;

    //Attributs de position du fond dans le jeu
    int _pos_x_bg_1;
    int _pos_x_bg_2;

    //Booléens permettants de passer d'une fenêtre à l'autre
    bool _play;
    bool _menu;
    bool _lose;
    bool _won;
    bool _nextLevel;

    //Booléens permettant de savoir si on appuie sur certaines touches
    bool _isDown;
    bool _isUp;
    bool _isRight;
    bool _isLeft;
    bool _isShooting;

    //Modèle à gérer
    GameModel * _model;

    //Fenêtre
    sf::RenderWindow * _window;

    //Fonte
    sf::Font _Font;


    /*** MENU ***/
    sf::String _Tplay;
    sf::String _Tquit;

    sf::Image _Background;
    sf::Image _Boutons;

    sf::Sprite _Sbackground;
    sf::Sprite _SbutonPlay;
    sf::Sprite _SbutonQuit;


    /*** GAME ***/

    int _backgroundX = 0;

    sf::String _Thealth;
    sf::String _Tscore;
    sf::String _Tlevel;
    sf::String _Tnotif;
    sf::String _Tdefeat;
    sf::String _Twon;
    sf::String _TnextLevel;

    sf::Image _BackgroundGame;
    sf::Image _Player;
    sf::Image _Enemy;
    sf::Image _Projectile;
    sf::Image _Bonus;
    sf::Image _Miniature;
    sf::Image _Shield;

    sf::Sprite _Sshield;
    sf::Sprite _SminiLife;
    sf::Sprite _SminiBomb;
    sf::Sprite _SbackgroundGame;
    sf::Sprite _SbackgroundGame2;
    sf::Sprite _Splayer;
    sf::Sprite _Senemy;
    sf::Sprite _Sprojectile;
    sf::Sprite _Sbonus;

    sf::Clock m_clock;
    sf::Clock m_clockNotif;


};

#endif // GAMEVIEW_HPP_INCLUDED
