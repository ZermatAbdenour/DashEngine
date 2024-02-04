#include "PointLight.h"
#include "Engine.h"
namespace DashEngine {
    PointLight::PointLight()
    {
        Engine::Instance->ActiveScene->LightManager.AddPointLight(*this);
    }

}
