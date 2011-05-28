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
    play_btn = new cp::cpButton(win, &gui, "Play", 400, 300, 70, 30);
    exit_btn = new cp::cpButton(win, &gui, "Exit", 400, 400, 70, 30);
}

std::string MainMenuState::Update()
{
    sf::Event ev;
    while(window->GetEvent(ev))
    {
        gui.ProcessKeys(&ev);
    }
    const sf::Input& in = window->GetInput();
    if(play_btn->CheckState(&in) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
    {
        return "PlayState";
    }
    if(exit_btn->CheckState(&in) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
    {
        Global.SetVal("run", false);
    }
    play_btn->Draw();
    exit_btn->Draw();
    return "";
}
