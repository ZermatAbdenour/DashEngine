#pragma once
#include <glm/glm.hpp>
#include <glm/fwd.hpp>
#include "Component.h"

namespace DashEngine {
    class Camera :public Component
    {
    public:
        float NearPlane = 0.1f;
        float FarPlane = 30.0f;
        static Camera* ActiveCamera;

    public:
        Camera();
        void SetActiveCamera();
        virtual void CalculateProjectionMatrice();
        virtual glm::mat4 GetProjectionMatrice();
        virtual glm::vec3 ScreenToWorldPosition(glm::vec2 position);
        glm::mat4 GetViewMatrice();
    };
}