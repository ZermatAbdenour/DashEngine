#pragma once
#include <glad/glad.h>

namespace DashEngine {
    enum TextureTypes {
        None,
        Diffuse,
        Specular
    };
    struct TextureParameters {
        unsigned int WrapS;
        unsigned int WrapT;
        unsigned int MinFilter;
        unsigned int MagFilter;
        static TextureParameters DefaultFileParms;
        static TextureParameters DefaultBufferParms;
    };
    class Texture {
    public:
        unsigned int ID;
        TextureTypes TextureType;
        TextureParameters TextureParms;
        Texture();
        //Texture(const char* TexturePath, TextureTypes type = TextureTypes::Diffuse);
        //Texture(float width, float height);
        void Bind();
        void Unbind();
        void ActivateAndBind(int texture);

        /// <summary>
        /// Set the Texture Parmeters Make sure that the Texture is bound and dont forget to unbind the texture
        /// </summary>
        /// <param name="parms"></param>
        void SetTextureParms(TextureParameters parms);
    };
}
