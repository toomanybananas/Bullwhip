//Supposed to be the item pickup entity
//On my todo list
#ifndef ENT_ITEM_H
#define ENT_ITEM_H

#include "InvisPhysEntity.h"


class ent_item : public InvisPhysEntity
{
    public:
        ent_item();
        virtual void init();
        virtual void Draw(sf::RenderTarget& win) {win.draw(draw);};
    protected:
    private:
        typedef InvisPhysEntity super;
};

#endif // ENT_ITEM_H
