#pragma once
#include "Shader.h"
#include "Mesh.h"
#include"Texture.h"
#include <map>
namespace DashEngine {

    struct ResourceManagement
    {
        struct Shaders
        {
            static std::map<std::string, Shader*> shaders;
            //Shaders
            static void AddShader(std::string name, Shader* shader);
            static Shader* GetShader(std::string name);
        };

        struct Textures
        {
            static std::map<std::string, Texture*> textures;
            //Textures
            static void AddTexture(std::string path, Texture* texture);
            static Texture* GetTexture(std::string name);
            static bool TextureExist(std::string name);
        };

        struct Primitives
        {
            static std::map<std::string, Mesh*> primitives;
            static void AddPrimitive(std::string name, Mesh* primitive);
            static Mesh* GetPrimitive(std::string name);
        };

        static void LoadResources();
        


        //Primitives
    };
}