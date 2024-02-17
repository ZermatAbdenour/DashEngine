#include "ComponentEditor.h"
#include "Component.h"
#include<stdio.h>
#include <imgui.h>

namespace DashEditor {
    void ComponentEditor::DrawEditor()
    {
        if (!ImGui::CollapsingHeader(m_name))
            return;
        DrawComponent();
        ImGui::Separator();
    }
    void ComponentEditor::DrawComponent()
    {

    }

    ComponentEditor::ComponentEditor(const char* name)
    {
        m_name = name;
    }

}