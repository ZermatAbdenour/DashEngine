

#include "Engine.h">
#include <iostream>
#include <glm/glm.hpp>
#include "DashEngineConfig.h"
#include "Shader.h"
#include "texture.h"
#include "Camera.h"
#include "TimeUtils.h"
#include "ResourceManagement.h"
#include"Inputs.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
using namespace DashEngine;

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Engine* Engine::Instance;

Engine::Engine() {
    //Set Engine Singleton
    Instance = this;

	//Create the Windows

	std::cout << "Starting DashEngine"<<std::endl;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window = glfwCreateWindow(STARTWINDOWWIDTH, STARTWINDOWHEIGHT,WINDOWTITLE,NULL,NULL);

	if (Window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(Window);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glViewport(0, 0, STARTWINDOWWIDTH, STARTWINDOWHEIGHT);
    WindowWidth = STARTWINDOWWIDTH;
    WindowHeight = STARTWINDOWHEIGHT;
	glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);

    glEnable(GL_DEPTH_TEST);
    //Enable Blending to render transparent textures
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //load Resources
    ResourceManagement::LoadResources();

    //Set Delta Time to 0
    TimeUtils::deltaTime = 0;

    //Init Inputs

    Inputs::InitInputs();

    std::cout << "Engine Fully loaded"<<std::endl;

    Assimp::Importer importer;
}


Engine::~Engine() {
	glfwTerminate();
}

bool Engine::isRunning() { return !glfwWindowShouldClose(Window); }

void Engine::Load(Scene* scene) {
    ActiveScene = scene;
    while (isRunning())
    {
        TimeUtils::deltaTime = glfwGetTime() - TimeUtils::time;
        TimeUtils::time = glfwGetTime();
        //Inputs
        Inputs::Instance->ProcessInputs();
        //Rendering

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        scene->RenderScene();

        // glfw: swap buffers and poll IO events 
        glfwSwapBuffers(Window);
    }
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
    Engine::Instance->WindowWidth = width;
    Engine::Instance->WindowHeight = height;
    Camera::ActiveCamera->CalculateProjectionMatrice();
}