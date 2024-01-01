#include "myScene.h"
#include <DashEngine/MeshRenderer.h>
#include <DashEngine/SpriteRenderer.h>
#include <DashEngine/OrthographicCamera.h>
#include <DashEngine/PrespectiveCamera.h>
#include "move.h"
#include "print.h"
#include <DashEngine/TimeUtils.h>

myScene::myScene()
{
    Entity* camera = new Entity();
    AddEntitie(camera);
    camera->addComponent<PrespectiveCamera>();

    camera->LocalPosition = glm::vec3(0,0,0);
    camera->EulerAngles = glm::vec3(0,0, 0);

    Entity* Cube = new Entity();
    AddEntitie(Cube);
    Cube->LocalPosition = glm::vec3(0, 0, 5);
    Cube->EulerAngles = glm::vec3(45, 0, 0);
    Cube->addComponent<MeshRenderer>();
    Cube->addComponent<move>();

    Entity* CubeChild = new Entity();
    Cube->addChild(CubeChild);
    CubeChild->LocalPosition = glm::vec3(1, 0, 0);
    CubeChild->addComponent<Print>();
}