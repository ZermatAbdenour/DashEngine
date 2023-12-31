#include "ResourceManagement.h"
using namespace DashEngine;



//Premitives

std::vector<float> cubevertices = {
    //positions           
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    0.5f, -0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    0.5f,  0.5f,  0.5f,
    0.5f, -0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,
};

std::vector<float> cubeuvs = {
    // texture coords
   0.0f, 0.0f,  // A 0
   1.0f, 0.0f,  // B 1
   1.0f, 1.0f,  // C 2
   0.0f, 1.0f,  // D 3
   0.0f, 0.0f,  // E 4
   1.0f, 0.0f,   // F 5
   1.0f, 1.0f,   // G 6
   0.0f, 1.0f,   // H 7

   0.0f, 0.0f,  // D 8
   1.0f, 0.0f,  // A 9
   1.0f, 1.0f,  // E 10
   0.0f, 1.0f,  // H 11
   0.0f, 0.0f,   // B 12
   1.0f, 0.0f,   // C 13
   1.0f, 1.0f,   // G 14
   0.0f, 1.0f,   // F 15

   0.0f, 0.0f,  // A 16
   1.0f, 0.0f,   // B 17
   1.0f, 1.0f,   // F 18
   0.0f, 1.0f,  // E 19
   0.0f, 0.0f,  // C 20
   1.0f, 0.0f,  // D 21
   1.0f, 1.0f,  // H 22
   0.0f, 1.0f,  // G 23
};

std::vector<unsigned int> cubeindices = {
    // front and back
    0, 3, 2,
    2, 1, 0,
    4, 5, 6,
    6, 7 ,4,
    // left and right
    11, 8, 9,
    9, 10, 11,
    12, 13, 14,
    14, 15, 12,
    // bottom and top
    16, 17, 18,
    18, 19, 16,
    20, 21, 22,
    22, 23, 20
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
    0.0f,0.0f,
    0.0f,1.0f,
    1.0f,1.0f,
    1.0f,0.0f
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

    ResourceManagement::Shaders::AddShader("SpriteShader", new Shader("Resources/Shaders/spritevertex.vert", "Resources/Shaders/fragment.frag"));

    //Textures
    ResourceManagement::Textures::AddTexture("Bricks", new Texture("Resources/Textures/wall.jpg"));
    //primitives

    ResourceManagement::Primitives::AddPrimitive("Cube", new MeshData(cubevertices, cubeindices, cubeuvs, true));
    ResourceManagement::Primitives::AddPrimitive("Quad", new MeshData(quadvertices, quadindices, quaduvs, false));
}