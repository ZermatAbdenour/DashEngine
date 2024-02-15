#include "PrespectiveCameraEditor.h"
#include "PrespectiveCamera.h"
#include <imgui.h>
#include <string_view>
#include <string>
namespace DashEditor {
    void PrespectiveCameraEditor::DrawComponent()
    {


        DashEngine::PrespectiveCamera* target = dynamic_cast<DashEngine::PrespectiveCamera*>(Target);
        //ItemLabel("Fov", ItemLabelFlag::Right);
        ImGui::DragFloat("Fov", &target->FovY);
        ImGui::DragFloat("Far plane", &target->FarPlane);
        ImGui::DragFloat("Near plane", &target->NearPlane);
    }

}
