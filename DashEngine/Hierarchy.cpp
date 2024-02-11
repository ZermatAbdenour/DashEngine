#include "Hierarchy.h"
#include "Inputs.h"


namespace DashEditor {
    using namespace DashEngine;
    Hierarchy::Hierarchy() {
    }
    void Hierarchy::ShowWindow()
    {
        m_entityDisplayIndex = 0;

        if (!IsVisible)
            return;
        // Get the screen size
        ImVec2 screenSize = ImGui::GetIO().DisplaySize;
        ImGui::SetNextWindowPos(ImVec2(0, 32), ImGuiCond_Always);
        ImGui::SetNextWindowSizeConstraints(ImVec2(screenSize.x / 5, screenSize.y -32), ImVec2(screenSize.x / 4, screenSize.y -32));
        ImGuiWindowFlags flags = ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse;


        ImGui::Begin("Hierarchy", &IsVisible, flags);
        ImGui::Button("+");
        ImGui::SameLine();

        if (ImGui::Button("-")&& SelectedEntitys.size()>0) {
            for (int i = 0;i < SelectedEntitys.size();i--) {
                if(SelectedEntitys[i]!= nullptr)
                    SelectedEntitys[i]->Delete();
            }
            SelectedEntitys.clear();
            m_shiftFistSelected = -1;
            m_shiftLastSelected = -1;
        }
        ImGui::Separator();
        ImGui::BeginChild("child", ImVec2(ImGui::GetWindowContentRegionMax().x, ImGui::GetWindowContentRegionMax().y - 36));
        //Show Hierarchy
        for (int i = 0;i < Engine::Instance->ActiveScene->RootEntities.size();i++)
            DisplayEntity(Engine::Instance->ActiveScene->RootEntities[i],m_entityDisplayIndex++);

        ImGui::EndChild();
        ImGui::End();
    }


    void Hierarchy::DisplayEntity(Entity* e,int displayIndex) {
        ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags();
        if (e->Childs.size() == 0)
            flags |= ImGuiTreeNodeFlags_::ImGuiTreeNodeFlags_Leaf;

        //Selected Items
        auto it = std::find(SelectedEntitys.begin(), SelectedEntitys.end(), e);
        if (it != SelectedEntitys.end() || displayIndex>=fmin(m_shiftFistSelected,m_shiftLastSelected) && displayIndex <= fmax(m_shiftFistSelected, m_shiftLastSelected))
            flags |= ImGuiTreeNodeFlags_::ImGuiTreeNodeFlags_Selected;

        const std::string name = e->Name;
        const bool Open = ImGui::TreeNodeExV(std::to_string(e->entityID).c_str(), flags, name.c_str(), NULL);

        if (ImGui::IsItemClicked()) {
            m_shiftFistSelected = displayIndex;
            if (!Inputs::GetKey(KeyCode::LeftShift)) {
                m_shiftLastSelected = displayIndex;
            }
            if (Inputs::GetKey(KeyCode::LeftControl)) {
                SelectedEntitys.push_back(e);
            }
            else {
                SelectedEntitys.clear();
                SelectedEntitys.push_back(e);
            }

        }
        //Check if the items in between the fist and the last
        if (displayIndex >= fmin(m_shiftFistSelected, m_shiftLastSelected) && displayIndex <= fmax(m_shiftFistSelected, m_shiftLastSelected)) {
            auto it = std::find(SelectedEntitys.begin(), SelectedEntitys.end(), e);
            if (it == SelectedEntitys.end()) {
                SelectedEntitys.push_back(e);
            }
        }
        
        if (Open) {
            for (int i = 0;i < e->Childs.size();i++) {
                DisplayEntity(e->Childs[i],m_entityDisplayIndex++);
            }
            ImGui::TreePop();
        }

    }
}