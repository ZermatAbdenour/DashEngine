#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION    
#include <Stb/stb_image.h>
#include <iostream>

using namespace DashEngine;
Texture::Texture(const char* TexturePath, TextureParms parms)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char* data = stbi_load(TexturePath, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, parms.InternalFormat, width, height, 0, parms.ImageFormat, GL_UNSIGNED_BYTE, data);

        if(parms.GenerateMipMap)
            glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);
}



void Texture::Use()
{
    glBindTexture(GL_TEXTURE_2D, ID);
}
