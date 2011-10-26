#include "Game.h"

void Game::init(std::string title, int x, int y)
{
    win.Create(sf::VideoMode(800, 600, 32), title);
    std::cout << "[core] initizalized screen\n";
    running = true;
    win.SetFramerateLimit(60);
    state = new StateManager;
    state->Init(&win);
    fpsfont.LoadFromFile("slkscr.ttf");
    fps.SetFont(fpsfont);
    fps.SetCharacterSize(8);
    std::cout << "[core] fps counter loaded\n";
    Global.SetVal("run", true);
}


void Game::draw()
{
    win.Clear();
    state->Update();
    win.SetView(win.GetDefaultView());
    std::stringstream ss;
    ss <<  (1.f / win.GetFrameTime()) * 1000;
    fps.SetString(ss.str());
    win.Draw(fps);
    win.Display();
    if((bool)Global.GetVal("run") == false)
    {
        running = false;
    }
}



