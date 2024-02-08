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
    mesh->Load();
}

void DashEngine::MeshRenderer::Update()
{
    shader->use();

    shader->setMatrix4fv("model", entity->Model);
    shader->setMatrix4fv("view", Camera::ActiveCamera->GetViewMatrice());
    shader->setMatrix4fv("projection", Camera::ActiveCamera->GetProjectionMatrice());
    

    shader->setVec3("u_viewPos", Camera::ActiveCamera->entity->GetGlobalPosition());
    //Settup the matereial
    shader->setVec3("u_material.baseColor", glm::vec3(1, 1, 1));

    //Maps
    shader->setFloat("u_material.shininess", 30);

    //setup directional light
    shader->setVec3("u_directionalLight.direction", glm::vec3(0, 0, 1));
    shader->setVec3("u_directionalLight.ambient", glm::vec3(0.3f,0.3f,0.3f));
    shader->setVec3("u_directionalLight.diffuse", glm::vec3(1, 1, 1));
    shader->setVec3("u_directionalLight.specular", glm::vec3(1, 1, 1));

    //setup point lights

    shader->setVec3("u_pointLights[0].position", glm::vec3(3, 0, 1));
    shader->setVec3("u_pointLights[0].ambient", glm::vec3(0.3f, 0.3f, 0.3f));
    shader->setVec3("u_pointLights[0].diffuse", glm::vec3(1, 1, 1));
    shader->setVec3("u_pointLights[0].specular", glm::vec3(1, 1, 1));
    
    shader->setFloat("u_pointLights[0].constant", 1.0);
    shader->setFloat("u_pointLights[0].linear", 0.7);
    shader->setFloat("u_pointLights[0].quadratic", 1.8);

    shader->setVec3("u_pointLights[1].position", glm::vec3(0, 0,5));
    shader->setVec3("u_pointLights[1].ambient", glm::vec3(0.3f, 0,0));
    shader->setVec3("u_pointLights[1].diffuse", glm::vec3(1, 0, 0));
    shader->setVec3("u_pointLights[1].specular", glm::vec3(1, 1, 1));

    shader->setFloat("u_pointLights[1].constant", 1.0);
    shader->setFloat("u_pointLights[1].linear", 0.7);
    shader->setFloat("u_pointLights[1].quadratic", 1.8);

    //setup spot lights
    shader->setVec3("u_spotLights[0].position", Camera::ActiveCamera->entity->GetGlobalPosition());
    shader->setVec3("u_spotLights[0].direction", Camera::ActiveCamera->entity->forward);
    shader->setVec3("u_spotLights[0].ambient", glm::vec3(0, 0, 0.3f));
    shader->setVec3("u_spotLights[0].diffuse", glm::vec3(0, 0, 1));
    shader->setVec3("u_spotLights[0].specular", glm::vec3(0, 0, 1));

    shader->setFloat("u_spotLights[0].cutOff", cos(glm::radians(15.0f)));
    shader->setFloat("u_spotLights[0].outerCutOff", cos(glm::radians(30.0f)));

    //Camera
    shader->setFloat("u_nearPlane", Camera::ActiveCamera->NearPlane);
    shader->setFloat("u_farPlane", Camera::ActiveCamera->FarPlane);

    mesh->Draw(*shader);
}
