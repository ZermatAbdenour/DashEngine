#version 330 core
#define POINT_LIGHTS_COUNT 2
#define SPOT_LIGHTS_COUNT 1

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
out vec4 FragColor;

struct Material {
    sampler2D diffuseMap[4];
    sampler2D SpecularMap[4];

    float shininess;
};
struct DirectionalLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
struct PointLight {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};
struct SpotLight {
    vec3 position;
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float cutOff;
    float outerCutOff;
};

uniform Material u_material;
uniform vec3 u_viewPos;

//Lights
uniform DirectionalLight u_directionalLight;

uniform PointLight u_pointLights[POINT_LIGHTS_COUNT];
uniform SpotLight u_spotLights[SPOT_LIGHTS_COUNT];

//Camera
uniform float u_nearPlane;
uniform float u_farPlane;

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir, vec3 diffuseTexture, vec3 specularTexture);
vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffuseTexture, vec3 specularTexture);
vec3 CalculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffuseTexture, vec3 specularTexture);
float LinerizeDepth(float depthValue);
void main() {
    vec3 fragResult = vec3(0);

    vec3 normal = normalize(Normal);
    vec3 viewDir = normalize(u_viewPos - FragPos);
    vec3 diffuseTexture = texture(u_material.diffuseMap[0], TexCoord).rgb;
    vec3 specularTexture = texture(u_material.SpecularMap[0], TexCoord).rgb;

    //calculate directional light impact
    fragResult += CalculateDirectionalLight(u_directionalLight, normal, viewDir, diffuseTexture, specularTexture);

    for(int i = 0; i < POINT_LIGHTS_COUNT; i++) {
        fragResult += CalculatePointLight(u_pointLights[i], normal, FragPos, viewDir, diffuseTexture, specularTexture);
    }
    /*
    for(int i = 0; i < SPOT_LIGHTS_COUNT; i++) {
        fragResult += CalculateSpotLight(u_spotLights[i], normal, FragPos, viewDir, diffuseTexture, specularTexture);
    }
    */
    float depth = LinerizeDepth(gl_FragCoord.z) / u_farPlane;
    vec3 depthVec4 = vec3(pow(depth, 1.4));

    FragColor = vec4(fragResult * (1 - depthVec4) + depthVec4, 1.0);
}

vec3 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir, vec3 diffuseTexture, vec3 specularTexture) {
    vec3 lightDir = normalize(-light.direction);
    //siffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    //specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(reflectDir, viewDir), 0.0), u_material.shininess);

    //calculate result
    vec3 ambient = diffuseTexture * light.ambient;
    vec3 diffuse = diffuseTexture * diff * light.diffuse;
    vec3 specular = specularTexture * spec * light.specular;
    return vec3(ambient + diffuse + specular);
}

vec3 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffuseTexture, vec3 specularTexture) {
    vec3 lightDir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), u_material.shininess);
    // attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance +
        light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient = diffuseTexture * light.ambient;
    vec3 diffuse = diffuseTexture * light.diffuse * diff;
    vec3 specular = specularTexture * light.specular * spec;
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

vec3 CalculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffuseTexture, vec3 specularTexture) {
    vec3 fragDir = normalize(light.position - fragPos);
    float theta = dot(normalize(-light.direction), fragDir);
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    vec3 lightDir = normalize(-light.direction);
    //siffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    //specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(reflectDir, viewDir), 0.0), u_material.shininess);

    //calculate result
    vec3 ambient = diffuseTexture * light.ambient * intensity;
    vec3 diffuse = diffuseTexture * diff * light.diffuse * intensity;
    vec3 specular = specularTexture * spec * light.specular * intensity;

    return (ambient + diffuse + specular);
}

float LinerizeDepth(float depthValue) {
    float ndc = depthValue * 2.0 - 1.0;
    float linearDepth = (2.0 * u_nearPlane * u_farPlane) / (u_farPlane + u_nearPlane - ndc * (u_farPlane - u_nearPlane));
    return linearDepth;
}