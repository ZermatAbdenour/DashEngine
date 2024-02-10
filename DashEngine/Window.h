#pragma once
#include <imgui.h>
namespace DashEditor {
    class Window {
    public:
        Window();
        bool IsVisible = true;
        virtual void ShowWindow();

    private:
        const char* m_name;
    };

}