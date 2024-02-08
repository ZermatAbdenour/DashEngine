#pragma once
#include "Camera.h"
#include <glm/glm.hpp>

namespace DashEngine {

    class OrthographicCamera : public Camera
    {
    public:
        glm::mat4 ProjectionMat;

    public:
        virtual void CalculateProjectionMatrice();
        virtual glm::mat4 GetProjectionMatrice();
        OrthographicCamera();
    };
}
