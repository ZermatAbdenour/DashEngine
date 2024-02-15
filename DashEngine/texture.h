#pragma once
#include <glad/glad.h>

namespace DashEngine {
    class Texture {
    public:
        enum TextureTypes {
            Diffuse,
            Specular,
            Buffer
        };
    public:
        unsigned int ID;
        TextureTypes TextureType;
        Texture(const char* TexturePath, TextureTypes type = TextureTypes::Diffuse);
        Texture(float width, float height);
        void Bind();
        void ActivateAndBind(int texture);
    };
}
