#pragma once
#include "glad/glad.h"
#include <iostream>
namespace DashEngine {
    class FrameBuffer {
    public:
        FrameBuffer();
        ~FrameBuffer();
        void Bind();
        void Unbind();
        void SetColorAttachment(unsigned int texutreid);
        void SetDepthStencilAttachment(unsigned int textureid);

    private:
        unsigned int FBO;
    };
}