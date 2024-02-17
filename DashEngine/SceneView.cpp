#include "SceneView.h"

#include "DashEngineConfig.h"
#include "SceneView.h"
#include "PrespectiveCamera.h"
#include "Engine.h"
using namespace DashEditor;

SceneView::SceneView() : m_colorTexture(STARTWINDOWWIDTH, STARTWINDOWHEIGHT, DashEngine::Color),
m_depthStencilTexture(STARTWINDOWWIDTH, STARTWINDOWHEIGHT, DashEngine::DepthStencil)
{
    m_frameBuffer.SetColorAttachment(m_colorTexture.ID);
    m_frameBuffer.SetDepthStencilAttachment(m_depthStencilTexture.ID);
    windowSize = { STARTWINDOWWIDTH , STARTWINDOWHEIGHT };
    m_frameBuffer.Bind();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_STENCIL_TEST);
    m_frameBuffer.Unbind();

}


void SceneView::ShowWindow()
{
    ImGui::Begin("Scene view", &IsVisible);

    glm::vec2 currentWindowSize = { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y };
    if (currentWindowSize != windowSize) {
        m_colorTexture.Bind();
        m_colorTexture.UpdateTextureBuffer(currentWindowSize.x, currentWindowSize.y, DashEngine::Color);
        m_colorTexture.Unbind();
        m_depthStencilTexture.Bind();
        m_depthStencilTexture.UpdateTextureBuffer(currentWindowSize.x, currentWindowSize.y, DashEngine::DepthStencil);
        m_depthStencilTexture.Bind();
        windowSize = currentWindowSize;
    }
    ImGui::Image(ImTextureID(m_colorTexture.ID), { windowSize.x,windowSize.y }, ImVec2(0, 1), ImVec2(1, 0));
    ImGui::End();
}

void DashEditor::SceneView::ProcessScene()
{
    m_frameBuffer.Bind();
    glViewport(0, 0, windowSize.x, windowSize.y);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    DashEngine::Camera::SetCurrentSize(windowSize.x, windowSize.y);
    DashEngine::Engine::Instance->ActiveScene->RenderScene();
    m_frameBuffer.Unbind();
}
