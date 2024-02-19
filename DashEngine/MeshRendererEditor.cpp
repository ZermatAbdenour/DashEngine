#include "MeshRendererEditor.h"
#include "MeshRenderer.h"
namespace DashEditor {

    void MeshRendererEditor::DrawComponent()
    {
        DashEngine::MeshRenderer* target = dynamic_cast<DashEngine::MeshRenderer*>(Target);
        //std::string a = std::to_string(target == nullptr );
        //ImGui::Text(a.c_str());
        ImGui::Text("Vertices: %i", target->mesh->Vertices.size());
        ImGui::Text("Indices: %i", target->mesh->Indices.size());
    }
}