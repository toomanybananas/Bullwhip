#ifndef BOXTRIGGERBODY_H
#define BOXTRIGGERBODY_H

#include "BoxDynamicBody.h"


class BoxTriggerBody : public BoxDynamicBody
{
    public:
        BoxTriggerBody();
        void Intialize(Def d, Entity* obj);
    protected:
    private:
};

#endif // BOXTRIGGERBODY_H
