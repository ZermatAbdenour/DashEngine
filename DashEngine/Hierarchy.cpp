#include "Hierarchy.h"


namespace DashEditor {
    using namespace DashEngine;
    Hierarchy::Hierarchy() {
    }
    void Hierarchy::ShowWindow()
    {

        if (!IsVisible)
            return;
        // Get the screen size
        ImVec2 screenSize = ImGui::GetIO().DisplaySize;
        ImGui::SetNextWindowPos(ImVec2(0, 32), ImGuiCond_Always);
        ImGui::SetNextWindowSizeConstraints(ImVec2(screenSize.x / 5, screenSize.y), ImVec2(screenSize.x / 4, screenSize.y));
        ImGuiWindowFlags flags = ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse;

        ImGui::Begin("Hierarchy", &IsVisible, flags);

        ImGui::BeginChild("child", ImVec2(ImGui::GetWindowContentRegionMax().x, 30));
        ImGui::Button("+");
        ImGui::SameLine();
        ImGui::Button("-");
        ImGui::Separator();
        ImGui::EndChild();
        //Show Hierarchy
        for (int i = 0;i < Engine::Instance->ActiveScene->RootEntities.size();i++)
            DisplayEntity(Engine::Instance->ActiveScene->RootEntities[i]);

        ImGui::End();
    }


    void Hierarchy::DisplayEntity(Entity* e) {
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