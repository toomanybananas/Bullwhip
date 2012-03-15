#ifndef BOXDYNAMICBODY_H
#define BOXDYNAMICBODY_H
#include "BoxStaticBody.h"

class BoxDynamicBody : public BoxStaticBody
{
    public:
        BoxDynamicBody();
        void Intialize(Entity* obj);
    protected:
        b2FixtureDef fix_def;
        b2Fixture* fix;
    private:
};

#endif // BOXDYNAMICBODY_H
