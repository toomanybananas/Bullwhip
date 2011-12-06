//Supposed to be the item pickup entity
//On my todo list
#ifndef ENT_ITEM_H
#define ENT_ITEM_H

#include "phys_dynamic.h"


class ent_item : public phys_dynamic
{
    public:
        ent_item();
        bool onCollision(Entity* obj);
    protected:
    private:
        typedef phys_dynamic super;
};

#endif // ENT_ITEM_H
