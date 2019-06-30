#version 330 core
layout (triangles) in;
layout (line_strip, max_vertices = 6) out;

in S_VAR {
    vec3 normal;
} gs_in[];

const float MAG = 0.2;

layout (std140) uniform mvp_mat {
    mat4 model;
    mat4 view;
    mat4 projection;
};

void main() {
    int i;
    for (i = 0; i< gl_in.length(); i++) {
        vec3 p = gl_in[i].gl_Position.xyz;
        vec3 n = gs_in[i].normal;

        gl_Position = projection * view * model * vec4(p, 1.0);
        EmitVertex();

        gl_Position = projection * view * model * vec4(p + n * MAG, 1.0);
        EmitVertex();

        EndPrimitive();
    }
}