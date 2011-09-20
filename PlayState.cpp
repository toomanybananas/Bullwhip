#include "PlayState.h"

PlayState::PlayState()
{
    alive = false;
}

void PlayState::Init(sf::RenderWindow* win)
{
    if(alive)
    {
        return;
    }
    window = win;
    scene = new SceneManager;
    reg = new EntityRegistry;
    scene->SetReg(reg);
    //bullwhipini.LoadFile("Bullwhip.ini");


    scene->Init(b2Vec2(0.f, 10.f));
    reg->AddFactory("base_ent", &newEntity);
    reg->AddFactory("player", &newPlayer);
    reg->AddFactory("phys_static", &newPhys_static);
    reg->AddFactory("phys_dynamic", &newPhys_dynamic);
    reg->AddFactory("game_spawnpoint", &newGame_spawnpoint);
    reg->AddFactory("tele_coord", &newTele_coord);
    reg->AddFactory("tele_obj", &newTele_obj);
    reg->AddFactory("ent_string", &newEnt_string);
    reg->AddFactory("game_setglobal", &newGame_setglobal);

    //scene->LoadScene(bullwhipini.GetValue("Bullwhip", "level", NULL));
    scene->LoadScene("level.bin");

    player = reg->NewEnt("player");
    Def pdef;
    pdef.SetVal("x", 100);
    pdef.SetVal("y", 100);
    pdef.SetString("image", "player.png");
    player->init(pdef);
    //scene->Spawn(*player, bullwhipini.GetValue("Bullwhip", "spawnpoint", NULL));
    scene->Spawn(*player, "spawn_default");
    scene->SetEntity("center", player);
    alive = true;
}

std::string PlayState::Update()
{
    scene->Update(*window);
    return "";
}
