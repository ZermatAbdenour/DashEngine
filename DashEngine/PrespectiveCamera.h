#pragma once
#include "Camera.h"

namespace DashEngine {
    class PrespectiveCamera : public Camera
    {
    public:
        float FovY = 60.0f;
        glm::mat4 ProjectionMat;

    public:
        virtual void CalculateProjectionMatrice();
        virtual glm::mat4 GetProjectionMatrice();
        PrespectiveCamera();
    };
}