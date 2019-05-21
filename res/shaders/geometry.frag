#version 330 core
layout (location = 0) out vec4 buf_position; //m
layout (location = 1) out vec4 buf_normal;  //r
layout (location = 2) out vec3 buf_albedo;

// Fragment data
in S_VAR {
    vec3 position;
    vec3 normal;
    vec2 texcoord;
} fs_in;

// Material data
uniform sampler2D texture_diffuse;
uniform sampler2D texture_normal;
uniform sampler2D texture_specular;

vec3 get_normal() {
    vec3 tangentNormal = texture(texture_normal, fs_in.texcoord).xyz * 2.0 - 1.0;

    vec3 Q1  = dFdx(fs_in.position);
    vec3 Q2  = dFdy(fs_in.position);
    vec2 st1 = dFdx(fs_in.texcoord);
    vec2 st2 = dFdy(fs_in.texcoord);

    vec3 N   = normalize(fs_in.normal);
    vec3 T  = normalize(Q1*st2.t - Q2*st1.t);
    vec3 B  = -normalize(cross(N, T));
    mat3 TBN = mat3(T, B, N);

    return normalize(TBN * tangentNormal);
}

void main() {
    buf_position.rgb = fs_in.position;
    buf_position.a = texture(texture_specular, fs_in.texcoord).g;
    buf_normal.rgb = get_normal().xyz;
    buf_normal.a = texture(texture_specular, fs_in.texcoord).r;
    buf_albedo.rgb = texture(texture_diffuse, fs_in.texcoord).rgb;
}

