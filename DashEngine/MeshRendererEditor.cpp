#include "MeshRendererEditor.h"
namespace DashEditor {

    void MeshRendererEditor::DrawComponent()
    {
        ImGui::BeginChild("MeshRenderer");
        ImGui::Text("A MeshRenderer Editor");
        ImGui::EndChild();
    }
}