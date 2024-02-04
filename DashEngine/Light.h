#pragma once
#include <glm/glm.hpp>
#include "Component.h"

namespace DashEngine {
    class DirectionalLight :public Component{
    public:
        glm::vec3 Direction;

        glm::vec3 Ambient;
        glm::vec3 Diffuse;
        glm::vec3 Specular;
    };
}