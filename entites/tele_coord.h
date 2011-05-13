#ifndef TELE_COORD_H
#define TELE_COORD_H
#include "InvisPhysEntity.h"

class tele_coord : public InvisPhysEntity
{
    public:
        tele_coord();
        virtual bool onCollision(Entity* obj);
    protected:
    private:
};

Entity* newTele_coord(int i);

#endif // TELE_COORD_H
