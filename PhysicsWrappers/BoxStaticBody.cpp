#include "BoxStaticBody.h"
#include "../Constants.h"
BoxStaticBody::BoxStaticBody()
{
    //ctor
    type = BODY_STATIC;
}

void BoxStaticBody::Intialize(Def d, Entity* obj)
{
    body_def.position.Set(d.GetVal<int>("x") * SCALE, d.GetVal<int>("y") * SCALE);
    body_def.angle = toRad(d.GetVal<float>("rotation"));
    body_def.userData = obj;
    bounding.SetAsBox( (d.GetVal<int>("hw")) * SCALE, (d.GetVal<int>("hh")) * SCALE);

    Def c;
    c.SetVal("def", body_def);
    body = (b2Body*)phys_world->CreateBody(c);
    body->CreateFixture(&bounding, 0.0f);
}
