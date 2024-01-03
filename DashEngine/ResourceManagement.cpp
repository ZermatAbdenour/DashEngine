#include "ResourceManagement.h"
using namespace DashEngine;



//Premitives

std::vector<float> cubevertices = {
    // Front
     -0.5, -0.5, -0.5,
      0.5, -0.5, -0.5,
      0.5,  0.5, -0.5,
     -0.5,  0.5, -0.5,
     // Back
     -0.5, -0.5,  0.5,
      0.5, -0.5,  0.5,
      0.5,  0.5,  0.5,
     -0.5,  0.5,  0.5,
     // Left
     -0.5, -0.5, -0.5,
     -0.5,  0.5, -0.5,
     -0.5,  0.5,  0.5,
     -0.5, -0.5,  0.5,
     // Right
      0.5, -0.5, -0.5,
      0.5,  0.5, -0.5,
      0.5,  0.5,  0.5,
      0.5, -0.5,  0.5,
      // Bottom
      -0.5, -0.5, -0.5,
       0.5, -0.5, -0.5,
       0.5, -0.5,  0.5,
      -0.5, -0.5,  0.5,
      // Top
      -0.5,  0.5, -0.5,
       0.5,  0.5, -0.5,
       0.5,  0.5,  0.5,
      -0.5,  0.5,  0.5
};

std::vector<float> cubeuvs = {
     // Front
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        // Back
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        // Left
        1, 1,
        0, 1,
        0, 0,
        1, 0,
        // Right
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        // Bottom
        0, 1,
        1, 1,
        1, 0,
        0, 0,
        // Top
        0, 1,
        1, 1,
        1, 0,
        0, 0
};

std::vector<unsigned int> cubeindices = {
        0, 1, 2,  0, 2, 3,  // Front
        4, 5, 6,  4, 6, 7,  // Back
        8, 9, 10, 8, 10, 11,  // Left
        12, 13, 14, 12, 14, 15,  // Right
        16, 17, 18, 16, 18, 19,  // Bottom
        20, 21, 22, 20, 22, 23   // Top
};

std::vector<float> cubenormals = {
    // Front
    0, 0, -1,
    0, 0, -1,
    0, 0, -1,
    0, 0, -1,
    // Back
    0, 0, 1,
    0, 0, 1,
    0, 0, 1,
    0, 0, 1,
    // Left
    -1, 0, 0,
    -1, 0, 0,
    -1, 0, 0,
    -1, 0, 0,
    // Right
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    // Bottom
    0, -1, 0,
    0, -1, 0,
    0, -1, 0,
    0, -1, 0,
    // Top
    0, 1, 0,
    0, 1, 0,
    0, 1, 0,
    0, 1, 0
};




std::vector<float> quadvertices = {
    //positions           
    -0.5f,-0.5f,
    -0.5f,0.5f,
    0.5f,0.5f,
    0.5f,-0.5f
};

std::vector<float> quaduvs = {
    // texture coords
    1.0f,1.0f,
    1.0f,0.0f,
    0.0f,0.0f,
    0.0f,1.0f
};

std::vector<unsigned int> quadindices = {
    0,1,2,
    0,3,2
};

std::map<std::string, Shader*> ResourceManagement::Shaders::shaders = {};

void ResourceManagement::Shaders::AddShader(std::string name, Shader* shader)
{
    ResourceManagement::Shaders::shaders[name] = shader;
}

Shader* ResourceManagement::Shaders::GetShader(std::string name)
{
    return  ResourceManagement::Shaders::shaders[name];
}

std::map<std::string, Texture*> ResourceManagement::Textures::textures = {};
void ResourceManagement::Textures::AddTexture(std::string name, Texture* texture)
{
    ResourceManagement::Textures::textures[name] = texture;
}

Texture* ResourceManagement::Textures::GetTexture(std::string name)
{
    return ResourceManagement::Textures::textures[name];
}

std::map<std::string, MeshData*> ResourceManagement::Primitives::primitives = {};
void DashEngine::ResourceManagement::Primitives::AddPrimitive(std::string name, MeshData* primitive)
{
    ResourceManagement::Primitives::primitives[name] = primitive;
}

MeshData* DashEngine::ResourceManagement::Primitives::GetPrimitive(std::string name)
{
    return ResourceManagement::Primitives::primitives[name];
}

void ResourceManagement::LoadResources()
{
    //shaders
    ResourceManagement::Shaders::AddShader("DefaultShader", new Shader("Resources/Shaders/vertex.vert", "Resources/Shaders/fragment.frag"));

    ResourceManagement::Shaders::AddShader("SpriteShader", new Shader("Resources/Shaders/spritevertex.vert", "Resources/Shaders/spritefragment.frag"));

    //Textures
    Texture::TextureParms ThreeDTextureParms = Texture::TextureParms();
    ResourceManagement::Textures::AddTexture("Bricks", new Texture("Resources/Textures/wall.jpg", ThreeDTextureParms));
    
    Texture::TextureParms TwoDTextureParms = Texture::TextureParms();
    TwoDTextureParms.ImageFormat = GL_RGBA;
    TwoDTextureParms.InternalFormat = GL_RGBA;

    ResourceManagement::Textures::AddTexture("Circle", new Texture("Resources/Sprites/PingPong/awesomeface.png", TwoDTextureParms));
    //primitives

    ResourceManagement::Primitives::AddPrimitive("Cube", new MeshData(cubevertices, cubeindices, cubeuvs, cubenormals));
    ResourceManagement::Primitives::AddPrimitive("Quad", new MeshData(quadvertices, quadindices, quaduvs));
}