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
    super::Init(win);
    scene = new SceneManager;
    reg = new EntityRegistry;
    scene->SetReg(reg);
    //bullwhipini.LoadFile("Bullwhip.ini");


    scene->Init(Vec2(0.f, 1000.f));
    reg->AddFactory("base_ent", &NewEnt<Entity>);
    reg->AddFactory("player", &NewEnt<Player>);
    reg->AddFactory("phys_static", &NewEnt<phys_static>);
    reg->AddFactory("phys_dynamic", &NewEnt<phys_dynamic>);
    reg->AddFactory("game_spawnpoint", &NewEnt<game_spawnpoint>);
    reg->AddFactory("tele_coord", &NewEnt<tele_coord>);
    reg->AddFactory("tele_obj", &NewEnt<tele_obj>);
    reg->AddFactory("ent_string", &NewEnt<ent_string>);
    reg->AddFactory("game_setglobal", &NewEnt<game_setglobal>);
    reg->AddFactory("ent_item", &NewEnt<ent_item>);

    //scene->LoadScene(bullwhipini.GetValue("Bullwhip", "level", NULL));
    scene->LoadScene("level.bin");

    player = reg->NewEnt("player");
    Def pdef;
    pdef.SetVal("x", 100);
    pdef.SetVal("y", 100);
    pdef.SetVal("rotation", 0.0f);
    pdef.SetString("image", "player.png");
    player->init(pdef);
    //scene->Spawn(*player, bullwhipini.GetValue("Bullwhip", "spawnpoint", NULL));
    scene->Spawn(*player, "spawn_default");
    scene->SetEntity("center", player);
    tex.Create(800, 600);
    renderspr.SetTexture(tex.GetTexture());
    renderspr.SetPosition(0, 0);

    // A basic item
    Def item;
    item.SetString("name", "QSword");
    item.SetString("real_name", "Sword");
    Items.SetItem("QSword", item);

    alive = true;
}

std::string PlayState::Update()
{
    tex.Clear();
    scene->Update(tex);
    tex.Display();
    //scene->Update(*window);
    window->Draw(renderspr);
    return "";
}
