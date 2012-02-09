#include "Game.h"

void Game::init(std::string title, int x, int y)
{
    win.Create(sf::VideoMode(800, 600, 32), title);
    std::cout << "[core] initialized screen\n";
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
    sf::Event ev;
    while(win.PollEvent(ev))
    {
        if(ev.Type == sf::Event::Closed)
        {
            Global.SetVal("run", false);
        }
    }
    std::stringstream ss;
    ss <<  (1.f / counter.Restart().AsSeconds());
    fps.SetString(ss.str());
    win.Draw(fps);
    win.Display();
    if(Global.GetVal<bool>("run") == false)
    {
        running = false;
    }
}



