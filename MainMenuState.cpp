#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
    //ctor
    alive = false;
}

void MainMenuState::Init(sf::RenderWindow* win)
{
    if(alive)
    {
        return;
    }
    window = win;
    /*render = new Gwen::Renderer::SFML(*win);
    skin.SetRender(render);
    skin.Init("DefaultSkin.png");
    skin.SetDefaultFont(L"OpenSans.ttf", 11);
    canvas2 = new Gwen::Controls::Canvas(&skin);
    canvas2->SetSize(800, 600);
    input.Initialize(canvas2);*/
    play = new Gwen::Controls::Button(canvas);
    play->SetBounds(400, 300, 70, 30);
    play->SetText("Play");
}

std::string MainMenuState::Update()
{
    /*sf::Event ev;
    while(window->PollEvent(ev))
    {
        if(ev.Type == sf::Event::Closed)
        {
            Global.SetVal("run", false);
        }
        input.ProcessMessage(ev);
    }*/
    //const sf::Input& in = window->GetInput();
    if(play->IsDepressed())
    {
        std::cout << "D\n";
        canvas->AddDelayedDelete(play);
        play = NULL;
        return "PlayState";
    }
    //if(exit_btn->CheckState(&in) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
    //{
        //Global.SetVal("run", false);
    //}*/
    //canvas2->RenderCanvas();
    return "";
}
