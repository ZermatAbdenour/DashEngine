#include "Component.h"
#include "ComponentEditor.h"

using namespace DashEngine;


DashEngine::Component::Component()
{
}

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

    if (Editor) {
        delete Editor;
        Editor = nullptr;
    }

    Editor = editor;
    editor->Target = this;
}
