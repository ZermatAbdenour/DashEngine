#include "Inspector.h"
#include "Hierarchy.h"
#include "ComponentEditor.h"

namespace DashEditor {
    Inspector::Inspector()
    {

    }
    void Inspector::ShowWindow()
    {
        ImGuiWindowFlags flags =  ImGuiWindowFlags_NoCollapse;
        ImGui::Begin("Inspector", &IsVisible, flags);

        if (Hierarchy::SelectedEntitys.size() == 0) {
            ImGui::End();
            return;
        }

        for (int i = 0;i < Hierarchy::SelectedEntitys[0]->Components.size();i++) {
            Hierarchy::SelectedEntitys[0]->Components[i]->Editor->DrawEditor();
        }

        ImGui::End();
    }
}
