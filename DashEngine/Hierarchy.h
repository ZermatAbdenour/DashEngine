#pragma once
#include "Window.h"
#include "Entity.h"

namespace DashEditor {
    using namespace DashEngine;
    class Hierarchy :public Window{
    public:
        static std::vector<Entity*> SelectedEntitys;
    public:
        void ShowWindow()override;
        void DisplayEntity(Entity* e);
    private:
    };
}