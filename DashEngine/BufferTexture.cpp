#include "BufferTexture.h"
#include <iostream>
using namespace DashEngine;

BufferTexture::BufferTexture(float width,float height,BufferTextureTypes type,TextureParameters parms)
{
    TextureType = TextureTypes::None;
    Bind();
    UpdateTextureBuffer(width,height,type);
    SetTextureParms(parms);
    Unbind();
}

void BufferTexture::UpdateTextureBuffer(float width, float height, BufferTextureTypes type)
{
    if (type == BufferTextureTypes::Color) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    }
    else if (type == BufferTextureTypes::DepthStencil) {
        glTexImage2D(
            GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, width, height, 0,
            GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL
        );
    }
    BufferTextureType = type;
}