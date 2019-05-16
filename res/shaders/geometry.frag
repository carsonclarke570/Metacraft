#version 330 core
layout (location = 0) out vec3 buf_position;
layout (location = 1) out vec3 buf_normal;
layout (location = 2) out vec4 buf_albedo;

// Fragment data
in S_VAR {
    vec3 position;
    vec3 normal;
    vec2 texcoord;
} fs_in;

// Material data
uniform sampler2D texture_diffuse;

void main() {
    buf_position = fs_in.position;
    buf_normal = normalize(fs_in.normal);
    buf_albedo.rgb = texture(texture_diffuse, fs_in.texcoord).rgb;
    buf_albedo.a = 0.0f;
}

