#pragma once

#include <DashEngine/Component.h>
#include<glm/glm.hpp>
using namespace DashEngine;

class move: public Component
{
 public:
    glm::vec3 Bounds = glm::vec3(1, 1, 0.0f);
    glm::vec3 MovementDirection = glm::vec3(0.7f, 0.5f, 0.0f);
public:
    virtual void Start();
    virtual void Update();
};