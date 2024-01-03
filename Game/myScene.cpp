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
    camera->addComponent<OrthographicCamera>();

    camera->LocalPosition = glm::vec3(0,0,0);
    camera->EulerAngles = glm::vec3(0,0, 0);

    Entity* Circle = new Entity();
    AddEntitie(Circle);
    Circle->LocalPosition = glm::vec3(0, 0, 5);
    Circle->EulerAngles = glm::vec3(0, 0, 0);
    Circle->Scale = glm::vec3(1);
    SpriteRenderer* sprite = Circle->addComponent<SpriteRenderer>();
    sprite->texture = ResourceManagement::Textures::GetTexture("Circle");

    Circle->addComponent<move>();

}