#pragma once

namespace DashEngine {
    class Entity; //Forward Declaration of the class Entity

	class Component
	{
    public:
        Entity* entity;
	private:
		bool StartCalled = false;

	public:
		virtual void Update();
		virtual void Start();
		void processComponent();
	private:

	};
}