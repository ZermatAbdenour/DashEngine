#pragma once
#pragma once

#include "imgui.h"
#include "imgui_internal.h"

static bool renderFrameContent(const char* title, bool* value);
static void example01(const char* name, bool debug);
static void example02(const char* name, bool* isOpen, bool debug);
static void example03(const char* name, bool* isOpen1, bool* isOpen2, bool* isOpen3, bool debug);

static bool DEBUG = false;

namespace ImGui
{
    inline bool BeginChildEx(const char* id, float sizeX, float paddingX, float paddingY)
    {
        ImGuiContext& g = *GImGui;
        ImGuiWindow* parent_window = g.CurrentWindow;

        ImGuiWindowFlags flags = 0;
        flags |= ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_ChildWindow | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_AlwaysUseWindowPadding;
        flags |= (parent_window->Flags & ImGuiWindowFlags_NoMove);  // Inherit the NoMove flag

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 4.f, 4.f });

        const float backup_border_size = g.Style.ChildBorderSize;
        g.Style.ChildBorderSize = 0.0f;
        bool ret = ImGui::Begin(id, NULL, flags);
        g.Style.ChildBorderSize = backup_border_size;

        ImGui::PopStyleVar();

        return ret;
    };

    inline void EndChildEx()
    {
        ImGuiContext& g = *GImGui;
        ImGuiWindow* window = g.CurrentWindow;

        float bottomOffset = g.Style.ItemSpacing.y;
        float y = ImGui::GetCursorPosY() - bottomOffset;

        ImDrawList* drawList = ImGui::GetWindowDrawList();
        ImVec2 vec = ImGui::GetCursorStartPos();

        float windowX = window->Pos.x + vec.x;
        float windowY = window->Pos.y + vec.y;

        float windowPaddingX = windowX - window->WindowPadding.x;
        float windowPaddingY = windowY - window->WindowPadding.y;

        float windowWidth = window->Size.x - window->WindowPadding.x * 2;
        float windowHeight = y - window->WindowPadding.y;

        float windowPaddingWidth = windowWidth + window->WindowPadding.x * 2;
        float windowPaddingHeight = windowHeight + window->WindowPadding.y * 2;

        ImGui::SetWindowSize(ImVec2(window->ParentWindow->ContentsRegionRect.GetWidth(), windowPaddingHeight));

        ImGui::EndChild();

        if (DEBUG) {
            float rounding = 0;
            //Render space + padding
            drawList->AddRect(ImVec2(windowPaddingX, windowPaddingY), ImVec2(windowPaddingX + windowPaddingWidth, windowPaddingY + windowPaddingHeight), ImGui::GetColorU32(ImVec4(255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f)), rounding);

            // Render space
            drawList->AddRect(ImVec2(windowX, windowY), ImVec2(windowX + windowWidth, windowY + windowHeight), ImGui::GetColorU32(ImVec4(0.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f)), rounding);
        }
    };

    inline bool BeginCollapsingHeaderEx(const char* id, const char* title, bool* isOpen, float sizeX, float paddingX, float paddingY)
    {
        ImGuiContext& g = *GImGui;
        float getFrameHeight = ImGui::GetFrameHeight();
        ImGui::BeginGroup();

        ImGui::BeginGroup();
        ImGui::PushID("id");

        ImDrawList* drawList = ImGui::GetWindowDrawList();

        ImVec2 vec = ImGui::GetCursorScreenPos();
        float screenPosX = vec.x;
        float screenPosY = vec.y;
        float windowWidth = ImGui::GetWindowContentRegionWidth();

        ImU32 frameColor = ImGui::GetColorU32(ImVec4(0x24 / 255.0f, 0x24 / 255.0f, 0x24 / 255.0f, 255 / 255.0f));

        int borderRound = 4;

        int roundingCorners = ImDrawCornerFlags_TopLeft | ImDrawCornerFlags_TopRight;

        drawList->AddRectFilled(ImVec2(screenPosX, screenPosY), ImVec2(screenPosX + windowWidth, screenPosY + getFrameHeight), frameColor, borderRound, roundingCorners);

        bool flag = renderFrameContent(title, isOpen);

        ImGui::PopID();
        ImGui::EndGroup();

        float bk = g.Style.ItemSpacing.y;
        g.Style.ItemSpacing.y = 0;
        int offset = 0;

        if (flag)
            offset = bk;

        ImGui::ItemSize(ImVec2(windowWidth, getFrameHeight - offset));
        g.Style.ItemSpacing.y = bk;

        float y = ImGui::GetCursorPosY();

        ImVec2 vec2 = ImGui::GetCursorScreenPos();

        float height = screenPosY + getFrameHeight;

        vec2 = ImGui::GetCursorScreenPos();

        if (flag)
            ImGui::BeginChildEx(id, sizeX, paddingX, paddingY);
        return flag;
    };

    inline void EndCollapsingHeaderEx(bool isOpen)
    {
        ImGuiContext& g = *GImGui;

        float height = 0;

        ImGuiWindow* childWindow = NULL;
        ImGuiWindow* parentWindow = NULL;

        if (isOpen) {
            childWindow = g.CurrentWindow;
            ImGui::EndChildEx();
        }

        parentWindow = g.CurrentWindow;

        float bk = g.Style.ItemSpacing.y;

        if (!isOpen)
            g.Style.ItemSpacing.y = 0;
        ImGui::EndGroup();
        if (!isOpen)
            g.Style.ItemSpacing.y = bk;

        float getFrameHeight = ImGui::GetFrameHeight();
        ImVec2 vec = ImGui::GetCursorScreenPos();
        float screenPosX = parentWindow->DC.CursorPos.x;
        float screenPosY = parentWindow->DC.CursorPosPrevLine.y;

        float windowWidth = ImGui::GetWindowContentRegionWidth();
        int offset = 0;
        if (isOpen)
            offset = g.Style.ItemSpacing.y;

        if (childWindow != NULL)
            height = childWindow->Size.y + screenPosY + getFrameHeight;
        else
            height = screenPosY + getFrameHeight;

        ImDrawList* drawList = ImGui::GetWindowDrawList();

        windowWidth = ImGui::GetWindowContentRegionWidth();

        float rounding = 5;

        int roundingCorners = ImDrawCornerFlags_TopLeft | ImDrawCornerFlags_TopRight;

        ImU32 borderColor = ImGui::GetColorU32(ImVec4(0x40 / 255.0f, 0x40 / 255.0f, 0x49 / 255.0f, 255 / 255.0f));

        drawList->AddRect(ImVec2(screenPosX, screenPosY), ImVec2(screenPosX + windowWidth, height), borderColor, rounding, roundingCorners, 1.0f);
    };

    inline void ShowCustomWindowDemo()
    {
        example01("example01", false);
        example01("example01 debug", true);

        static bool example02Open = false;
        example02("example02", &example02Open, false);
        static bool example02Open2 = false;
        example02("example02 debug", &example02Open2, true);

        static bool example03Open1 = false;
        static bool example03Open2 = false;
        static bool example03Open3 = false;
        example03("example03", &example03Open1, &example03Open2, &example03Open3, false);


        static bool example03Open4 = false;
        static bool example03Open5 = false;
        static bool example03Open6 = false;
        example03("example03 debug", &example03Open4, &example03Open5, &example03Open6, true);
    };

}

