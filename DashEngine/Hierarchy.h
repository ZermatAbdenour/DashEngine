#pragma once
#include "Window.h"
#include "Engine.h"

namespace DashEditor {
    using namespace DashEngine;
    class Hierarchy :public Window{
    public:
        Hierarchy();
        void ShowWindow()override;
        void DisplayEntity(Entity* e);
    };
}