#pragma once
#include "DashEngineConfig.h"
#include "Window.h"
#include "FrameBuffer.h"
#include "BufferTexture.h"
#include "Camera.h"
#include "glm/glm.hpp"
namespace DashEditor {
    class SceneView : public Window {
    public:
        void ShowWindow() override;
        void ProcessScene();
        SceneView();
        glm::vec2 windowSize;
    private:
        DashEngine::FrameBuffer m_frameBuffer;
        DashEngine::BufferTexture m_colorTexture;
        DashEngine::BufferTexture m_depthStencilTexture;
    };
}