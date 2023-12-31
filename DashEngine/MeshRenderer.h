#pragma once
#include "Component.h"
#include "Shader.h"
#include "texture.h"
#include "MeshData.h"
#include "ResourceManagement.h"
namespace DashEngine {
    class MeshRenderer :public Component
    {
    public:
        MeshRenderer();
        virtual void Start();
        virtual void Update();

    public:
        Texture* texture = ResourceManagement::Textures::GetTexture("Bricks");
        Shader* shader = ResourceManagement::Shaders::GetShader("DefaultShader");
        MeshData* meshData = ResourceManagement::Primitives::GetPrimitive("Cube");
    };

}