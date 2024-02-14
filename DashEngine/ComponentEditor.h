#pragma once

namespace DashEngine {
    class Component;
}
namespace DashEditor {
    class ComponentEditor
    {
    public:
        DashEngine::Component* Target;
        void DrawEditor();
        virtual void DrawComponent();

    private:

    };
}