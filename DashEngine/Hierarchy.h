#pragma once
#include "Window.h"
#include "Engine.h"

namespace DashEditor {
    using namespace DashEngine;
    class Hierarchy :public Window{
    public:
        std::vector<Entity*> SelectedEntitys;
    public:
        Hierarchy();
        void ShowWindow()override;
        void DisplayEntity(Entity* e,int displayIndex);
    private:
        int m_entityDisplayIndex;
        int m_shiftFistSelected = -1,m_shiftLastSelected =-1;
    };
}