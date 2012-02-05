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
    render = new Gwen::Renderer::SFML(win);
    skin.SetRender(render);
    skin.Init("DefaultSkin.png");
    skin.SetDefaultFont(L"OpenSans.ttf", 11);
    canvas = new Gwen::Controls::Canvas(&skin);
    canvas->SetSize(800, 600);
    input.Initialize(canvas);
    //GUI_sprite.SetTexture(GUI.GetTexture());
    std::cout << "[core] initialzed GUI (GWEN)\n";
    Global.SetVal("run", true);
}


void Game::draw()
{
    win.Clear();
    state->Update();
    //win.SetView(win.GetDefaultView());
    sf::Event ev;
    while(win.PollEvent(ev))
    {
        if(ev.Type == sf::Event::Closed)
        {
            Global.SetVal("run", false);
        }
        input.ProcessMessage(ev);
    }
    canvas->RenderCanvas();
    //win.Draw(GUI_sprite);
    win.SetView(win.GetDefaultView());
    std::stringstream ss;
    ss <<  (1.f / win.GetFrameTime()) * 1000;
    fps.SetString(ss.str());
    win.Draw(fps);
    win.Display();
    //if(any_cast<bool>(Global.GetVal("run")) == false)
    if(Global.GetVal<bool>("run") == false)
    {
        running = false;
    }
}



