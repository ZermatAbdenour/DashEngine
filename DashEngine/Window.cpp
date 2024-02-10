#include "Window.h"

namespace DashEditor {
    Window::Window(const char* name)
    {
        m_name = name;
    }
    void Window::Begin()
    {
        if (IsVisible) {
            ImGui::Begin(m_name, &IsVisible);
        }
    }
    void Window::GUIUpdate()
    {

    }
    void Window::End()
    {
        if(IsVisible)
            ImGui::End();
    }
}

