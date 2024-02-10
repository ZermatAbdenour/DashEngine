#include "move.h"
#include <iostream>
#include <DashEngine/Entity.h>
#include<DashEngine/TimeUtils.h>
#include<DashEngine/Inputs.h>
#include<DashEngine/Camera.h>

bool m_disabled;
void move::Start()
{
    m_disabled = false;


}

void move::Update()
{


    glm::vec3 movedir = glm::vec3(0);
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
    entity->EulerAngles.x += Inputs::Mouse::delta.y*0.1;

    if (Inputs::GetKeyDown(KeyCode::Escape))
    {
        if (m_disabled) {
            Inputs::Mouse::SetCursorMode(CursorMode::Normal);
            m_disabled = false;
        }
        else
        {
            Inputs::Mouse::SetCursorMode(CursorMode::Disabled);
            m_disabled = true;
        }
    }
}


