#pragma once

#include "Window.h"
namespace DashEditor {
    class Inspector :public Window {
    public:
        Inspector();
        void ShowWindow() override;
    private:
    };
}