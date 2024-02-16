#include "Editor.h"

using namespace DashEditor;
ToolBar* Editor::m_toolbar;
Hierarchy* Editor::m_hierarchy;
Inspector* Editor::m_inspector;
void Editor::Init()
{
    m_toolbar = new ToolBar();
    m_hierarchy = new Hierarchy();
    m_inspector = new Inspector();
}

void Editor::Update() {

    m_toolbar->ShowWindow();
    m_hierarchy->ShowWindow();
    m_inspector->ShowWindow();
}
