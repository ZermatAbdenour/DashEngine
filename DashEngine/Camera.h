#pragma once
#include <glm/glm.hpp>
#include <glm/fwd.hpp>
#include "Component.h"

namespace DashEngine {
    class Camera : public Component
    {
    public:
        float NearPlane = 0.1f;
        float FarPlane = 30.0f;
        static Camera* ActiveCamera;
        static float s_currentWidth, s_currentHeight;
    public:
        Camera();
        void SetActiveCamera();
        glm::mat4 GetViewMatrice();
        virtual void CalculateProjectionMatrice();
        virtual void CalculateProjectionMatrice(float width, float height);
        virtual glm::mat4 GetProjectionMatrice();
        virtual glm::vec3 ScreenToWorldPosition(glm::vec2 position);
        static void SetCurrentSize(float width,float height);
    };
}