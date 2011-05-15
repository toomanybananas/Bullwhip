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
#include "entites/game_spawnpoint.h"
#include "entites/tele_coord.h"
#include "entites/tele_obj.h"
#include "SimpleINI/SimpleIni.h"
//Version is 0.09

using namespace std;
int main()
{
    CSimpleIni bullwhipini;
    bullwhipini.LoadFile("Bullwhip.ini");
    Game gam;
    gam.init("Bullwhip.Default", 800, 600); //Window title, width, height
    gam.GetScene()->Init(b2Vec2(0.f, 10.f));
    SceneManager* scene = gam.GetScene();
    EntityRegistry* reg = gam.GetRegistry();
    reg->AddFactory("base_ent", &newEntity);
    reg->AddFactory("player", &newPlayer);
    reg->AddFactory("phys_static", &newPhys_static);
    reg->AddFactory("phys_dynamic", &newPhys_dynamic);
    reg->AddFactory("game_spawnpoint", &newGame_spawnpoint);
    reg->AddFactory("tele_coord", &newTele_coord);
    reg->AddFactory("tele_obj", &newTele_obj);

    scene->LoadScene(bullwhipini.GetValue("Bullwhip", "level", NULL));

    Entity* player = reg->NewEnt("player");
    Def pdef;
    pdef.SetVal("x", 100);
    pdef.SetVal("y", 100);
    pdef.SetString("image", "player.png");
    player->init(pdef);
    scene->Spawn(*player, bullwhipini.GetValue("Bullwhip", "spawnpoint", NULL));
    scene->SetEntity("center", player);


    while(gam.run())
    {
        const sf::Input& in = gam.getin();

        sf::Event event;

        while(gam.gEvent(event))
        {
            if(event.Type == sf::Event::Closed)
                gam.Quit();
        }
        gam.draw();
    }
    return 0;
}
