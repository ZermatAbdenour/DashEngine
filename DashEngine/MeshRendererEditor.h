#pragma once
#include "ComponentEditor.h"
#include "imgui.h"
namespace DashEditor {
    class MeshRendererEditor :public ComponentEditor
    {
    public:
        void DrawComponent() override;
        MeshRendererEditor() :ComponentEditor("Mesh Renderer") {}
    private:

    };
}

