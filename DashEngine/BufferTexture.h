#pragma once
#include "Texture.h"
namespace DashEngine {
    enum BufferTextureTypes
    {
        Color,Depth,Stencil,DepthStencil
    };
    class BufferTexture :public Texture{
    public:
        BufferTextureTypes BufferTextureType;
        BufferTexture(float width, float height, BufferTextureTypes type,TextureParameters parms = TextureParameters::DefaultBufferParms);
        void UpdateTextureBuffer(float width,float height, BufferTextureTypes type);
    };
}