#version 330 core

struct Material{
    vec3 BaseColor;
    int useTexture;
};

uniform sampler2D ourTexture;
uniform Material material;


in vec2 TexCoord;

out vec4 FragColor;

void main()
{
    vec4 result =(1-material.useTexture)* vec4(material.BaseColor,1) + material.useTexture * texture(ourTexture, TexCoord) * vec4(material.BaseColor,1);
    FragColor = result;  

}