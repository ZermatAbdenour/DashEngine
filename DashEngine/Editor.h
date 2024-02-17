#pragma once
#include "ToolBar.h"
#include "Hierarchy.h"
#include "Inspector.h"
#include "SceneView.h"

namespace DashEditor {
    class Editor {
    public:
        static void Init();
        static void Update();
        static void EndFrame();
    private:
        static ToolBar* m_toolbar;
        static Hierarchy* m_hierarchy;
        static Inspector* m_inspector;
        static SceneView* m_sceneView;
    };
}