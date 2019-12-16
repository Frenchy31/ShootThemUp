#include <iostream>
#include "GameView.hpp"
#include "GameModel.hpp"

using namespace std;

int main()
{
    GameModel * model = new GameModel(SCREEN_WIDTH,SCREEN_HEIGHT);
    GameView * view = new GameView(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
    view->setModel(model);

    while(view->treatEvents())
    {
        view->draw();
        view->synchronize();
    }

    delete view;
    return EXIT_SUCCESS;
}
