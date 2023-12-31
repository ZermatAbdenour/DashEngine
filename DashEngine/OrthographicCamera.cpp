#include <glm/gtc/matrix_transform.hpp>
#include "OrthographicCamera.h"
#include "Engine.h"

using namespace DashEngine;
void OrthographicCamera::CalculateProjectionMatrice()
{
    int width, height;
    glfwGetWindowSize(Engine::window, &width, &height);
    float aspectRatio = (float)width / height;
    float orthoLeft = -aspectRatio;
    float orthoRight = aspectRatio;
    float orthoBottom = -1.0f;
    float orthoTop = 1.0f;
    ProjectionMat = glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop,NearPlane,FarPlane);
}

glm::mat4 OrthographicCamera::GetProjectionMatrice()
{
    return ProjectionMat;
}

OrthographicCamera::OrthographicCamera()
{
    CalculateProjectionMatrice();
}
