#pragma once
#include <vector>
#include "Entity.h"
#include "LightsManager.h"
namespace DashEngine {
    class Entity;
	class Scene
	{
	public:
		std::vector<Entity*> RootEntities;

        //Light manager
        LightManager LightManager;
	public:
        Scene();
		void RenderScene();
		void AddEntitie(Entity* entity);
		void RemoveRootEntity(Entity* entity);
	};
}
