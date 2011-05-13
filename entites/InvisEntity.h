#ifndef INVISENTITY_H
#define INVISENTITY_H
#include "../Entity.h"


class InvisEntity : public Entity
{
    public:
        InvisEntity();
        virtual void Draw(sf::RenderWindow& win) {};
        virtual void init(Def def);
    protected:
    private:
};

#endif // INVISENTITY_H
