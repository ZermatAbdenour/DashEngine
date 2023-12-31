#pragma once
#include "Component.h"
#include "Shader.h"
#include "texture.h"
#include "MeshData.h"
#include"ResourceManagement.h"

namespace DashEngine {

    class SpriteRenderer :public Component
    {
    public:
        Texture* texture = ResourceManagement::Textures::GetTexture("Bricks");
        Shader* shader = ResourceManagement::Shaders::GetShader("SpriteShader");
    public:
        SpriteRenderer();
        virtual void Start();
        virtual void Update();


    private:
        MeshData* meshData = ResourceManagement::Primitives::GetPrimitive("Quad");
    };
}