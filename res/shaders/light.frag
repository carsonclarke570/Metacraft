#version 330 core

layout (location = 0) out vec4 out_color;

in vec2 texcoord;

uniform sampler2D buf_position;
uniform sampler2D buf_normal;
uniform sampler2D buf_albedo;

// Camera
uniform vec3 eye_pos;

// Directional Light
uniform vec3 direction;
uniform vec3 diffuse;

const vec3 MIN_DIELECTRIC = vec3(0.03);
const float PI = 3.14159265359;
const float EPSILON = 0.00001;
const vec3 AMBIENCE = vec3(0.03);

// Cook-Torrance Equations
float normal_function(vec3 h, vec3 n, float a) {
    float hn = max(dot(h, n), 0.0f);
    float aa = a * a;
    aa = aa * aa;
    float hn2 = hn * hn;

    float x = hn2 * (aa - 1.0) + 1.0;
    return aa / (PI * x * x);
}

float ggx_geometry(vec3 w, vec3 n, float a) {
    float r = (a + 1.0f);
    float k = (r * r) / 8.0f;
    float nw = max(dot(n, w), 0.0f);

    return nw / (nw * (1.0 - k) + k);
}

float geometry_function(vec3 wi, vec3 wo, vec3 n, float a) {
    return ggx_geometry(wi, n, a) * ggx_geometry(wo, n, a);
}

vec3 fresnel_function(float cos_theta, vec3 f0) {
    return f0 + (1 - f0) * pow(1.0f - cos_theta, 5);
}

void main() {
    // Geometry Buffer Data
    vec3 world_pos = texture(buf_position, texcoord).rgb;
    vec3 normal = normalize(texture(buf_normal, texcoord).rgb);
    vec3 albedo = texture(buf_albedo, texcoord).rgb;

    float metallic = texture(buf_position, texcoord).a;
    float roughness = texture(buf_normal, texcoord).a;
    float ao = 1.0f;

    // Fresnel 0
    vec3 f0 = mix(MIN_DIELECTRIC, albedo, metallic);

    // Outgoing and Incoming rays
    vec3 w_o = normalize(eye_pos - world_pos);  // point -> eye
    vec3 w_i = normalize(direction);

    // Outgoing light
    vec3 l_o = vec3(0.0f);

    // DIRECTIONAL LIGHT
    vec3 h = normalize(w_o +w_i);
    vec3 radiance = diffuse;

    // BRDF
    float D = normal_function(h, normal, roughness);
    float G = geometry_function(w_i, w_o, normal, roughness);
    vec3 F = fresnel_function(max(dot(h, w_o), 0.0f), f0);

    vec3 ks = F;
    vec3 kd = (vec3(1.0f) - ks) * (1.0f - metallic);

    vec3 specular = (D * G * F) / max(4.0f * max(dot(normal, w_o), 0.0) * max(dot(normal, w_i), 0.0), EPSILON);
    float cos_theta = max(dot(normal, w_i), 0.0f);
    l_o += (kd * albedo / PI + specular) * radiance * cos_theta;

    // OTHER LIGHTS

    // Corrections
    vec3 color = (AMBIENCE * albedo * ao) + l_o;

    // HDR Tone-mapping
    color = color / (color + vec3(1.0));
    // Gamma Correct
    color = pow(color, vec3(1.0/2.2));

    out_color = vec4(color, 1.0f);
}

