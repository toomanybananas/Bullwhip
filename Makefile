CC=g++
CFLAGS=-c -Wall -Wextra
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lBox2D
SOURCES=Actor.cpp BullwhipContactListener.cpp Constants.cpp Definition.cpp Entity.cpp File.cpp Game.cpp ImageManager.cpp Item.cpp JMath.cpp MainMenuState.cpp PlayState.cpp Player.cpp SceneManager.cpp State.cpp StateManager.cpp Vec2.cpp main.cpp PhysicsWrappers/BoxDynamicBody.cpp PhysicsWrappers/BoxStaticBody.cpp PhysicsWrappers/BoxTriggerBody.cpp PhysicsWrappers/BoxWorld.cpp SimpleINI/ConvertUTF.c entites/InvisEntity.cpp entites/InvisPhysEntity.cpp entites/ent_item.cpp entites/ent_string.cpp entites/game_setglobal.cpp entites/game_spawnpoint.cpp entites/phys_dynamic.cpp entites/phys_static.cpp entites/tele_coord.cpp entites/tele_obj.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=bullwhip

all: $(SOURCES) $(EXEC)

$(EXEC) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
