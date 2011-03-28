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
}

void SceneManager::Update(sf::RenderWindow& win)
{
    phys_world->Step(1.f / 60.f, 10, 10);
    phys_world->ClearForces();

    //Parse entites
    for(unsigned int i = 0; i < entites.size(); i++)
    {
        //Update entity
        entites[i]->update();
        win.Draw(entites[i]->getspr());
    }
}

void SceneManager::Init(b2Vec2 gravity)
{
    phys_world = new b2World(gravity, true);
    phys_world->SetContactListener(&bclisten);
}

void SceneManager::PhysAdd(Entity* obj)
{
    obj->reg(phys_world);
}

void SceneManager::LoadScene(std::string filename)
{
    std::ifstream file(filename.c_str(), std::ios::binary);
    int ents;
    file.read((char*)&ents, sizeof(int));
    for(int i = 0; i < ents; i++)
    {
        /*int length; //read ent name
        file.read((char*)&length, sizeof(int));
        for(int k = 0; k <= length; k++)
        {
            //read string
            //don't parse the string for now
        }*/
        //read x and y coords
        float x;
        float y;
        file.read((char*)&x, sizeof(float));
        file.read((char*)&y, sizeof(float));
        int imglength;
        file.read((char*)&imglength, sizeof(int));
        std::stringstream ss;
        for(int k = 0; k <= imglength; k++)
        {
            //read string
            char c;
            file.read((char*)&c, sizeof(char));
            ss << c;
        }
        std::string image = ss.str();
        phys_static* ent = new phys_static;
        Def edef;
        edef.SetVal("x", (int)x);
        edef.SetVal("y", (int)y);
        edef.SetString("image", image);
        ent->init(edef);
        entites.insert(entites.end(), ent);
        if(ent->GetAttribute("physics"))
        {
            PhysAdd(ent);
        }
    }
    file.close();
}
