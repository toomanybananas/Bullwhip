#include "PlayState.h"
#include "Item.h"
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
    //

    componentreg.AddFactory("Position", &NewComp<Position>);
    componentreg.AddFactory("Graphical", &NewComp<Graphical>);
    componentreg.AddFactory("Physical", &NewComp<Physical>);
    componentreg.AddFactory("Moveable", &NewComp<Moveable>);
    componentreg.AddFactory("PlayerControlled", &NewComp<PlayerControlled>);


    scene->Init(Vec2(0.f, 1000.f));
    //scene->Init(Vec2(0.f, 0.f));
    /*reg->AddFactory("base_ent", &NewEnt<Entity>);
    reg->AddFactory("player", &NewEnt<Player>);
    reg->AddFactory("phys_static", &NewEnt<phys_static>);
    reg->AddFactory("phys_dynamic", &NewEnt<phys_dynamic>);
    reg->AddFactory("game_spawnpoint", &NewEnt<game_spawnpoint>);
    reg->AddFactory("tele_coord", &NewEnt<tele_coord>);
    reg->AddFactory("tele_obj", &NewEnt<tele_obj>);
    reg->AddFactory("ent_string", &NewEnt<ent_string>);
    reg->AddFactory("game_setglobal", &NewEnt<game_setglobal>);
    reg->AddFactory("ent_item", &NewEnt<ent_item>);*/
    //New factory format, using fancy initalizer lists
    std::vector<std::string> vis = {"Graphical"};
    std::vector<std::string> invis = {"Position"};
    std::vector<std::string> phys = {"Graphical", "Physical"};
    reg->AddFactory("base_ent", vis, 101);
    reg->AddFactory("player", {"Graphical", "Physical", "Moveable", "PlayerControlled"}, 100, "dynamic");
    reg->AddFactory("phys_static", phys, 100, "static");
    reg->AddFactory("phys_dynamic", phys, 100, "dynamic");
    reg->AddFactory("game_spawnpoint", invis);
    reg->AddFactory("ent_item", vis, 101);

    //scene->LoadScene(bullwhipini.GetValue("Bullwhip", "level", NULL));
    scene->LoadScenev1("level.bin");

    player = reg->NewEnt("player");
    //Def* pdef = new Def;
    player->SetVal("x", 100);
    player->SetVal("y", 100);
    player->SetVal("rotation", 0.0f);
    player->SetString("image", "player.png");
    player->init();
    //scene->Spawn(*player, bullwhipini.GetValue("Bullwhip", "spawnpoint", NULL));
    scene->Spawn(*player, "spawn_default");
    scene->SetEntity("center", player);
    tex.create(800, 600);
    renderspr.setTexture(tex.getTexture());
    renderspr.setPosition(0, 0);

    // A basic item
    Def item;
    item.SetString("name", "QSword");
    item.SetString("real_name", "Sword");
    Items.SetItem("QSword", item);

    alive = true;
}

std::string PlayState::Update()
{
    tex.clear();
    scene->Update(tex);
    tex.display();
    //scene->Update(*window);
    window->draw(renderspr);
    return "";
}
