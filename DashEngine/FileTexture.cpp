#include "FileTexture.h"
#define STB_IMAGE_IMPLEMENTATION    
#include <Stb/stb_image.h>
#include <iostream>

using namespace DashEngine;

FileTexture::FileTexture(const char* TexturePath, TextureTypes type,TextureParameters parms) {
    stbi_set_flip_vertically_on_load(true);

    Bind();

    SetTextureParms(parms);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char* data = stbi_load(TexturePath, &width, &height, &nrChannels, 0);
    if (data)
    {
        GLenum format;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    Unbind();
}