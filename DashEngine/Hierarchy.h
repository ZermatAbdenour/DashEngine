#pragma once
#include "Window.h"
#include "Engine.h"

namespace DashEditor {
    using namespace DashEngine;
    class Hierarchy :public Window{
    public:
        static std::vector<Entity*> SelectedEntitys;
    public:
        void ShowWindow()override;
        void DisplayEntity(Entity* e,int displayIndex);
    private:
        bool m_clear;
        int m_entityDisplayIndex;
        int m_shiftFistSelected = -1,m_shiftLastSelected =-1;
    };
}