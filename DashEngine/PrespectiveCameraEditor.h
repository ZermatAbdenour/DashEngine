#pragma once
#include"ComponentEditor.h"
namespace DashEditor {
    class PrespectiveCameraEditor :public ComponentEditor
    {
    public:
        void DrawComponent() override;
        PrespectiveCameraEditor() :ComponentEditor("Prespective Camera"){}
    };
}

