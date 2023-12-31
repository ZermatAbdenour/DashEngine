#pragma once

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Component.h"
#include <glm/glm.hpp>

namespace DashEngine {
	
	class Entity
	{
	public:
        //Transform
        glm::vec3 LocalPosition;
        glm::vec3 EulerAngles;
        glm::vec3 Scale;
        glm::mat4 Model;
        //hierarchy
		std::vector<Entity*> Childs;
		Entity* Parent;//if Parent == NULL means the Enitity is a root
		Entity* Root;

		std::vector<Component*> Components;
        float LatestProcessTime;
	private:
		int _entityID;
		static int _nextEntityID;

	public:
		Entity();
		void addChild(Entity* child);
		void removeChild(Entity* child);

        //Entity transform
        void SetGlobalPosition(glm::vec3 position);
        glm::vec3 GetGlobalPosition();

        //Processing Entity
        glm::mat4 GetModel();
		void processEntity();

        //Manage Entity Componenets
		template <typename T>
        T* addComponent();
        template <typename T>
        T* getComponent() const;
        template <typename T>
        void removeComponent();

        //Direction Vectors
        glm::vec3 getForward();
        glm::vec3 getRight();
        glm::vec3 getUp();

	};


}


#include "Entity.inl"