static void renderContent() {
    ImGui::Text("This is a Text");
    ImGui::TextWrapped("This is a WrappeddddddddddddddText ");
    ImGui::Button("ButtonInside 01", ImVec2(-1, 0));
    ImGui::Button("ButtonInside 02", ImVec2(0, 0));
}

static char* catStr(const char* one, const char* two) {
    char* three = new char[strlen(one) + strlen(two) + 1] { '\0' };
    strcat_s(three, strlen(one) + 1, one);
    strcat_s(three, strlen(one) + strlen(two) + 1, two);
    return three;
}

static void example01(const char* name, bool debug) {
    ImGui::Begin(name);

    DEBUG = debug;

    char* idChild = catStr(name, "child");

    ImGui::Button("Outside Begin", ImVec2(-1, 0));
    {
        ImGui::BeginChildEx(idChild, 0, 0, 0);
        renderContent();
        ImGui::EndChildEx();
    }
    ImGui::Button("Outside End", ImVec2(-1, 0));

    delete[] idChild;

    ImGui::End();
}

static void example02(const char* name, bool* isOpen, bool debug) {
    ImGui::Begin(name);

    DEBUG = debug;

    char* idChild = catStr(name, "child");

    ImGui::Button("Outside Begin", ImVec2(-1, 0));
    {
        if (ImGui::BeginCollapsingHeaderEx(idChild, "Title", isOpen, 0, 0, 0))
            renderContent();
        ImGui::EndCollapsingHeaderEx(*isOpen);
    }
    ImGui::Button("Outside End", ImVec2(-1, 0));

    delete[] idChild;

    ImGui::End();
}

