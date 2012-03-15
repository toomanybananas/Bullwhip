#include "BoxStaticBody.h"
#include "../Constants.h"
#include "../Entity.h"
BoxStaticBody::BoxStaticBody()
{
    //ctor
    type = BODY_STATIC;
}

void BoxStaticBody::Intialize(Entity* obj)
{
    body_def.position.Set(obj->GetVal<int>("x") * SCALE, obj->GetVal<int>("y") * SCALE);
    body_def.angle = toRad(obj->GetVal<float>("rotation"));
    body_def.userData = obj;
    bounding.SetAsBox( (obj->GetVal<int>("hw")) * SCALE, (obj->GetVal<int>("hh")) * SCALE);

    Def c;
    c.SetVal("def", body_def);
    body = (b2Body*)phys_world->CreateBody(c);
    body->CreateFixture(&bounding, 0.0f);
}
