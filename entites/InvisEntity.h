//Simple invisible entity, no collisions, absoultely nothing

//Not entirely useless, can use it as a marker for teleport destinations
#ifndef INVISENTITY_H
#define INVISENTITY_H
#include "../Entity.h"


class InvisEntity : public Entity
{
    public:
        InvisEntity();
        virtual void Draw(sf::RenderTarget& win) {};
        virtual void init(Def def);
    protected:
    private:
        typedef Entity super;
};

#endif // INVISENTITY_H
