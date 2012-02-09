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
    //play = new Gwen::Controls::Button(canvas);
    //play->SetBounds(400, 300, 70, 30);
    //play->SetText("Play");
}

std::string MainMenuState::Update()
{
    //if(play->IsDepressed())
    //{
        //canvas->AddDelayedDelete(play);
        //play = NULL;
        //return "PlayState";
    //}
    //if(exit_btn->CheckState(&in) == cp::CP_ST_MOUSE_LBUTTON_RELEASED)
    //{
        //Global.SetVal("run", false);
    //}
    return "";
}
