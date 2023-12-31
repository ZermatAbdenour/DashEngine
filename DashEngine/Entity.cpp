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

glm::vec3 Entity::getForward() {

    glm::vec3 euler_angles_rad = glm::vec3(glm::radians(EulerAngles.x), glm::radians(EulerAngles.y), glm::radians(EulerAngles.z));
    glm::quat quaternion = glm::quat(euler_angles_rad);
    glm::vec3 forward = glm::normalize(quaternion * glm::vec3(0, 0, 1));
    return forward;
}

glm::vec3 Entity::GetGlobalPosition()
{
    return glm::vec3(Model[3]);
}
void Entity::SetGlobalPosition(glm::vec3 position)
{
    LocalPosition = position - Parent->GetGlobalPosition();
}

glm::vec3 Entity::getRight() {
    glm::vec3 euler_angles_rad = glm::vec3(glm::radians(EulerAngles.x), glm::radians(EulerAngles.y), glm::radians(EulerAngles.z));
    glm::quat quaternion = glm::quat(euler_angles_rad);
    glm::vec3 right = glm::normalize(quaternion * glm::vec3(1, 0, 0));
    return right;
}
glm::vec3 Entity::getUp() {
    glm::vec3 euler_angles_rad = glm::vec3(glm::radians(EulerAngles.x), glm::radians(EulerAngles.y), glm::radians(EulerAngles.z));
    glm::quat quaternion = glm::quat(euler_angles_rad);
    glm::vec3 Up = glm::normalize(quaternion * glm::vec3(0, 1, 0));
    return Up;
}