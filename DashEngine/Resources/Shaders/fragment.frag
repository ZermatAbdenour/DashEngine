#version 330 core
out vec4 FragColor;
  
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D ourTexture;
uniform vec3 LightDirection;
uniform vec3 LightColor;
uniform vec3 ViewPos;

void main()
{
    float AmbientStrength = 0.1f;
    vec3 Ambient = LightColor * AmbientStrength;

    vec3 NormalLightDir = normalize(LightDirection);
    float diff = max(dot(Normal,NormalLightDir),0.0); 
    vec3 diffuse = diff * LightColor;
    
    float specularStrength = 0.3;
    vec3 viewDir = normalize(ViewPos - FragPos);
    vec3 reflectDir = reflect(-LightDirection, Normal); 
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 35);
    vec3 specular = specularStrength * spec * LightColor;  

    vec3 result =  (Ambient + diffuse + specular) * vec3(texture(ourTexture, TexCoord));
    FragColor = vec4(result,1);  
}