#pragma once
#include <vector>
#include "Entity.h"

namespace DashEngine {
	class Scene
	{
	public:
		std::vector<Entity*> RootEntities;

	public:
		void RenderScene();
		void AddEntitie(Entity* entity);
		void RemoveEntitie();
	};
}
