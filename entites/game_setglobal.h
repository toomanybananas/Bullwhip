//Invisible entity that sets a global value when an entity passes over it
#include "InvisPhysEntity.h"
#include "../Constants.h"

class game_setglobal : public InvisPhysEntity
{
    public:
        game_setglobal();
        virtual void onCollision(Entity* obj);
    protected:
    private:
};
