#include "MeshRenderer.h"
#include<glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "Entity.h"
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include "Camera.h"


DashEngine::MeshRenderer::MeshRenderer()
{

}

void DashEngine::MeshRenderer::Start()
{
    meshData->LoadToGPU();
}

void DashEngine::MeshRenderer::Update()
{
    shader->use();

    shader->setMatrix4fv("model", entity->Model);
    shader->setMatrix4fv("view", Camera::ActiveCamera->GetViewMatrice());
    shader->setMatrix4fv("projection", Camera::ActiveCamera->GetProjectionMatrice());
    texture->Use();

    //Set Uniforms
    shader->setVec3("LightColor" ,glm::vec3(1,1,1));
    shader->setVec3("LightDirection", glm::vec3(1, 0, -1));

    meshData->DrawMesh();
}
