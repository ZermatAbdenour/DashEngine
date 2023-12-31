#pragma once
#include <glm/glm.hpp>
#include <glm/fwd.hpp>
#include "Component.h"

namespace DashEngine {
    class Camera :public Component
    {
    public:
        static Camera* ActiveCamera;

    public:
        Camera();
        void SetActiveCamera();
        virtual void CalculateProjectionMatrice();
        virtual glm::mat4 GetProjectionMatrice();
        glm::mat4 GetViewMatrice();
    };
}