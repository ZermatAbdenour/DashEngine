#include "Scene.h"

using namespace DashEngine;

void Scene::RenderScene()
{
	for (int i = 0;i < RootEntities.size();i++) {
		RootEntities[i]->processEntity();
	}
}

void Scene::AddEntitie(Entity* entity)
{
	RootEntities.push_back(entity);
}
