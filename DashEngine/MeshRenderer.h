#pragma once
#include "Component.h"
#include "Shader.h"
#include "texture.h"
#include "Mesh.h"
#include "ResourceManagement.h"
namespace DashEngine {
    class MeshRenderer :public Component
    {
    public:
        MeshRenderer();
        virtual void Start();
        virtual void Update();

    public:
        Shader* shader = ResourceManagement::Shaders::GetShader("DefaultShader");
        Mesh* mesh = ResourceManagement::Primitives::GetPrimitive("Cube");
    };

}