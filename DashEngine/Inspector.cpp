#include "Inspector.h"
#include "Hierarchy.h"
#include "ComponentEditor.h"
#include "Engine.h"
#include <glm/gtc/type_ptr.hpp>

namespace DashEditor {
    Inspector::Inspector()
    {

    }
    void Inspector::ShowWindow()
    {
        ImGui::Begin("Inspector", &IsVisible);

        if (Hierarchy::SelectedEntitys.size() == 0) {
            ImGui::End();
            return;
        }
        //Draw the Entity editor
        ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_DefaultOpen;
        if (ImGui::CollapsingHeader("Entity", flags)) {
            ImGui::BeginChild("Entity Editor");
            ImGui::DragFloat3("Position", glm::value_ptr(Hierarchy::SelectedEntitys[0]->LocalPosition));
            ImGui::DragFloat3("Rotation", glm::value_ptr(Hierarchy::SelectedEntitys[0]->EulerAngles));
            ImGui::DragFloat3("Scale", glm::value_ptr(Hierarchy::SelectedEntitys[0]->Scale));
            ImGui::Separator();
            ImGui::EndChild();
        }

        //Draw the component editor
        for (int i = 0;i < Hierarchy::SelectedEntitys[0]->Components.size();i++) {
            if(Hierarchy::SelectedEntitys[0]->Components[i]->Editor)
                Hierarchy::SelectedEntitys[0]->Components[i]->Editor->DrawEditor();
        }

        ImGui::End();
    }
}
