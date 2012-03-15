#include "BoxTriggerBody.h"
#include "../Constants.h"
#include "../Entity.h"
BoxTriggerBody::BoxTriggerBody()
{
    //ctor
    type = BODY_TRIGGER;
}

void BoxTriggerBody::Intialize(Entity* obj)
{
    body_def.position.Set(obj->GetVal<int>("x") * SCALE, obj->GetVal<int>("y") * SCALE);
    body_def.angle = toRad(obj->GetVal<float>("rotation"));
    body_def.userData = obj;
    body_def.type = b2_staticBody;
    bounding.SetAsBox( (obj->GetVal<int>("hw")) * SCALE, (obj->GetVal<int>("hh")) * SCALE);
    fix_def.density = 1.0f;
    fix_def.friction = 1.0f;
    fix_def.shape = &bounding;
    fix_def.isSensor = true;

    Def c;
    c.SetVal("def", body_def);
    body = (b2Body*)phys_world->CreateBody(c);
    fix = body->CreateFixture(&fix_def);
}
