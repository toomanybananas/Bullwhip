#include "Game.h"

void Game::init(std::string title, int x, int y)
{
    //std::cout << "LOADING SCREEN YO!\n";
    win.Create(sf::VideoMode(800, 600, 32), title);
    std::cout << "[core] initizalized screen\n";
    running = true;
    win.SetFramerateLimit(60);
    scene = new SceneManager;
    reg = new EntityRegistry;
    scene->SetReg(reg);
    fpsfont.LoadFromFile("slkscr.ttf");
    fps.SetFont(fpsfont);
    fps.SetSize(12);
    std::cout << "[core] fps counter loaded\n";
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



