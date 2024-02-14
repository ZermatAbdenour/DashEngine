#pragma once
#include <imgui.h>
namespace DashEditor {
    class Window {
    public:
        bool IsVisible = true;
        virtual void ShowWindow();

    private:
        const char* m_name;
    };

}