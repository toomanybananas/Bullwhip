#include "InvisPhysEntity.h"
#include "../Constants.h"

class game_setglobal : public InvisPhysEntity
{
    public:
        game_setglobal();
        virtual bool onCollision(Entity* obj);
    protected:
    private:
};

Entity* newGame_setglobal(int i);
