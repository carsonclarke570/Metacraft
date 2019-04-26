#version 330 core

in vec2 texcoord;

out vec4 out_color;

uniform sampler2D tex;

void main() {
    out_color = texture(tex, texcoord);
}