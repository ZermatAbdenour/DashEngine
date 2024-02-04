#include "myScene.h"
#include <DashEngine/MeshRenderer.h>
#include <DashEngine/OrthographicCamera.h>
#include <DashEngine/PrespectiveCamera.h>
#include "move.h"
#include "print.h"
#include <DashEngine/TimeUtils.h>
#include<DashEngine/ModelLoader.h>
myScene::myScene()
{
    Entity* camera = new Entity();
    AddEntitie(camera);
    camera->addComponent<PrespectiveCamera>();

    camera->LocalPosition = glm::vec3(0,0,0);
    camera->EulerAngles = glm::vec3(0,0, 0);
    camera->addComponent<move>();

    Entity* object = new Entity();
    AddEntitie(object);
    object->LocalPosition = glm::vec3(0, 0, 3);
    object->EulerAngles = glm::vec3(0, 9, 0);
    object->Scale = glm::vec3(1);
    object->addComponent<MeshRenderer>();
    object->addComponent<Print>();

    Entity* object1 = new Entity();
    AddEntitie(object1);
    //std::cout << "loadModel";
    ModelLoader::LoadModel("Resources/Models/backpack/backpack.obj", object1);

    object1->Scale = glm::vec3(10, 2, 2);
}