#include "SceneViewCamera.h"
#include "Inputs.h"
#include "TimeUtils.h"
#include <glm/fwd.hpp>

using namespace DashEngine;

void SceneViewCamera::Start()
{
    m_disablCursor = false;
}

void SceneViewCamera::Update() {
    if (!Inputs::GetMouseButton(0)) {
        Inputs::Mouse::SetCursorMode(CursorMode::Normal);
        return;
    }
    Inputs::Mouse::SetCursorMode(CursorMode::Disabled);

    float speed = 2;
    if (Inputs::GetKey(KeyCode::W))
        entity->LocalPosition += entity->forward * speed * TimeUtils::deltaTime;
    if (Inputs::GetKey(KeyCode::S))
        entity->LocalPosition -= entity->forward * speed * TimeUtils::deltaTime;
    if (Inputs::GetKey(KeyCode::D))
        entity->LocalPosition += entity->right * speed * TimeUtils::deltaTime;
    if (Inputs::GetKey(KeyCode::A))
        entity->LocalPosition -= entity->right * speed * TimeUtils::deltaTime;

    //Camera movements

    entity->EulerAngles.y += Inputs::Mouse::delta.x * 0.1;
    entity->EulerAngles.x += Inputs::Mouse::delta.y * 0.1;

}
