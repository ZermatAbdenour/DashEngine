#pragma once
namespace DashEngine {
    enum BufferTextureType
    {
        Color,Depth,Stencil,DepthStencil
    };
    class BufferTexture {
    public:

        BufferTexture();
        void SetColorType();
        void Bind();
        void Unbind();
    };
}