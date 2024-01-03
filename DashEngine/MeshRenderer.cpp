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

    //Settup the matereial
    shader->setVec3("material.BaseColor", glm::vec3(1, 1, 1));
    shader->setInt("material.useTexture", 1);
    shader->setVec3("material.ambient", glm::vec3(0.0215, 0.1745, 0.0215));
    shader->setVec3("material.diffuse", glm::vec3(0.07568, 0.61424, 0.07568));
    shader->setVec3("material.specular", glm::vec3(0.633, 0.727811, 0.633));
    shader->setFloat("material.shininess", 32);
    texture->Use();

    //Set Uniforms
    shader->setVec3("LightColor" ,glm::vec3(1,1,1));
    shader->setVec3("LightDirection", glm::vec3(0, 0, -1));

    meshData->DrawMesh();
}
