#include "move.h"
#include <iostream>
#include <DashEngine/Entity.h>
#include<DashEngine/TimeUtils.h>
#include<DashEngine/Inputs.h>
void move::Update()
{

    if (Inputs::GetMouseButton(0)) {
        entity->EulerAngles += entity->getRight() * -Inputs::Mouse::delta.y + glm::vec3(0, Inputs::Mouse::delta.x, 0);
    }

}

