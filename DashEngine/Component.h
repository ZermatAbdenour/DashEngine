#include"ComponentEditor.h"
#pragma once

namespace DashEngine {
    using namespace DashEditor;
    class Entity; //Forward Declaration of the class Entity

	class Component
	{
    public:
        Entity* entity;
        ComponentEditor* Editor;
	private:
		bool StartCalled = false;

	public:
		virtual void Update();
		virtual void Start();
		void processComponent();
	private:

	};
}