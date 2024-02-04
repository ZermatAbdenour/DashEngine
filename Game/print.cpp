#include "print.h"
#include <DashEngine/Entity.h>
#include <DashEngine/TimeUtils.h>
#include<DashEngine/Inputs.h>
void Print::Update()
{
    

}

void Print::Start()
{
    Inputs::Mouse::SetCursorMode(CursorMode::Normal);
    //entity->SetGlobalPosition(glm::vec3(0, 0, 0));
}
