//Best entity ever
//A default physics object
//Nothing special, just a box that can bounce around
#ifndef PHYS_DYNAMIC_H
#define PHYS_DYNAMIC_H

#include "phys_static.h"


class phys_dynamic : public phys_static
{
    public:
        phys_dynamic();
        virtual void init(Def def);
        //virtual void Destroy();
    protected:
    private:
        typedef phys_static super;
};

#endif // PHYS_DYNAMIC_H
