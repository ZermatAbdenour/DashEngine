#include "move.h"
#include <iostream>
#include <DashEngine/Entity.h>
#include<DashEngine/TimeUtils.h>
void move::Update()
{
    entity->EulerAngles = glm::vec3(45, 180 * sin(TimeUtils::time), 0);
}

