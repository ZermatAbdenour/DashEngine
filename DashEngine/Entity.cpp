#include "Entity.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace DashEngine;

int Entity::_nextEntityID = 1;


Entity::Entity()
{
	_entityID = _nextEntityID;
	_nextEntityID++;

    //Reset Transform
    LocalPosition = glm::vec3(0.0f);
    EulerAngles = glm::vec3(0.0f);
    Scale = glm::vec3(1.0f);

	Parent = nullptr;
	Root = nullptr;
}

void Entity::addChild(Entity* child)
{
	//add the child into the childs vector
	Childs.push_back(child);

	//Set the Child parent into this 
	child->Parent = this;

	//Add the Root of the child
	if (this->Parent == nullptr)
		child->Root = this;
	else
		child->Root = this->Root;
}

void Entity::removeChild(Entity* child)
{

}

void Entity::processEntity()
{
    
    float processStartTime = glfwGetTime();
    
    //get Model
    GetModel();
    UpdateEntityVectors();

	//std::cout << "processing Entity id :" << _entityID << std::endl;
	for (int i = 0;i < Components.size();i++) {
  		Components[i]-> processComponent();
	}

	for (int i = 0;i < Childs.size();i++)
		Childs[i]->processEntity();

    LatestProcessTime = (glfwGetTime() - processStartTime)*1000;//in milliseconds
}

glm::mat4 Entity::GetModel()
{
    // Build the Model matrix
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), LocalPosition);
    glm::mat4 rotationMatrix = glm::eulerAngleYXZ(glm::radians(EulerAngles.y), glm::radians(EulerAngles.x), glm::radians(EulerAngles.z));
    glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), Scale);

    if(Parent == nullptr)
        Model = translationMatrix * rotationMatrix * scalingMatrix;
    else
        Model = Parent->Model * translationMatrix * rotationMatrix * scalingMatrix;
    return Model;
}

void DashEngine::Entity::UpdateEntityVectors()
{
    glm::vec3 front;

    front.x = sin(glm::radians(EulerAngles.y)) * cos(glm::radians(EulerAngles.x));
    front.y = sin(glm::radians(EulerAngles.x));
    front.z = -cos(glm::radians(EulerAngles.y)) * cos(glm::radians(EulerAngles.x));

    front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    glm::vec3 right = glm::normalize(glm::cross(front, glm::vec3(0, 1, 0)));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    glm::vec3 up = glm::normalize(glm::cross(right, front));

    this->forward = front;
    this->up = up;
    this->right = right;
}

glm::vec3 Entity::GetGlobalPosition()
{
    return glm::vec3(Model[3]);
}
void Entity::SetGlobalPosition(glm::vec3 position)
{
    LocalPosition = position - Parent->GetGlobalPosition();
}

