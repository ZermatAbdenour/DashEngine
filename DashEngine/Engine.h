#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Scene.h"

namespace DashEngine {
	class Engine
	{
	public:
		Engine();
		~Engine();
		bool isRunning();
		void Update(Scene* scene);

	private:
		
	public:
		static GLFWwindow* window;
	};
}

#endif // ENGINE_H