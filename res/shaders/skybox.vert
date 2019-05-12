#version 330 core
layout (location = 0) in vec3 in_position;

layout (std140) uniform mvp_mat {
    mat4 model;
    mat4 view;
    mat4 projection;
};

out DATA {
    vec4 position;
    float time;
} vs_out;

uniform float time;

void main() {
    mat4 alt_view = view;
    alt_view[3][0] = 0.0f;
    alt_view[3][1] = 0.0f;
    alt_view[3][2] = 0.0f;

    vs_out.position = vec4(in_position, 1.0);
    vs_out.time = time;

    gl_Position = (projection * alt_view * vec4(in_position, 1.0)).xyww;
}