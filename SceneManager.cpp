#include "SceneManager.h"

SceneManager::SceneManager()
{
    //ctor
}

void SceneManager::AddEntity(Entity& ent)
{
    entites.insert(entites.end(), &ent);
    if(ent.GetAttribute("physics"))
    {
        PhysAdd(&ent);
    }
    prtDbg("[scene] added entity");
}

void SceneManager::AddEntity(Entity* ent)
{
    entites.insert(entites.end(), ent);
    if(ent->GetAttribute("physics"))
    {
        PhysAdd(ent);
    }
    prtDbg("[scene] added entity");
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
        win.Draw(entites[i]->getspr());
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
    prtDbg("[scene][phys] intialized physics");
    v.SetHalfSize(400, 300);
    v.SetCenter(100, 100);
    prtDbg("[scene] set views");
}

void SceneManager::PhysAdd(Entity* obj)
{
    obj->reg(phys_world);
    std::cout << "[scene][phys] added physics entity" << std::endl;
}

void SceneManager::LoadScene(std::string filename)
{
    std::cout << "[scene] attempted to call an unfinished function\n";
    return; //not done yet
    inFile file;
    file.OpenFile(filename);
    //READ HEADER
    //INT: ENGINE VERSION
    if(file.ReadInt() != 1)
    {
        //error out
        std::cout << "Incompatible map version\n";
        return;
    }
    //INT: GAME ID (not used yet)
    int gameID = file.ReadInt();
    //STRING: MAPNAME
    std::string mapname = file.ReadString();
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
            worldprops.SetVal(file.ReadString(), file.ReadInt());
        }
        if(t == 2) //float
        {
            //STRING: NAME
            //FLOAT: VALUE
            worldprops.SetVal(file.ReadString(), file.ReadFloat());
        }
        if(t == 3) //string
        {
            //STRING: NAME
            //string: VALUE
            worldprops.SetString(file.ReadString(), file.ReadString());
        }
    }
    //INT: ENTS TO READ
    int entcount = file.ReadInt();
    file.Close();
}
