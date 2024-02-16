#include "Inspector.h"
#include "Hierarchy.h"
#include "ComponentEditor.h"
#include "Engine.h"

namespace DashEditor {
    Inspector::Inspector()
    {

    }
    void Inspector::ShowWindow()
    {
        ImGuiWindowFlags flags =  ImGuiWindowFlags_NoCollapse;
        ImGui::Begin("Inspector", &IsVisible);

        if (Hierarchy::SelectedEntitys.size() == 0) {
            ImGui::End();
            return;
        }

        for (int i = 0;i < Hierarchy::SelectedEntitys[0]->Components.size();i++) {
            if(Hierarchy::SelectedEntitys[0]->Components[i]->Editor)
                Hierarchy::SelectedEntitys[0]->Components[i]->Editor->DrawEditor();
        }

        ImGui::End();
    }
}
