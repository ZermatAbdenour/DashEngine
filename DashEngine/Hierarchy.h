#pragma once
#include "Window.h"
#include "Engine.h"

namespace DashEditor {
    using namespace DashEngine;
    class Hierarchy :public Window{
    public:
        Hierarchy();
        void Begin() override;
        void GUIUpdate() override;
        void DisplayEntity(Entity* e);
    };
}