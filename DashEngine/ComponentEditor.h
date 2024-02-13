#pragma once

namespace DashEngine {
    class Component;
}
namespace DashEditor {
    class ComponentEditor
    {
    public:
        DashEngine::Component* component;
        void DrawEditor();
        virtual void DrawComponent();

    private:

    };
}