//Teleportation entity
//Teleports any teleportable entity inside it to another area.
#ifndef TELE_COORD_H
#define TELE_COORD_H
#include "InvisPhysEntity.h"

class tele_coord : public InvisPhysEntity
{
    public:
        tele_coord();
        virtual void onCollision(Entity* obj);
    protected:
    private:
};


#endif // TELE_COORD_H
