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
        ComponentEditor(const char* name);
    private:
        const char* m_name;
    };
}