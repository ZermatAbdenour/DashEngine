#include "Camera.h"
#include <glm/gtx/euler_angles.hpp>

#include "Entity.h"

using namespace DashEngine;

Camera* Camera::ActiveCamera = nullptr;

Camera::Camera()
{
    ActiveCamera = this;
}

void Camera::SetActiveCamera()
{
    ActiveCamera = this;
    CalculateProjectionMatrice();
}

void Camera::CalculateProjectionMatrice()
{
}

glm::mat4 Camera::GetViewMatrice()
{

    // Build the Model matrix
    
    glm::mat4 view = glm::lookAt(entity->LocalPosition, entity->LocalPosition+ entity->getForward(), entity->getUp());

    return view;
}

glm::mat4 DashEngine::Camera::GetProjectionMatrice()
{
    return glm::mat4(1);
}
