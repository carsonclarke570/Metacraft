#version 330 core

in vec3 texcoord;
out vec4 out_color;

uniform float percent;
uniform vec3 day_sky;
uniform vec3 day_hor;
uniform vec3 night_sky;
uniform vec3 night_hor;

void main() {
    float a = normalize(texcoord).y;

    vec3 day = mix(day_hor, day_sky, a);
    vec3 night = mix(night_hor, night_sky, a);
    out_color = vec4(mix(day, night, percent), 1.0f);
}
