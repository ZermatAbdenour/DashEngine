#include "ModelLoader.h"
#include <iostream>
#include "MeshRenderer.h"
#include "Engine.h"
#include "FileTexture.h"

namespace DashEngine {
    ModelLoader::Model* ModelLoader::LoadModel(std::string path,bool cleanLoading)
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
            return new Model();
        }

        std::string directory = path.substr(0, path.find_last_of('/'));
        
        Model* model = new Model();
        model->directory = directory;
        model->scene = scene;
        model->CleanLoaded = cleanLoading;


        ProcessNode(scene->mRootNode, nullptr, model);
        return model;
    }
    void ModelLoader::ProcessNode(aiNode* node, Entity* parent, Model* model) {
        //Create the root entity
        Entity* newEntity = new Entity(node->mName.C_Str());
        for (int i = 0;i < node->mNumMeshes;i++) {
            MeshRenderer* renderer = newEntity->addComponent<MeshRenderer>();
            aiMesh* mesh = model->scene->mMeshes[node->mMeshes[i]];
            renderer->mesh = ProcessMesh(mesh, model);
        }
        if (parent == nullptr) {
            //Remove the file extension from the name 
            size_t dotPosition = newEntity->Name.find_last_of('.');
            if (dotPosition != std::string::npos && dotPosition > 0) {
                newEntity->Name = newEntity->Name.substr(0, dotPosition);
            }
            model->rootEntity = newEntity;
        }
        else
            parent->addChild(newEntity);
        
        //process Child 
        for (unsigned int i = 0; i < node->mNumChildren; i++)
        {
            if (model->CleanLoaded && node->mChildren[i]->mNumChildren == 0 && node->mChildren[i]->mNumMeshes == 0)
                continue;
            ProcessNode(node->mChildren[i],newEntity,model);
        }
    }

    Mesh* ModelLoader::ProcessMesh(aiMesh* mesh,Model* model)
    {
        std::vector<Mesh::Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture*> textures;

        for (unsigned int i = 0; i < mesh->mNumVertices; i++)
        {
            Mesh::Vertex vertex;
            // process vertex positions, normals and texture coordinates
            glm::vec3 position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
            vertex.position = position;

            glm::vec3 normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
            vertex.normal = normal;

            if (mesh->mTextureCoords[0]) 
            {
                glm::vec2 textCoord;
                textCoord.x = mesh->mTextureCoords[0][i].x;
                textCoord.y = mesh->mTextureCoords[0][i].y;
                vertex.texCoord = textCoord;
            }
            else
                vertex.texCoord = glm::vec2(0.0f, 0.0f);

            vertices.push_back(vertex);
        }
        // process indices

        for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }

        //process Textures
        if (mesh->mMaterialIndex >= 0)
        {
            aiMaterial* material = model->scene->mMaterials[mesh->mMaterialIndex];
            std::vector<Texture*> diffuseMaps = loadMaterialTextures(material,
                aiTextureType_DIFFUSE, TextureTypes::Diffuse, model);
            //std::cout << diffuseMaps.size()<<std::endl;
            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
            std::vector<Texture*> specularMaps = loadMaterialTextures(material,
                aiTextureType_SPECULAR, TextureTypes::Specular,model);
            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
        }

        return new Mesh(vertices, indices, textures);
    }
    std::vector<Texture*> ModelLoader::loadMaterialTextures(aiMaterial* mat, aiTextureType type, TextureTypes textureType,Model* model)
    {
        std::vector<Texture*> textures;
        for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
        {
            aiString str;
            mat->GetTexture(type, i, &str);

            std::string fullPath = model->directory + "/" + str.C_Str();
            if (!ResourceManagement::Textures::TextureExist(fullPath)) {
                std::cout << fullPath << std::endl;
                FileTexture* texture = new FileTexture(fullPath.c_str(), textureType);
                ResourceManagement::Textures::AddTexture(fullPath,texture);
                textures.push_back(texture);
            }
            else {
                Texture* texture = ResourceManagement::Textures::GetTexture(fullPath);
                textures.push_back(texture);
            }
        }
        return textures;
    }
}
