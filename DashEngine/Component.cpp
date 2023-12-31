#include "Component.h"
#include <iostream>
using namespace DashEngine;


void Component::Update()
{
}
void Component::Start()
{
}

void Component::processComponent()
{

	if (!StartCalled) {
		//Call the start function of a component
		Start();
		StartCalled = true;
	}

	//Call the Update function of a component
	Update();
}
