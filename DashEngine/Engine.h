#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Scene.h"

namespace DashEditor {
    class Editor;
}

namespace DashEngine {
    using namespace DashEditor;
	class Engine
	{
    public:
        static Engine* Instance;
        int WindowWidth, WindowHeight;
        GLFWwindow* Window;
        Scene* ActiveScene;
	public:
		Engine();
		~Engine();
		bool isRunning();
        void Load(Scene* scene);
    private:
        DashEditor::Editor* m_editor;
	};
}

#endif // ENGINE_H