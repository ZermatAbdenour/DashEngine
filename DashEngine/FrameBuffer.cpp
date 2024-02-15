#include "FrameBuffer.h"

using namespace DashEngine;
FrameBuffer::FrameBuffer()
{
    glGenFramebuffers(1, &FBO);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)
        std::cout << "Framebuffer created successfuly"<<std::endl;
    else
        std::cout << "FrameBuffer failed to create";
}

FrameBuffer::~FrameBuffer()
{
    glDeleteFramebuffers(1, &FBO);
}

void FrameBuffer::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
}

void FrameBuffer::Unbind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::SetColorAttachment(unsigned int texutreid)
{
    Bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texutreid, 0);
    Unbind();
}

void FrameBuffer::SetDepthStencilAttachment(unsigned int textureid) {
    Bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, textureid, 0);
    Unbind();
}