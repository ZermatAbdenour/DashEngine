#pragma once
#include "PositionalLight.h"

namespace DashEngine {
    class PointLight :public PositionalLight {
    public:
        float Constant;
        float Linear;
        float Quadratic;

    public:
        PointLight();
    };
}