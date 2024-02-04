#include <glm/gtc/matrix_transform.hpp>
#include "OrthographicCamera.h"
#include "Engine.h"

using namespace DashEngine;

OrthographicCamera::OrthographicCamera()
{
    CalculateProjectionMatrice();
}

void OrthographicCamera::CalculateProjectionMatrice()
{
    float aspectRatio = (float)Engine::Instance->WindowWidth / Engine::Instance->WindowHeight;
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
