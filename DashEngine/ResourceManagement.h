#pragma once
#include "Shader.h"
#include "Mesh.h"
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
            static std::string UniqueName();
            //Textures
            static void AddTexture(std::string name, Texture* texture);
            static Texture* GetTexture(std::string name);
        private:
            static int LoadedTextures;
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