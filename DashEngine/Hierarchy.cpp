#include "Hierarchy.h"


namespace DashEditor{
    using namespace DashEngine;
    Hierarchy::Hierarchy() {
    }
    void Hierarchy::Begin() {
        if (IsVisible) {
            // Get the screen size
            ImVec2 screenSize = ImGui::GetIO().DisplaySize;

            ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
            ImGui::SetNextWindowSizeConstraints(ImVec2(screenSize.x/5, screenSize.y), ImVec2(screenSize.x / 4, screenSize.y));

            ImGuiWindowFlags flags = ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse ;
            ImGui::Begin("Hierarchy", &IsVisible, flags);
        }
    }

    void Hierarchy::GUIUpdate()
    {   

        if (IsVisible);
            for(int i=0;i<Engine::Instance->ActiveScene->RootEntities.size();i++)
                DisplayEntity(Engine::Instance->ActiveScene->RootEntities[i]);
    }

    void Hierarchy::DisplayEntity(Entity *e) {
        ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags();
        if (e->Childs.size() == 0)
            flags |= ImGuiTreeNodeFlags_::ImGuiTreeNodeFlags_Leaf;
        const std::string name = e->Name;
        const bool Open = ImGui::TreeNodeExV(std::to_string(e->entityID).c_str(), flags, name.c_str(), NULL);
        if (Open) {
            for (int i = 0;i < e->Childs.size();i++) {
                DisplayEntity(e->Childs[i]);
            }
            ImGui::TreePop();
        }
    }
}