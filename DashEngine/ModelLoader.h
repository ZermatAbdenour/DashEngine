#pragma once
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include "texture.h"
#include "Entity.h"
#include "Mesh.h"

namespace DashEngine {
    static class ModelLoader
    {
    public:
        struct Model {
            const aiScene* scene;
            std::string directory;
            std::vector<std::string> loadedTextures;
        };
        static void LoadModel(std::string path,Entity* root);
    private:
        static void ProcessNode(aiNode* node,Entity* parent, Model* model);
        static Mesh* ProcessMesh(aiMesh* mesh, Model* model);
        static std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,Texture::TextureTypes textureType,Model* model);
    };
}