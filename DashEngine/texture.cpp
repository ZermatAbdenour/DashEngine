#include "Texture.h"
#include <iostream>

namespace DashEngine {

    TextureParameters TextureParameters::DefaultFileParms = { GL_REPEAT,GL_REPEAT,GL_LINEAR_MIPMAP_LINEAR,GL_LINEAR };
    TextureParameters TextureParameters::DefaultBufferParms = { GL_REPEAT,GL_REPEAT,GL_LINEAR,GL_LINEAR };

    Texture::Texture()
    {
        glGenTextures(1, &ID);
    }

    //Texture::Texture(float width,float height)
    //{
    //    glGenTextures(1, &ID);
    //    glBindTexture(GL_TEXTURE_2D, ID);
    //    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    //    
    //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //    glBindTexture(GL_TEXTURE_2D, 0);
    //}

    void Texture::Bind()
    {
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void Texture::Unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void Texture::ActivateAndBind(int texture) {
        int texturenumber = 0x84c0 + texture;
        glActiveTexture(texturenumber);
        glBindTexture(GL_TEXTURE_2D, ID);
    }


    void Texture::SetTextureParms(TextureParameters parms) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, parms.WrapS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, parms.WrapT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, parms.MinFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, parms.MagFilter);
        TextureParms = parms;
    }
}