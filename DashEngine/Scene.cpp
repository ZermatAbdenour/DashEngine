#include "Scene.h"
#include "PrespectiveCamera.h"
#include "SceneViewCamera.h"
namespace DashEngine {

    Scene::Scene() {
        Entity* camera = new Entity("Camera");
        camera->addComponent<PrespectiveCamera>();

        camera->LocalPosition = glm::vec3(0, 0, 0);
        camera->EulerAngles = glm::vec3(0, 0, 0);
        camera->addComponent<SceneViewCamera>();
        AddEntitie(camera);
        camera->SetVisibilityInHierarchy(false);
    }

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
        if(it != RootEntities.end())
            RootEntities.erase(it);
        delete entity;
    }
}
