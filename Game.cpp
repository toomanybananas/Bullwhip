#include "Game.h"

void Game::init(std::string title, int x, int y)
{
    win.Create(sf::VideoMode(800, 600, 32), title);
    prtDbg("[core] initizalized screen");
    running = true;
    win.SetFramerateLimit(60);
    scene = new SceneManager;
    reg = new EntityRegistry;
    fpsfont.LoadFromFile("slkscr.ttf");
    fps.SetFont(fpsfont);
    fps.SetSize(12);
    prtDbg("[core] fps counter loaded");
    //ill do views later
    //v.SetCenter(1000, 1000);
    //v.Move(-900, -900);

}


void Game::draw()
{
    win.Clear();
    scene->Update(win);
    win.SetView(win.GetDefaultView());
    //Draw the interface
    std::stringstream ss;
    ss <<  1.f / win.GetFrameTime();
    fps.SetText(ss.str());
    win.Draw(fps);
    win.Display();
}



Game Game::m_Game;
