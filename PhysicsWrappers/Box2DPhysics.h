#pragma once
//#define PHYS_BOX2D
//#ifdef PHYS_BOX2D
#include "BoxWorld.h"
#include "BoxDynamicBody.h"
#include "BoxStaticBody.h"
#include "BoxTriggerBody.h"

#define StaticBody BoxStaticBody
#define DynamicBody BoxDynamicBody
#define TriggerBody BoxTriggerBody
#define Physics2D BoxWorld
#define Physics3D

#define PHYSINUSE
//#endif
