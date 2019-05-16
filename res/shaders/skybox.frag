#version 330 core

in DATA {
    vec4 position;
    float time;
} fs_in;

out vec4 out_color;

const vec4 DAY_TOP = vec4(0.0, 0.0, 1.0, 1.0);
const vec4 DAY_HOR = vec4(0.32, 0.92, 1.0, 1.0);

const vec4 NIGHT = vec4(0.1, 0.1, 0.1, 1.0);

const float DAY_LEN = 10.0f; // In seconds

void main() {
    vec3 point = normalize(fs_in.position.xyz);
    float a = point.y;
    float b = sin(fs_in.time / DAY_LEN);
    out_color = mix(mix(DAY_HOR, DAY_TOP, a), NIGHT, b);
}