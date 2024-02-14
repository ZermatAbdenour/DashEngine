#include "MeshRendererEditor.h"
#include "MeshRenderer.h"
namespace DashEditor {

    void MeshRendererEditor::DrawComponent()
    {
        DashEngine::MeshRenderer* target = dynamic_cast<DashEngine::MeshRenderer*>(Target);
        ImGui::Text("MeshRenderer");
        std::string a = std::to_string(target->mesh->Vertices.size() );
        ImGui::Text(a.c_str());
        
    }
}