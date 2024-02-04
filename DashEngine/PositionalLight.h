#pragma once
#include "DirectionalLight.h"

namespace DashEngine {
    class PositionalLight :public DirectionalLight {
    public:
        glm::vec3 Position;
    public:

    };
}