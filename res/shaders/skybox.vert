#version 330 core
layout (location = 0) in vec3 in_position;

layout (std140) uniform mvp_mat {
    mat4 model;
    mat4 view;
    mat4 projection;
};

out vec3 texcoord;

void main() {
    texcoord = in_position;

    gl_Position = (projection * mat4(mat3(view)) * vec4(in_position, 1.0)).xyww;
}
