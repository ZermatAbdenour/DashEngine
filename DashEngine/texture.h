#pragma once
#include <glad/glad.h>

namespace DashEngine {
    class Texture {
    public:
        enum TextureTypes {
            Diffuse,
            Specular,
        };
    public:
        unsigned int ID;
        TextureTypes TextureType;
        Texture(const char* TexturePath, TextureTypes type = TextureTypes::Diffuse);
        void Bind();
        void ActivateAndBind(int texture);
    };
}
