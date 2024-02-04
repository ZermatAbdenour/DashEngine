#pragma once
#include "PositionalLight.h"

namespace DashEngine {
    class SpotLight :public PositionalLight {
    public:
        float CutOff;
        float OuterCutOff;
    public:
        SpotLight();
        
    };
}