

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

using namespace DashEngine;

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

GLFWwindow* Engine::window = nullptr;


Engine::Engine() {
	//Create the Windows

	std::cout << "Starting DashEngine"<<std::endl;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WINDOWWIDTH, WINDOWHEIGHT,WINDOWTITLE,NULL,NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glViewport(0, 0, WINDOWWIDTH, WINDOWHEIGHT);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    

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
}


Engine::~Engine() {
	glfwTerminate();
}

bool Engine::isRunning() { return !glfwWindowShouldClose(window); }

void Engine::Update(Scene* scene)
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
	glfwSwapBuffers(window);
    
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
    Camera::ActiveCamera->CalculateProjectionMatrice();
}