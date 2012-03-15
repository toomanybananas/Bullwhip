#include "BoxDynamicBody.h"
#include "../Constants.h"
#include "../Entity.h"
BoxDynamicBody::BoxDynamicBody()
{
    //ctor
    type = BODY_DYNAMIC;
}

void BoxDynamicBody::Intialize(Entity* obj)
{
    body_def.position.Set(obj->GetVal<int>("x") * SCALE, obj->GetVal<int>("y") * SCALE);
    body_def.angle = toRad(obj->GetVal<float>("rotation"));
    body_def.userData = obj;
    body_def.type = b2_dynamicBody;
    bounding.SetAsBox( (obj->GetVal<int>("hw")) * SCALE, (obj->GetVal<int>("hh")) * SCALE);
    fix_def.density = 1.0f;
    fix_def.friction = 0.2f;
    fix_def.shape = &bounding;

    Def c;
    c.SetVal("def", body_def);
    body = (b2Body*)phys_world->CreateBody(c);
    fix = body->CreateFixture(&fix_def);
}
