#include <glm/ext/matrix_clip_space.hpp>
#include "PrespectiveCamera.h"
#include "PrespectiveCameraEditor.h"
#include "Engine.h"
namespace DashEngine {
    void PrespectiveCamera::CalculateProjectionMatrice()
    {
        ProjectionMat = glm::perspective(glm::radians(FovY), (float)s_currentWidth / s_currentHeight, NearPlane, FarPlane);
    }

    glm::mat4 DashEngine::PrespectiveCamera::GetProjectionMatrice()
    {
        CalculateProjectionMatrice();
        return ProjectionMat;
    }

    PrespectiveCamera::PrespectiveCamera()
    {
        //Set Editor
        SetComponentEditor(new DashEditor::PrespectiveCameraEditor());

        CalculateProjectionMatrice();
    }
}