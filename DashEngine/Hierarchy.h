#pragma once
#include "Window.h"
namespace DashEditor {
    class Hierarchy :public Window{
    public:
        Hierarchy();
        void GUIUpdate() override;
        void DisplayEntity();
    };
}