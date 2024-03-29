#include "Camera.h"
#include <glm/gtx/euler_angles.hpp>
#include"Engine.h"
#include "Entity.h"
#include "PrespectiveCameraEditor.h"
using namespace DashEngine;

Camera* Camera::ActiveCamera = nullptr;
float Camera::s_currentWidth = 800;
float Camera::s_currentHeight = 600;

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

void Camera::CalculateProjectionMatrice(float width, float height)
{
}

glm::mat4 Camera::GetViewMatrice()
{
    // Build the view matrix
    glm::mat4 view = glm::lookAt(entity->LocalPosition, entity->LocalPosition + entity->forward, entity->up);

    return view;
}


glm::mat4 DashEngine::Camera::GetProjectionMatrice()
{
    std::cout << "Camera projection mat" << std::endl;
    return glm::mat4(1);
}


//ChatGPT
glm::vec3 Camera::ScreenToWorldPosition(glm::vec2 position)
{
    // Convert to NDC
    float ndc_x = (2.0 * position.x) / -s_currentWidth - 1.0;
    float ndc_y = 1.0 - (2.0 * position.y) / -s_currentHeight;

    // Convert to clip coordinates
    glm::vec4 clipCoords(ndc_x, ndc_y, -1.0, 1.0);

    // Convert to eye coordinates
    glm::mat4 inverseProjectionMatrix = glm::inverse(GetProjectionMatrice());
    glm::vec4 eyeCoords = inverseProjectionMatrix * clipCoords;
    eyeCoords = glm::vec4(eyeCoords.x, eyeCoords.y, -1.0, 0.0);

    // Convert to world coordinates
    glm::mat4 inverseViewMatrix = glm::inverse(GetViewMatrice());
    glm::vec4 worldCoords = inverseViewMatrix * eyeCoords;

    return worldCoords;
}

void Camera::SetCurrentSize(float width,float height)
{
    s_currentWidth = width;
    s_currentHeight = height;
}