#include "SpotLight.h"
#include "Engine.h"
namespace DashEngine {
    SpotLight::SpotLight(){
        Engine::Instance->ActiveScene->LightManager.AddSpotLight(*this);
    }
}