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
#include "Scene.h"

namespace DashEngine {
    class Scene; //Forward Declaration of the class Entity
	class Entity
	{
	public:
        //Identifiers
        std::string Name;
        int entityID;
        Scene* scene;
        //Transform
        glm::vec3 LocalPosition;
        glm::vec3 EulerAngles;
        glm::vec3 Scale;
        glm::mat4 Model;

        glm::vec3 forward;
        glm::vec3 right;
        glm::vec3 up;
        //hierarchy
		std::vector<Entity*> Childs;
		Entity* Parent;//if Parent == NULL means the Enitity is a root
		Entity* Root;

		std::vector<Component*> Components;
        float LatestProcessTime;
	private:

		static int _nextEntityID;

	public:
		Entity();
        Entity(std::string name);
        ~Entity();
        void Delete();
        void setParent(Entity* parent);
		void addChild(Entity* child);
		void removeChild(Entity* child);
        //Entity transform
        void SetGlobalPosition(glm::vec3 position);
        glm::vec3 GetGlobalPosition();

        //Processing Entity
        glm::mat4 GetModel();
        void UpdateEntityVectors();
		void processEntity();

        //Manage Entity Componenets
		template <typename T>
        T* addComponent();
        template <typename T>
        T* getComponent() const;
        template <typename T>
        void removeComponent();

    private:
        void InitEntity();
	};


}


#include "Entity.inl"