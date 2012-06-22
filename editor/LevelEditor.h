#pragma once
#include "../SceneManager.h"
#include "LevelEntity.h"
#include "../Definition.h"


class LevelEditor : public SceneManager
{
	public:
		virtual void Init(Vec2 gravity);
		virtual void Update(sf::RenderTarget& win);
		virtual void Save(std::string filename);
		virtual void LoadScene(std::string filename);
};
