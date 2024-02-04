#pragma once
#include "Camera.h"

namespace DashEngine {
    class PrespectiveCamera : public Camera
    {
    public:
        float FovY = glm::radians(60.0f);
        float NearPlane = 0.1f;
        float FarPlane = 100.0f;
        glm::mat4 ProjectionMat;

    public:
        virtual void CalculateProjectionMatrice();
        virtual glm::mat4 GetProjectionMatrice();
        PrespectiveCamera();
    };
}