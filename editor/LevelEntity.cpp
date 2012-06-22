#include "LevelEntity.h"

void LevelEntity::init()
{
	if(IsDefined("image") || IsDefined("asset"))
		Entity::init(); //assume that we are loading an image based entity
	else
	{
		//load it based on no image (c&p from invis entity
	}
};
