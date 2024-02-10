#include <imgui.h>
namespace DashEditor {
    class Window {
    public:
        Window(const char * name);
        bool IsVisible;
        void Begin();
        virtual void GUIUpdate();
        void End();
    private:
        const char* m_name;
    };

}