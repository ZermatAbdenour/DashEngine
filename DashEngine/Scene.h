#pragma once
#include <vector>
#include "Entity.h"
#include "LightsManager.h"
namespace DashEngine {
	class Scene
	{
	public:
		std::vector<Entity*> RootEntities;

        //Light manager
        LightManager LightManager;
	public:
		void RenderScene();
		void AddEntitie(Entity* entity);
		void RemoveEntitie();
	};
}
