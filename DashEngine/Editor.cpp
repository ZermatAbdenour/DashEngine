#include "Editor.h"
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

using namespace DashEditor;
ToolBar* Editor::m_toolbar;
Hierarchy* Editor::m_hierarchy;
Inspector* Editor::m_inspector;
SceneView* Editor::m_sceneView;
void Editor::Init()
{
    m_toolbar = new ToolBar();
    m_hierarchy = new Hierarchy();
    m_inspector = new Inspector();
    m_sceneView = new SceneView();
}

void Editor::Update() {

    //Imgui new frame
    ImGui_ImplGlfw_NewFrame();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

    m_toolbar->ShowWindow();
    m_hierarchy->ShowWindow();
    m_inspector->ShowWindow();
    m_sceneView->ShowWindow();
    m_sceneView->ProcessScene();
    //RenderImGui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
