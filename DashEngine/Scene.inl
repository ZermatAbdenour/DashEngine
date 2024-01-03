#pragma once
#include "Scene.h"
using namespace DashEngine;

extern int componentCounter;
template <class T>
int GetComponentId()
{
    static int s_componentId = componentCounter++;
    return s_componentId;
}

template <class T>
void Scene::AssignComponent(EntityID entityid) {
    Entities[entityid].mask.set(GetComponentId(T));
}
