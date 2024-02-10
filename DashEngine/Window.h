#include <imgui.h>
namespace DashEditor {
    class Window {
    public:
        Window();
        bool IsVisible;
        virtual void Begin();
        virtual void GUIUpdate();
        virtual void End();
    private:
        const char* m_name;
    };

}