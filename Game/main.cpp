#include <DashEngine/Engine.h>
#include <iostream>
#include "myScene.h"
using namespace DashEngine;
int main(void) {
	Engine e = Engine();
	myScene* s = new myScene();

    e.Load(s);

	return 0;
}