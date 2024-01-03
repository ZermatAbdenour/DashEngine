#pragma once
#include <glad/glad.h>

namespace DashEngine {
    class Texture {
    public:
        struct TextureParms {
            unsigned int InternalFormat;
            unsigned int ImageFormat;
            bool GenerateMipMap;
            TextureParms() {
                InternalFormat = GL_RGB;
                ImageFormat = GL_RGB;
                GenerateMipMap = true;
            }
        };
    public:
        unsigned int ID;
        TextureParms textureparms;
        Texture(const char* TexturePath, TextureParms parms);
        void Use();


    };
}
