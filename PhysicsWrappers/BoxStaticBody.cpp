#include "BoxStaticBody.h"
#include "../Constants.h"
BoxStaticBody::BoxStaticBody()
{
    //ctor
    type = BODY_STATIC;
}

void BoxStaticBody::Intialize(Def d, Entity* obj)
{
    body_def.position.Set((int)d.GetVal("x") * SCALE, (int)d.GetVal("y") * SCALE);
    body_def.angle = toRad(d.GetFloat("rotation"));
    body_def.userData = obj;
    bounding.SetAsBox( ((int)d.GetVal("hw")) * SCALE, ((int)d.GetVal("hh")) * SCALE);

    Def c;
    c.SetVal("def", &body_def);
    body = (b2Body*)phys_world->CreateBody(c);
    body->CreateFixture(&bounding, 0.0f);
}
