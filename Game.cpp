#include "Game.h"

void Game::init(std::string title, int x, int y)
{
    win.Create(sf::VideoMode(800, 600, 32), title);
    running = true;
    win.SetFramerateLimit(60);
    scene = new SceneManager;
    //ill do views later
    //v.SetCenter(1000, 1000);
    //v.SetHalfSize(400, 300);
    //v.Move(-900, -900);

}


void Game::draw()
{
    win.Clear();
    //win.SetView(v);
    //win.SetView(win.GetDefaultView());
    //Draw the interface
    scene->Update(win);
    win.Display();
}


void Game::update()
{
    if(!running) {return;}

    //do stuff, make this function feel needed.
}



Game Game::m_Game;
