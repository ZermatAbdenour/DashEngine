#version 330 core

struct Material{
    vec3 BaseColor;
    int useTexture;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform sampler2D ourTexture;
uniform Material material;


uniform vec3 LightDirection;
uniform vec3 LightColor;
uniform vec3 ViewPos;
  
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;


out vec4 FragColor;

void main()
{
    vec3 Ambient = LightColor * material.ambient;

    vec3 NormalLightDir = normalize(LightDirection);
    float diff = max(dot(Normal,NormalLightDir),0.0); 
    vec3 diffuse =LightColor * (diff * material.diffuse) ;
    
    vec3 viewDir = normalize(ViewPos - FragPos);
    vec3 reflectDir = reflect(-LightDirection, Normal); 
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = LightColor * (material.specular * spec);  

    //vec3 result = (Ambient + diffuse + specular) * vec3(texture(ourTexture, TexCoord));
    vec3 result =(1-material.useTexture)* (Ambient + diffuse + specular) * material.BaseColor + material.useTexture * (Ambient + diffuse + specular) * vec3(texture(ourTexture, TexCoord)) * material.BaseColor;
    FragColor = vec4(result,1);  

}