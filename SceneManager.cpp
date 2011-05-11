#include "SceneManager.h"

SceneManager::SceneManager()
{
    //reg == NULL;
}

void SceneManager::AddEntity(Entity& ent)
{
    entites.insert(entites.end(), &ent);
    if(ent.GetAttribute("physics"))
    {
        PhysAdd(&ent);
    }
    std::cout << "[scene] added entity\n";
}

void SceneManager::AddEntity(Entity* ent)
{
    entites.insert(entites.end(), ent);
    if(ent->GetAttribute("physics"))
    {
        PhysAdd(ent);
    }
    std::cout << "[scene] added entity\n";
}

void SceneManager::Update(sf::RenderWindow& win)
{
    phys_world->Step(1.f / 60.f, 10, 10);
    phys_world->ClearForces();

    //Parse entites
    win.SetView(v);
    for(unsigned int i = 0; i < entites.size(); i++)
    {
        //Update entity
        entites[i]->update(win.GetInput());
        //win.Draw(entites[i]->getspr());
        entites[i]->Draw(win);
    }
    if(specents["center"] != NULL)
    {
        v.SetCenter(specents["center"]->GetX(), specents["center"]->GetY());
    }
}

void SceneManager::Init(b2Vec2 gravity)
{
    phys_world = new b2World(gravity, true);
    phys_world->SetContactListener(&bclisten);
    std::cout << "[scene][phys] intialized physics\n";
    v.SetHalfSize(400, 300);
    v.SetCenter(100, 100);
    std::cout << "[scene] set views\n";
}

void SceneManager::PhysAdd(Entity* obj)
{
    obj->reg(phys_world);
    std::cout << "[scene][phys] added physics entity" << std::endl;
}

void SceneManager::Spawn(Entity& plyr, std::string spawnpoint)
{
    AddEntity(plyr);
    plyr.SetX(spawnpoints[spawnpoint]->GetX());
    plyr.SetY(spawnpoints[spawnpoint]->GetY());
}

void SceneManager::LoadScene(std::string filename)
{
    sf::Clock time;
    inFile file;
    file.OpenFile(filename);
    //READ HEADER
    //INT: ENGINE VERSION
    if(file.ReadInt() != 1)
    {
        //error out
        std::cout << "[scene] [WARN] Incompatible map version!\n";
        return;
    }
    //std::cout << "version:" << file.ReadInt() << std::endl;
    //INT: GAME ID (not used yet)
    int gameID = file.ReadInt();
    //STRING: MAPNAME
    std::string mapname = file.ReadString();
    std::cout << "[scene] loading map:" << mapname << std::endl;
    //PROPERTY LIST: WORLD PROPERTY'S
    while(true)
    {
        //INT: TYPE
        int t = file.ReadInt();
        if(t == 0) //no type, end of list
        {
            break;
        }
        if(t == 1) //int
        {
            //STRING: NAME
            //INT: VALUE
            std::string h = file.ReadString();
            int i = file.ReadInt();
            worldprops.SetVal(h, i);
        }
        if(t == 2) //float
        {
            //STRING: NAME
            //FLOAT: VALUE
            std::string h = file.ReadString();
            float i = file.ReadFloat();
            worldprops.SetVal(h, i);
        }
        if(t == 3) //string
        {
            //STRING: NAME
            //string: VALUE
            std::string h = file.ReadString();
            std::string i = file.ReadString();
            worldprops.SetString(h, i);
        }
    }
    while(true)
    {
        std::string type = file.ReadString();
        if(type == "")
        {
            break;
        }
        Entity* newent = reg->NewEnt(type);
        Def pdef;
        while(true)
        {
            //INT: TYPE
            int t = file.ReadInt();
            if(t == 0) //no type, end of list
            {
                break;
            }
            if(t == 1) //int
            {
                //STRING: NAME
                //INT: VALUE
                std::string h = file.ReadString();
                int i = file.ReadInt();
                pdef.SetVal(h, i);
            }
            if(t == 2) //float
            {
                //STRING: NAME
                //FLOAT: VALUE
                std::string h = file.ReadString();
                float i = file.ReadFloat();
                pdef.SetVal(h, i);
            }
            if(t == 3) //string
            {
                //STRING: NAME
                //string: VALUE
                std::string h = file.ReadString();
                std::string i = file.ReadString();
                pdef.SetString(h, i);
            }
        }
        newent->init(pdef);
        AddEntity(newent);
        if(pdef.GetString("name") != "")
        {
            SetEntity(pdef.GetString("name"), newent);
        }
        if(type == "game_spawnpoint")
        {
            AddSpawn(newent, pdef.GetString("name"));
        }
    }
    file.Close();
    std::cout << "[scene] Level loading took:" << time.GetElapsedTime() << std::endl;
}
