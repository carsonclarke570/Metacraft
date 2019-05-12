#version 330 core

in S_VAR {
    vec3 normal;
    vec2 texcoord;
} fs_in;

out vec4 out_color;

uniform sampler2D texture_diffuse;

void main() {
    out_color = texture(texture_diffuse, fs_in.texcoord);
}