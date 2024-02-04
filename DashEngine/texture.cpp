#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION    
#include <Stb/stb_image.h>
#include <iostream>

namespace DashEngine {
    Texture::Texture(const char* TexturePath, TextureTypes type)
    {
        stbi_set_flip_vertically_on_load(true);
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
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

        glBindTexture(GL_TEXTURE_2D, 0);
    }



    void Texture::Bind()
    {
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void Texture::ActivateAndBind(int texture) {
        int texturenumber = 0x84c0 + texture;
        glActiveTexture(texturenumber);
        glBindTexture(GL_TEXTURE_2D, ID);
    }
}