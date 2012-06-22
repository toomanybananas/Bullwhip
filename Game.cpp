#include "Game.h"

void Game::init(std::string title, int x, int y)
{
    win.create(sf::VideoMode(800, 600, 32), title);
    std::cout << "[core] initialized screen\n";
    running = true;
    win.setFramerateLimit(60);
    state = new StateManager;
    state->Init(&win);
    fpsfont.loadFromFile("slkscr.ttf");
    fps.setFont(fpsfont);
    fps.setCharacterSize(8);
    std::cout << "[core] fps counter loaded\n";
    Global.SetVal("run", true);
}


void Game::draw()
{
    win.clear();
    state->Update();
    win.setView(win.getDefaultView());
    sf::Event ev;
    while(win.pollEvent(ev))
    {
        if(ev.type == sf::Event::Closed)
        {
            Global.SetVal("run", false);
        }
	if(ev.type == sf::Event::KeyPressed)
	{
		keys.push_back(ev.key.code);
	}
    }
    std::stringstream ss;
    ss <<  (1.f / counter.restart().asSeconds());
    fps.setString(ss.str());
    win.draw(fps);
    win.display();
    if(Global.GetVal<bool>("run") == false)
    {
        running = false;
    }
}



