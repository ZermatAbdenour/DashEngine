#pragma once

namespace DashEditor {
    class ComponentEditor;
}
namespace DashEngine {
    class Entity; //Forward Declaration of the class Entity

	class Component
	{
    public:
        Entity* entity;
        DashEditor::ComponentEditor* Editor;
        Component();
	private:
		bool StartCalled = false;

	public:
		virtual void Update();
		virtual void Start();
		void processComponent();
        void SetComponentEditor(DashEditor::ComponentEditor* editor);
	private:

	};
}