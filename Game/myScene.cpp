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
    //std::cout << "loadModel";
    ModelLoader::Model* model = ModelLoader::LoadModel("Resources/Models/backpack/backpack.obj",true);
    model->rootEntity->Scale = glm::vec3(1, 1, 1);
    AddEntitie(model->rootEntity);

    /*ModelLoader::Model model2 = ModelLoader::LoadModel("Resources/Models/backpack/backpack.obj");
    AddEntitie(model2.rootEntity);
    model2.rootEntity->Scale = glm::vec3(0.3);
    model2.rootEntity->LocalPosition = glm::vec3(0, 0.5, 0);*/
}