#include "move.h"
#include <iostream>
#include <DashEngine/Entity.h>
#include<DashEngine/TimeUtils.h>
void move::Update()
{
    entity->LocalPosition += glm::vec3(0,0,5 * TimeUtils::deltaTime);
    //std::cout << 1/ Time::deltaTime << std::endl;

}