static void example03(const char* name, bool* isOpen1, bool* isOpen2, bool* isOpen3, bool debug) {
    ImGui::Begin(name);

    DEBUG = debug;

    char* idChild = catStr(name, "child");
    char* idSubChild = catStr(name, "subchild");
    char* idthird = catStr(name, "idthird");

    ImGui::Button("Outside Begin", ImVec2(-1, 0));
    {
        if (ImGui::BeginCollapsingHeaderEx(idChild, "First", isOpen1, 0, 0, 0)) {
            renderContent();

            if (ImGui::BeginCollapsingHeaderEx(idSubChild, "Second", isOpen2, 0, 0, 0)) {
                renderContent();
            }
            ImGui::EndCollapsingHeaderEx(*isOpen2);
        }
        ImGui::EndCollapsingHeaderEx(*isOpen1);

        if (ImGui::BeginCollapsingHeaderEx(idthird, "Third", isOpen3, 0, 0, 0)) {
            renderContent();
        }
        ImGui::EndCollapsingHeaderEx(*isOpen3);
    }
    ImGui::Button("Outside End", ImVec2(-1, 0));

    delete[] idChild;
    delete[] idSubChild;
    delete[] idthird;

    ImGui::End();
}

static bool renderFrameContent(const char* title, bool* value)
{
    ImGui::BeginGroup();
    ImGui::PushID("frame");

    ImDrawList* drawList = ImGui::GetWindowDrawList();
    float getFrameHeight = ImGui::GetFrameHeight();
    float removedSize = 5.5f; // reduce few pixels
    float halfSize = (getFrameHeight) / 2.0f - removedSize;

    ImVec2 vec = ImGui::GetCursorScreenPos();

    float screenPosX = vec.x;
    float screenPosY = vec.y;
    float arrowPaddingLeft = 6;

    float x = screenPosX + halfSize + arrowPaddingLeft;
    float y = screenPosY + getFrameHeight / 2.0f;

    bool hovered = ImGui::IsMouseHoveringRect(ImVec2(x - halfSize - removedSize, y - halfSize - removedSize),
        ImVec2(x + halfSize + removedSize, y + halfSize + removedSize));

    ImU32 hoveredColor = ImGui::GetColorU32(ImVec4(255 / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f));
    ImU32 clickColor = ImGui::GetColorU32(ImVec4(0 / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f));
    ImU32 whiteColor = ImGui::GetColorU32(ImVec4(255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f));

    bool isWindowHovered = ImGui::IsWindowHovered();

    if (isWindowHovered) {
        if (hovered) {
            if (ImGui::IsMouseDown(0))
                hoveredColor = clickColor;
            if (ImGui::IsMouseReleased(0))
                *value = !*value;
        }

        if (hovered)
            drawList->AddCircleFilled(ImVec2(x, y), halfSize * 2, hoveredColor);
    }

    float triA_X = 0;
    float triA_Y = 0;
    float triB_X = 0;
    float triB_Y = 0;
    float triC_X = 0;
    float triC_Y = 0;

    if (*value) {
        // arrow down
        float offset = -0.5f;
        triA_X = x - halfSize + offset;
        triA_Y = y - halfSize;
        triB_X = x + halfSize + offset;
        triB_Y = y - halfSize;
        triC_X = x + offset;
        triC_Y = y + halfSize;
    }
    else {
        // arrow right
        triA_X = x - halfSize;
        triA_Y = y - halfSize;
        triB_X = x + halfSize;
        triB_Y = y;
        triC_X = x - halfSize;
        triC_Y = y + halfSize;
    }

    ImVec2 textSize = ImGui::CalcTextSize(title, NULL);

    float offsetY = (getFrameHeight - textSize.y) / 2.0f;
    float offsetX = 5;

    drawList->AddText(ImVec2(x + halfSize * 2 + offsetX, screenPosY + offsetY), whiteColor, title, NULL);

    drawList->AddTriangleFilled(ImVec2(triA_X, triA_Y), ImVec2(triB_X, triB_Y), ImVec2(triC_X, triC_Y), whiteColor);

    ImGui::PopID();
    ImGui::EndGroup();

    return *value;
}