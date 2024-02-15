#pragma once
#include<glm/glm.hpp>
#include <vector>
#include "Texture.h"
#include "Shader.h"

namespace DashEngine {

    class Mesh {

    public:
        struct Vertex {
            glm::vec3 position;
            glm::vec3 normal;
            glm::vec2 texCoord;
            Vertex() {

            }
            Vertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 texCrd) {
                position = pos;
                normal = norm;
                texCoord = texCrd;
            }
        };
    public:
        unsigned int VBO, EBO, VAO;
        std::vector<Vertex> Vertices;
        std::vector<unsigned int> Indices;
        std::vector<Texture*> Textures;
    public:
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture*> textures);
        void Load();
        void Draw(Shader& shader);
    };
}