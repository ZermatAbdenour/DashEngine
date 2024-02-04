#include "Inputs.h"
#include "DashEngineConfig.h"

namespace DashEngine {
    Inputs* Inputs::Instance = nullptr;
    glm::vec2 Inputs::Mouse::position = glm::vec2();
    glm::vec2 Inputs::Mouse::delta = glm::vec2();

    //keyboard buttons
    bool Inputs::keys[GLFW_KEY_LAST] = { false };
    bool Inputs::keysUp[GLFW_KEY_LAST] = { false };
    bool Inputs::keysDown[GLFW_KEY_LAST] = { false };

    //mouse buttons
    bool Inputs::mouse[GLFW_MOUSE_BUTTON_LAST] = { false };
    bool Inputs::mouseUp[GLFW_MOUSE_BUTTON_LAST] = { false };
    bool Inputs::mouseDown[GLFW_MOUSE_BUTTON_LAST] = { false };

    Inputs::Inputs(GLFWwindow* window)
    {
        this->window = window;
    }

    void Inputs::ProcessInputs()
    {
        glfwPollEvents();
        int width, height;
        glfwGetWindowSize(window, &width, &height);

        //Process mouse
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        //xpos =  ((float)Engine::Instance->WindowWidth / width) * xpos;
        //ypos = STARTWINDOWHEIGHT- ((float)STARTWINDOWHEIGHT / height) * ypos;
        ypos = Engine::Instance->WindowHeight - ypos;
        glm::vec2 newposition = glm::vec2(xpos, ypos);

        Inputs::Mouse::delta = newposition - Inputs::Mouse::position;
        Inputs::Mouse::position = newposition;

        //ProcessKeys
        for (unsigned int i = 32;i <= 96;i++) {
            ProcesssKey(i);
        }
        for (unsigned int i = 255; i < GLFW_KEY_LAST; i++) {
            ProcesssKey(i);
        }

        //Process mouse buttons
        for (unsigned int i = 0;i < GLFW_MOUSE_BUTTON_LAST;i++) {
            ProcesssMouseButton(i);
        }
    }

    void DashEngine::Inputs::ProcesssKey(unsigned int key)
    {
        if (glfwGetKey(window, key) == GLFW_PRESS) {
            if (keys[key] == false) {
                keys[key] = true;
                keysDown[key] = true;
            }
            else
                keysDown[key] = false;
        }
        if (glfwGetKey(window, key) == GLFW_RELEASE) {
            if (keys[key] == true) {
                keys[key] = false;
                keysUp[key] = true;
            }
            else
                keysUp[key] = false;
        }
    }

    void DashEngine::Inputs::ProcesssMouseButton(unsigned int button)
    {
        if (glfwGetMouseButton(window, button) == GLFW_PRESS) {
            if (mouse[button] == false) {
                mouse[button] = true;
                mouseDown[button] = true;
            }
            else
                mouseDown[button] = false;
        }


        if (glfwGetMouseButton(window, button) == GLFW_RELEASE) {
            if (mouse[button] == true) {
                mouse[button] = false;
                mouseUp[button] = true;
            }
            else
                mouseUp[button] = false;
        }
    }

    Inputs* Inputs::InitInputs()
    {
        if (Instance == nullptr)
            Instance = new Inputs(Engine::Instance->Window);
        return Instance;
    }

    void Inputs::Mouse::SetCursorMode(CursorMode cursormode)
    {
        glfwSetInputMode(Engine::Instance->Window, GLFW_CURSOR, cursormode);
    }
}
