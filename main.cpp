#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "ScriptedEntity.h"
#include "InfoBox.h"
#include "JMath.h"
#include "Constants.h"
#include "entites/phys_dynamic.h"
#include "Player.h"
//Version is 0.09

using namespace std;
int main()
{
    Game& gam = Game::Instance();
    gam.init("Bullwhip.Platformer", 800, 600); //Window title, width, height
    gam.GetScene()->Init(b2Vec2(0.f, 10.f));
    SceneManager* scene = gam.GetScene();

    scene->LoadScene("level.bin");


    Player player;
    Def pdef;
    pdef.SetVal("x", 100);
    pdef.SetVal("y", 100);
    pdef.SetString("image", "player.png");
    player.init(pdef);
    scene->AddEntity(player);


    while(gam.run())
    {
        const sf::Input& in = gam.getin();


        sf::Event event;


        //Handle events
        while(gam.gEvent(event))
        {
            if(event.Type == sf::Event::Closed)
                gam.Quit();
        }

        if(in.IsKeyDown(sf::Key::Up))
        {
            player.jump();
        }
        if(in.IsKeyDown(sf::Key::Right))
        {
            player.ApplyForce(Vec2(500, -100), Vec2(0, 0));
        }
        if(in.IsKeyDown(sf::Key::Left))
        {
            player.ApplyForce(Vec2(-500, -100), Vec2(0, 0));
        }
        if((!in.IsKeyDown(sf::Key::Right)) && (!in.IsKeyDown(sf::Key::Left)))
        {
            player.SetXVel(0);
        }
        gam.draw();
    }
    return 0;
}
