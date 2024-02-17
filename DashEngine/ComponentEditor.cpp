#include "ComponentEditor.h"
#include "Component.h"
#include<stdio.h>
#include <imgui.h>

namespace DashEditor {
    void ComponentEditor::DrawEditor()
    {
        if (!ImGui::CollapsingHeader(m_name))
            return;
        ImGui::BeginChild("Component");
        DrawComponent();
        ImGui::Separator();
        ImGui::EndChild();
    }
    void ComponentEditor::DrawComponent()
    {

    }

    ComponentEditor::ComponentEditor(const char* name)
    {
        m_name = name;
    }

}