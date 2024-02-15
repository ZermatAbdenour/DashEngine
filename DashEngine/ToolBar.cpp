#include "ToolBar.h"
#include <iostream>

namespace DashEditor {
    ToolBar::ToolBar() {

    }

    void ToolBar::ShowWindow()
    {
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("Options"))
            {
                // Disabling fullscreen would allow the window to be moved to the front of other windows,
                // which we can't undo at the moment without finer window depth/z control.
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }
    }
}