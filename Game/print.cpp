#include "print.h"
#include <DashEngine/Entity.h>
#include <DashEngine/TimeUtils.h>
#include<DashEngine/Inputs.h>
void Print::Update()
{

    std::cout << "FPS: " << 1 / TimeUtils::deltaTime << std::endl;



}

void Print::Start()
{

}
