#include <DashEngine/Engine.h>
#include <iostream>
#include "myScene.h"
using namespace DashEngine;
int main(void) {
	Engine*e = new Engine();
	myScene* s = new myScene();

    
	while (e->isRunning())
	{
		e->Update(s);
	}

	return 0;
}