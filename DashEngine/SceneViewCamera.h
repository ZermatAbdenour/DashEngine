#pragma once
#include "Component.h"
namespace DashEngine {
    class SceneViewCamera:public DashEngine::Component
    {
    public:
        void Start()override;
        void Update()override;
    private:
        bool m_disablCursor;
    };
}