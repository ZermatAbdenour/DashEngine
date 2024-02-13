#include "ComponentEditor.h"
#include "Component.h"
#include<stdio.h>
#include <imgui.h>
namespace DashEditor {
    void ComponentEditor::DrawEditor()
    {
        ImGui::BeginChild("Component");
        DrawComponent();
        ImGui::Separator();
        ImGui::EndChild();
    }
    void ComponentEditor::DrawComponent()
    {

    }
}