#include "Component.h"
#include "ComponentEditor.h"
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

void Component::SetComponentEditor(DashEditor::ComponentEditor* editor)
{
    // Assuming you want to delete the existing editor before creating a new one
    if (Editor) {
        delete Editor;
        Editor = nullptr;
    }

    Editor = editor;
    editor->Target = this;
}
