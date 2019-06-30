#version 330 core

in vec2 texcoord;
out vec4 out_color;

uniform sampler2D buf_position;
uniform sampler2D buf_normal;
uniform sampler2D buf_albedo;

uniform vec3 ambience;

void main() {
    out_color = texture(buf_albedo, texcoord) * vec4(ambience, 1.0f);
}