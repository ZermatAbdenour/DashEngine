#pragma once
#include "Texture.h"
namespace DashEngine {
    class FileTexture : public Texture
    {
    public:
        FileTexture(const char* TexturePath, TextureTypes type = TextureTypes::Diffuse,TextureParameters parms = TextureParameters::DefaultFileParms);
    };
}
