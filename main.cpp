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
    Game gam;
    gam.init("Bullwhip.Default", 800, 600); //Window title, width, height
    gam.GetScene()->Init(b2Vec2(0.f, 10.f));
    SceneManager* scene = gam.GetScene();
    EntityRegistry* reg = gam.GetRegistry();
    reg->AddFactory("base_ent", &newEntity);
    reg->AddFactory("player", &newPlayer);
    reg->AddFactory("phys_static", &newPhys_static);
    reg->AddFactory("phys_dynamic", &newPhys_dynamic);

    scene->LoadScene("level.bin"); //new format coming soon

    /*Entity* platform = reg->NewEnt("phys_static");
    Def p;
    p.SetVal("x", 300);
    p.SetVal("y", 500);
    p.SetString("image", "platform.png");
    platform->init(p);
    scene->AddEntity(platform);*/


    Entity* player = reg->NewEnt("player");
    Def pdef;
    pdef.SetVal("x", 100);
    pdef.SetVal("y", 100);
    pdef.SetString("image", "player.png");
    player->init(pdef);
    scene->AddEntity(player);
    scene->SetEntity("center", player);


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
        gam.draw();
    }
    return 0;
}
