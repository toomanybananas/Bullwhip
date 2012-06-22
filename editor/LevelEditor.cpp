#include "LevelEditor.h"



void LevelEditor::Init(Vec2 gravity)
{
	//set up a basic enviorment, not much to do
}


void LevelEditor::Update(sf::RenderTarget& win)
{
	//read keybindings, draw entites, open menus
	v.setSize(800, 600);
	v.setCenter(400, 300);
}

void LevelEditor::LoadScene(std::string filename)
{
	std::cout << "[leveledit] Loading level " << filename << std::endl;
	inFile file;
	file.OpenFile(filename);
	if(file.ReadInt() != 2)
	{
		std::cout << "[leveledit] [ERROR] Incompatible map version!" << std::endl;
	}
	Def level;
	level.Load(file);
	std::string mapname;
	if(level.IsDefined("name"))
		mapname = level.GetVal<std::string>("name");
	int count = level.GetVal<int>("entcount");
	for(int i = 0; i < count; i++)
	{
		std::stringstream ss;
		ss << count;
		Def d = level.GetVal<Def>(ss.str());
		std::string type = d.GetVal<std::string>("type");
		Entity* ent = new LevelEntity;
		ent->Copy(d);
		ent->init();
		AddEntity(ent);
		if(ent->IsDefined("name"))
		{
			SetEntity(ent->GetVal<std::string>("name"), ent);
		}
		if(type == "game_spawnpoint")
		{
			AddSpawn(ent, ent->GetVal<std::string>("name"));
		}
			
	}
	file.Close();
	std::cout << "[leveledit] Level loaded\n";
}

void LevelEditor::Save(std::string filename)
{
	outFile file;
	file.OpenFile(filename);
	file.WriteInt(2);
	std::cout << "[leveledit] Saving level to file " << filename << std::endl;
	Def level;
	level.SetVal("entcount", (int)entites.size());
	//set the mapname TODO
	for(int i = 0; i < entites.size(); i++)
	{
		Def d;
		d.Copy(*entites[i]);
		std::stringstream ss;
		ss << i;
		level.SetVal(ss.str(), d);
	}
	file.Close();
}
