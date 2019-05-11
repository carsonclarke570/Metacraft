#version 330 core

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;
layout (location = 2) in vec2 in_texture;

out vec2 texcoord;

layout (std140) uniform mvp_mat {
    mat4 model;
    mat4 view;
    mat4 projection;
};

void main() {
    gl_Position = projection * view * model * vec4(in_position, 1.0);
    texcoord = in_texture;
}