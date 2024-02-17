#include "Engine.h">
#include <iostream>
#include <glm/glm.hpp>
#include "DashEngineConfig.h"
#include "Camera.h"
#include "Editor.h"
#include "TimeUtils.h"
#include "ResourceManagement.h"
#include"Inputs.h"
#include <assimp/Importer.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include "Hierarchy.h"
#include "ToolBar.h"
#include "Inspector.h"
#include "FrameBuffer.h"
#include "BufferTexture.h"

namespace DashEngine {
    using namespace DashEditor;

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    Engine* Engine::Instance;

    Engine::Engine() {
        //Set Engine Singleton
        Instance = this;

        //Create the Windows

        std::cout << "Starting DashEngine" << std::endl;

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        Window = glfwCreateWindow(STARTWINDOWWIDTH, STARTWINDOWHEIGHT, WINDOWTITLE, NULL, NULL);

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

        //Settup ImGUI
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        (void)io;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(Window, true);
        ImGui_ImplOpenGL3_Init("#version 330");


        glEnable(GL_DEPTH_TEST);
        //Enable Blending to render transparent textures
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        //Stencil test
        glEnable(GL_STENCIL_TEST);

        //Cull faces
        glEnable(GL_CULL_FACE);


        //load Resources
        ResourceManagement::LoadResources();

        //Set Delta Time to 0
        TimeUtils::deltaTime = 0;

        //Init Inputs

        Inputs::InitInputs();

        //Init Editor
        Editor::Init();

        std::cout << "Engine Fully loaded" << std::endl;
    }


    Engine::~Engine() {
        glfwTerminate();

        ImGui_ImplGlfw_Shutdown();
        ImGui_ImplOpenGL3_Shutdown();
        ImGui::DestroyContext();
    }

    bool Engine::isRunning() { return !glfwWindowShouldClose(Window); }

    void Engine::Load(Scene* scene) {
        ActiveScene = scene;

  
        while (isRunning())
        {
            TimeUtils::deltaTime = glfwGetTime() - TimeUtils::time;
            TimeUtils::time = glfwGetTime();

            //std::cout << 1/TimeUtils::deltaTime << std::endl;

            //Rendering

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            Editor::Update();
            glfwSwapBuffers(Window);
            Inputs::Instance->ProcessInputs();
        }
    }

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
        Engine::Instance->WindowWidth = width;
        Engine::Instance->WindowHeight = height;
        Camera::ActiveCamera->CalculateProjectionMatrice();
    }
}