#pragma once
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include <vector>
namespace DashEngine {
    class LightManager {
    private:
        DirectionalLight m_directionalLight;
        std::vector<PointLight> m_pointLights;
        std::vector<SpotLight> m_spotLights;

    public:
        void SetDirectionalLight(DirectionalLight directionalLight);
        void AddPointLight(PointLight pointlight);
        void RemovePointLight(PointLight pointlight);
        void AddSpotLight(SpotLight spotLight);
        void RemoveSpotLight(SpotLight spotLight);

    };
}
