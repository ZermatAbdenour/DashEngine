#include "Entity.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace DashEngine;

int Entity::_nextEntityID = 1;


Entity::Entity()
{
    Name = "Entity";
    InitEntity();
}
Entity::Entity(std::string name) {
    Name = name;
    InitEntity();
}
Entity::~Entity() {

}

void Entity::Delete()
{
    if (Parent == nullptr) {
        scene->RemoveRootEntity(this);
    }
    else {
        Parent->removeChild(this);
    }
        
}



void Entity::SetVisibilityInHierarchy(bool visible)
{
    m_isVisibleInHierarchy = visible;
}

bool DashEngine::Entity::getVisibilityInHierarchy()
{
    return m_isVisibleInHierarchy;
}

void Entity::InitEntity()
{
    entityID = _nextEntityID;
    _nextEntityID++;
    m_isVisibleInHierarchy = true;

    //Reset Transform
    LocalPosition = glm::vec3(0.0f);
    EulerAngles = glm::vec3(0.0f);
    Scale = glm::vec3(1.0f);

    Parent = nullptr;
    Root = nullptr;
}

void Entity::setParent(Entity* parent)
{
    //Set the Child parent into this 
    Parent = parent;

    //Add the Root of the child
    if (parent->Parent == nullptr)
        this->Root = parent;
    else
        this->Root = parent->Root;
}

void Entity::addChild(Entity* child)
{
	//add the child into the childs vector
	Childs.push_back(child);

    child->setParent(this);
}

void Entity::removeChild(Entity* child)
{
    for (int i = 0;i < child->Childs.size();i++) {
        removeChild(child->Childs[i]);
    }
    auto it = std::find(Childs.begin(), Childs.end(), child);
    if (it != Childs.end())
        Childs.erase(it);

    delete child;
}

void Entity::processEntity()
{
    
    float processStartTime = glfwGetTime();
    
    //get Model
    GetModel();
    UpdateEntityVectors();

	//std::cout << "processing Entity id :" << _entityID << std::endl;
	for (int i = 0;i < Components.size();i++) {
  		Components[i]->processComponent();
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
    position = position - Parent->GetGlobalPosition();
}

