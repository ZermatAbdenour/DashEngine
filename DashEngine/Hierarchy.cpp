#include "Hierarchy.h"
#include "Inputs.h"


namespace DashEditor {
    using namespace DashEngine;
    std::vector<Entity*> Hierarchy::SelectedEntitys;
    void Hierarchy::ShowWindow()
    {
        if (!IsVisible)
            return;
        // Get the screen size
        ImVec2 screenSize = ImGui::GetIO().DisplaySize;
        ImGui::Begin("Hierarchy", &IsVisible);

        //add empty entity
        if (ImGui::Button("+")) {
            Entity* newEntity = new Entity();
            if (SelectedEntitys.size() == 1) {
                SelectedEntitys[0]->addChild(newEntity);
            }
            else {
                Engine::Instance->ActiveScene->AddEntitie(newEntity);
            }
        }

        ImGui::SameLine();

        //delete selected Entityes
        if (ImGui::Button("-")) {
 
            for (int i = SelectedEntitys.size()-1;i>= 0;i--) {
                if(SelectedEntitys[i]!= NULL)
                    SelectedEntitys[i]->Delete();
            }
            SelectedEntitys.clear();
        }

        ImGui::Separator();
        ImGui::BeginChild("child", ImVec2(ImGui::GetWindowContentRegionMax().x, ImGui::GetWindowContentRegionMax().y - 60));
        //Show Hierarchy
        for (int i = 0;i < Engine::Instance->ActiveScene->RootEntities.size();i++)
            DisplayEntity(Engine::Instance->ActiveScene->RootEntities[i]);
        //std::cout << Engine::Instance->ActiveScene->RootEntities[2]->Childs.size() <<std::endl;
        
        if (!ImGui::IsAnyItemHovered() && ImGui::IsWindowHovered() && ImGui::IsMouseClicked(0)) {
             SelectedEntitys.clear();
        }

        ImGui::EndChild();
        ImGui::End();
    }


    void Hierarchy::DisplayEntity(Entity* e) {
        if (!e->getVisibilityInHierarchy())
            return;

        ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags();
        if (e->Childs.size() == 0)
            flags |= ImGuiTreeNodeFlags_::ImGuiTreeNodeFlags_Leaf;

        //Selected Items
        auto it = std::find(SelectedEntitys.begin(), SelectedEntitys.end(), e);
        if (it != SelectedEntitys.end())
            flags |= ImGuiTreeNodeFlags_::ImGuiTreeNodeFlags_Selected;

        const std::string name = e->Name;
        const bool Open = ImGui::TreeNodeExV(std::to_string(e->entityID).c_str(), flags, name.c_str(), NULL);

        if (ImGui::IsItemClicked()) {
            if (Inputs::GetKey(KeyCode::LeftControl)) {
                SelectedEntitys.push_back(e);
            }
            else {
                SelectedEntitys.clear();
                SelectedEntitys.push_back(e);
            }

        }
        
        if (Open) {
            for (int i = 0;i < e->Childs.size();i++) {
                DisplayEntity(e->Childs[i]);
            }
            ImGui::TreePop();
        }

    }
}