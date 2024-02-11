#include "Scene.h"
namespace DashEngine {

    void Scene::RenderScene()
    {
        for (int i = 0;i < RootEntities.size();i++) {
            RootEntities[i]->processEntity();
        }
    }

    void Scene::AddEntitie(Entity* entity)
    {
        entity->scene = this;
        RootEntities.push_back(entity);
    }

    void Scene::RemoveRootEntity(Entity* entity)
    {
        for (int i = 0;i < entity->Childs.size();i++) {
            entity->removeChild(entity->Childs[i]);
        }
        auto it = std::find(RootEntities.begin(), RootEntities.end(), entity);
        delete entity;
        if(it != RootEntities.end())
            RootEntities.erase(it);
    }
}
