#include "Hierarchy.h"
#include "Engine.h"

namespace DashEditor{
    using namespace DashEngine;
    Hierarchy::Hierarchy() :Window("Hierarchy") {
    }

    void Hierarchy::GUIUpdate()
    {   
        if(IsVisible)
            for(int i=0;i<Engine::Instance->ActiveScene->RootEntities.size();i++)
                DisplayEntity();
    }

    void Hierarchy:: DisplayEntity() {
        const bool Open = ImGui::TreeNodeEx("Entity", NULL);
    }
}