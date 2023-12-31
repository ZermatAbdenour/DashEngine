// Entity.inl
#pragma once
#include"Entity.h"
template <typename T>

T* DashEngine::Entity::addComponent(){
    static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
    T* newComponent = new T();
    // Add the component to the entity
    Components.push_back(newComponent);

    Component* component = static_cast<Component*>(newComponent);
    component->entity = this;
    return newComponent;
}

template <typename T>
T* DashEngine::Entity::getComponent() const{
    // Find the component of type T in the vector
    for (Component* component : Components) {
        T* castedComponent = dynamic_cast<T*>(component);
        if (castedComponent != nullptr) {
            return castedComponent;
        }
    }

    // Return nullptr if the component is not found
    return nullptr;
}

template <typename T>
void DashEngine::Entity::removeComponent() {
    // Use an iterator to find the component of type T in the vector
    auto it = std::remove_if(Components.begin(), Components.end(), [](Component* component) {
        return dynamic_cast<T*>(component) != nullptr;
        });

    Components.erase(it, Components.end());
}