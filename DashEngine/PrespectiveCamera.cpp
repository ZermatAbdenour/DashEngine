#include <glm/ext/matrix_clip_space.hpp>
#include "PrespectiveCamera.h"
#include "Engine.h"
using namespace DashEngine;
void PrespectiveCamera::CalculateProjectionMatrice()
{
    int width, height;
    glfwGetWindowSize(Engine::window, &width, &height);
    ProjectionMat = glm::perspective(FovY, (float)width / height,NearPlane, FarPlane);
}

glm::mat4 DashEngine::PrespectiveCamera::GetProjectionMatrice()
{
    return ProjectionMat;
}

PrespectiveCamera::PrespectiveCamera()
{
    CalculateProjectionMatrice();
}
