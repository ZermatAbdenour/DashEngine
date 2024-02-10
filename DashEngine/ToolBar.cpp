#include "ToolBar.h"
#include <iostream>

namespace DashEditor {
    ToolBar::ToolBar() {

    }

    void ToolBar::ShowWindow()
    {
        if (!IsVisible)
            return;
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(ImVec2(viewport->Pos.x, viewport->Pos.y));
        ImGui::SetNextWindowSize(ImVec2(viewport->Size.x, 30));
        ImGuiWindowFlags window_flags = 0
            | ImGuiWindowFlags_NoTitleBar
            | ImGuiWindowFlags_NoResize
            | ImGuiWindowFlags_NoMove
            | ImGuiWindowFlags_NoScrollbar
            | ImGuiWindowFlags_NoSavedSettings
            ;
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1, 0.1, 0.11, 1));
        ImGui::Begin("TOOLBAR", NULL, window_flags);
        ImGui::PopStyleVar();
        ImGui::PopStyleColor();
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.1, 0.1, 0.11, 1));
        ImGui::Button("File");

        ImGui::SameLine();
        ImGui::Button("Assets");
        ImGui::PopStyleColor();
        ImGui::End();
    }
}