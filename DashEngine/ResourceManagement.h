#pragma once
#include "Shader.h"
#include "MeshData.h"
#include"texture.h"
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
            static void AddTexture(std::string name, Texture* texture);
            static Texture* GetTexture(std::string name);
        };

        struct Primitives
        {
            static std::map<std::string, MeshData*> primitives;
            static void AddPrimitive(std::string name, MeshData* primitive);
            static MeshData* GetPrimitive(std::string name);
        };

        static void LoadResources();
        


        //Primitives
    };
}