#version 330 core

in vec2 texcoord;

out vec4 out_color;

uniform sampler2D texture_diffuse;

void main() {
    vec3 diffuse = texture(texture_diffuse, texcoord).rgb;
    out_color = vec4(diffuse, 1.0f);
}