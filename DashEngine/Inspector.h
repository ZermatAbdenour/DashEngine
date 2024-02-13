#pragma once

#include "Window.h"
#include "Engine.h"

namespace DashEditor {
    using namespace DashEngine;
    class Inspector :public Window {
    public:
        Inspector();
        void ShowWindow() override;
    private:
    };
}