#version 330 core
layout (location = 0) out vec3 buf_position;
layout (location = 1) out vec3 buf_normal;
layout (location = 2) out vec4 buf_albedo;

void main() {
    buf_albedo = vec4(1.0, 1.0, 0.0, 1.0);
}