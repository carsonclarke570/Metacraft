#version 330 core
layout (location = 0) out vec4 out_color;

in vec2 texcoord;

uniform sampler2D buf_position;
uniform sampler2D buf_normal;
uniform sampler2D buf_albedo;

// Light
uniform vec3 eye_pos;
uniform vec3 direction;
uniform vec3 diffuse;

const vec3 MIN_DIELECTRIC = vec3(0.03);
const float PI = 3.14159265359;
const float EPSILON = 0.00001;
const vec3 AMBIENCE = vec3(0.03);


vec3 fresnel_schlick(float cos_theta, vec3 f0) {
    return f0 + (vec3(1.0) - f0) * pow(1.0 - cos_theta, 5.0);
}

float distribution(float NH, float r) {
    float a = r * r;
    a = a * a;

    float denom = (NH * NH) * (a - 1.0) + 1.0;
    denom = PI * denom * denom;

    return a / denom;
}

float geometryGGX(float cosTheta, float k) {
    return cosTheta / (cosTheta * (1.0 - k) + k);
}

float geometry(float NV, float NL, float rough) {
    float r = rough + 1.0;
    float k = (r * r) / 8.0;
    return geometryGGX(NV, k) * geometryGGX(NL, k);
}

void main() {
    vec3 world_pos = texture(buf_position, texcoord).rgb;
    vec3 albedo = texture(buf_albedo, texcoord).rgb;
    float metallic = texture(buf_position, texcoord).a;
    float roughness = texture(buf_normal, texcoord).a;
    float ao = 1.0f;

    vec3 N = normalize(texture(buf_normal, texcoord).rgb);  // Normal
    vec3 V = normalize(eye_pos - world_pos);

    vec3 F0 = mix(MIN_DIELECTRIC, albedo, metallic);

    // Directional Light
    vec3 L = normalize(direction);
    vec3 H = normalize(V + L);

    float NV = max(dot(N, V), 0.0);
    float NL = max(dot(N, L), 0.0);
    float NH = max(dot(N, H), 0.0);
    float HV = max(dot(H, V), 0.0);

    float D = distribution(NH, roughness);
    float G = geometry(NV, NL, roughness);
    vec3 F = fresnel_schlick(HV, F0);

    vec3 specular = (D * G * F) / (4 * NV * NL + EPSILON);

    vec3 ks = F;
    vec3 kd = (vec3(1.0f) - ks) * (1.0f - metallic);

    vec3 LIGHT = (kd * albedo / PI + specular) * diffuse * NL;

    // Point Lights

    // TO-DO

    vec3 AMBIENT = AMBIENCE * albedo * ao;
    vec3 color = AMBIENT + LIGHT;

    // HDR Tone-mapping
    color = color / (color + vec3(1.0));
    // Gamma Correct
    color = pow(color, vec3(1.0/2.2));

    out_color = vec4(color, 1.0f);
}