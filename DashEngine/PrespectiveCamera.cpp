#include <glm/ext/matrix_clip_space.hpp>
#include "PrespectiveCamera.h"
#include "Engine.h"
using namespace DashEngine;
void PrespectiveCamera::CalculateProjectionMatrice()
{
    ProjectionMat = glm::perspective(FovY, (float)Engine::Instance->WindowWidth / Engine::Instance->WindowHeight,NearPlane, FarPlane);
}

glm::mat4 DashEngine::PrespectiveCamera::GetProjectionMatrice()
{
    return ProjectionMat;
}

PrespectiveCamera::PrespectiveCamera()
{
    CalculateProjectionMatrice();
}
