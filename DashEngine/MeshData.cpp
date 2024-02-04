#include "MeshData.h"
#include <glad/glad.h>
#include <iostream>

using namespace DashEngine;



DashEngine::MeshData::MeshData()
{
}

MeshData::~MeshData()
{
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO);
}

MeshData::MeshData(std::vector<float> verticies, std::vector<unsigned int> indicies, std::vector<float> uvs)
{
    ThreeD = false;
    Verticies = interleaveData2D(verticies, uvs);
    Indicies = indicies;
}

MeshData::MeshData(std::vector<float> verticies, std::vector<unsigned int> indicies, std::vector<float> uvs, std::vector<float> normals)
{
    ThreeD = true;
    Verticies = interleaveData3D(verticies, uvs,normals);
    Indicies = indicies;
}


std::vector<float> MeshData::interleaveData3D(const std::vector<float>& vertices, const std::vector<float>& uvs, const std::vector<float>& normals)
{
    // Assuming vertices and uvs have the same size and are properly formatted

    size_t numVertices = vertices.size() / 3; // Assuming each vertex has 3 components (x, y, z)

    std::vector<float> interleavedData;
    interleavedData.reserve(numVertices * 5); // 3 for position + 2 for texture coordinates
    
    for (size_t i = 0; i < numVertices; ++i) {
        // Copy position data
        interleavedData.push_back(vertices[i * 3]);
        interleavedData.push_back(vertices[i * 3 + 1]);
        interleavedData.push_back(vertices[i * 3 + 2]);

        // Copy texture coordinate data
        interleavedData.push_back(uvs[i * 2]);
        interleavedData.push_back(uvs[i * 2 + 1]);

        //Copy Normals
        interleavedData.push_back(normals[i * 3]);
        interleavedData.push_back(normals[i * 3 + 1]);
        interleavedData.push_back(normals[i * 3 + 2]);

    }

    return interleavedData;
}

std::vector<float> MeshData::interleaveData2D(const std::vector<float>& vertices, const std::vector<float>& uvs)
{
    // Assuming vertices and uvs have the same size and are properly formatted

    size_t numVertices = vertices.size() / 3; // Assuming each vertex has 3 components (x, y,z)

    std::vector<float> interleavedData;

    interleavedData.reserve(numVertices * 5); // 3 for position + 2 for texture coordinates

    for (size_t i = 0; i < numVertices; ++i) {
        // Copy position data
        interleavedData.push_back(vertices[i * 3]);
        interleavedData.push_back(vertices[i * 3 + 1]);
        interleavedData.push_back(vertices[i * 3 + 2]);

        // Copy texture coordinate data
        interleavedData.push_back(uvs[i * 2]);
        interleavedData.push_back(uvs[i * 2 + 1]);
    }

    return interleavedData;
}

void MeshData::LoadToGPU()
{
    if (LoadedToGPU) {
        return;
    }
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, Verticies.size() * sizeof(float), Verticies.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, Indicies.size() * sizeof(unsigned int), Indicies.data(), GL_STATIC_DRAW);

    if (ThreeD) {
        //Positions
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        //UVs
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        //Normals
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }
    else {
        //2d Mesh

        //Positions
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        //UVs
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
  
    }


    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
    
    LoadedToGPU = true;

   
}

void MeshData::DrawMesh()
{

    //Bind Buffers
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    //Draw Object
    glDrawElements(GL_TRIANGLES, Indicies.size(), GL_UNSIGNED_INT, 0);

    //std::cout << Indicies.size() << std::endl;
}

