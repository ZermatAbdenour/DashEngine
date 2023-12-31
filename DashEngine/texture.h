#pragma once

class Texture {
public:
    int ID;
    Texture(const char* TexturePath);
    void Use();
};