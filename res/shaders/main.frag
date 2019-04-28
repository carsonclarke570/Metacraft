#version 330 core

in vec2 texcoord;

out vec4 out_color;

uniform sampler2D texture_diffuse;

void main() {
    out_color = texture(texture_diffuse, texcoord);
}