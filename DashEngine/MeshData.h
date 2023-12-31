#pragma once
#include <vector>

namespace DashEngine {
    struct MeshData
    {
    public:
        bool ThreeD = true;
        std::vector<float> Verticies;
        std::vector<unsigned int> Indicies;
        bool LoadedToGPU = false;
        unsigned int VBO, EBO, VAO;
    public:
        MeshData();
        ~MeshData();
        MeshData(std::vector<float> verticies, std::vector<unsigned int> indicies, std::vector<float> uvs,bool threeD);
        std::vector<float> interleaveData3D(const std::vector<float>& vertices, const std::vector<float>& uvs);
        std::vector<float> interleaveData2D(const std::vector<float>& vertices, const std::vector<float>& uvs);
        void LoadToGPU();
        void DrawMesh();
    };
}