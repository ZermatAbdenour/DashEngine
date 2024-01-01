#include "print.h"
#include <DashEngine/Entity.h>
#include <DashEngine/TimeUtils.h>
#include<DashEngine/Inputs.h>
void Print::Update()
{
    if (Inputs::GetKeyUp(KeyCode::A))
        std::cout << entity->GetGlobalPosition().x << " "<< entity->GetGlobalPosition().y<<" " << entity->GetGlobalPosition().z << std::endl;

    if(Inputs::GetMouseButton(0))
        std::cout << Inputs::Mouse::delta.x<<"|" << Inputs::Mouse::delta.y << std::endl;

}

void Print::Start()
{
    //entity->SetGlobalPosition(glm::vec3(0, 0, 0));
}
