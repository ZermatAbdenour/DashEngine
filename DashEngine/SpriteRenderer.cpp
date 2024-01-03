#include "SpriteRenderer.h"
#include<glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "Entity.h"
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include "Camera.h"


using namespace DashEngine;

SpriteRenderer::SpriteRenderer()
{
}

void SpriteRenderer::Start()
{
    meshData->LoadToGPU();
}

void SpriteRenderer::Update()
{
    shader->use();


    shader->setMatrix4fv("model", entity->Model);
    shader->setMatrix4fv("view", Camera::ActiveCamera->GetViewMatrice());
    shader->setMatrix4fv("projection", Camera::ActiveCamera->GetProjectionMatrice());

    //Settup material
    shader->setVec3("material.BaseColor", glm::vec3(1, 1, 1));
    shader->setInt("material.useTexture", 1);
    texture->Use();

    meshData->DrawMesh();

}
