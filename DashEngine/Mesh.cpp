#include "Mesh.h"
#include <string>

namespace DashEngine {
    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture*> textures)
    {
        Vertices = vertices;
        Indices = indices;
        Textures = textures;
    }   

    void Mesh::Load() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(Vertex), &Vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indices.size() * sizeof(unsigned int), &Indices[0], GL_STATIC_DRAW);

        //Positions
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(0);

        //UVs
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
        glEnableVertexAttribArray(1);

        //Normals
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
        glEnableVertexAttribArray(2);
        


        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glBindVertexArray(0);

    }

    void Mesh::Draw(Shader &shader)
    {
        unsigned int diffuseNbr = 0, specularNbr = 0;

        for (int i = 0;i < Textures.size();i++) {
            std::string name;
            std::string nbr;
            Textures[i]->ActivateAndBind(i);
            if (Textures[i]->TextureType == Texture::TextureTypes::Diffuse) {
                name = "diffuseMap";
                nbr = diffuseNbr++;
            }
            else if (Textures[i]->TextureType == Texture::TextureTypes::Specular) {
                name = "SpecularMap";
                nbr = specularNbr++;
            }

            shader.setInt(("material." + name + "["+ nbr+"]").c_str(), i);
        }
        glActiveTexture(GL_TEXTURE0);

        //Bind Buffers
        glBindVertexArray(VAO);


        ///Try Comment this two lines and see if it works
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        //Draw Object
        glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);
        
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}
