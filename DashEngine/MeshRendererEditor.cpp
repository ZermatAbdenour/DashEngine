#include "MeshRendererEditor.h"
#include "MeshRenderer.h"
namespace DashEditor {

    void MeshRendererEditor::DrawComponent()
    {
        DashEngine::MeshRenderer* target = dynamic_cast<DashEngine::MeshRenderer*>(Target);
        //std::string a = std::to_string(target == nullptr );
        //ImGui::Text(a.c_str());

        char inputBuffer[256] = "";
        if (ImGui::InputText("Shader", inputBuffer, sizeof(inputBuffer))) {
            std::cout << "text changed"<<std::endl;
        }
        
    }
}