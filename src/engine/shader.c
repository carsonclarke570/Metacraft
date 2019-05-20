/*
    Copyright 2019 Carson Clarke-Magrab

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include <shader.h>


extern const char *texture_type_map[4];

void shader_create(Shader *shader) {
    shader->program = 0;
    shader->shaders[VERTEX] = 0;
    shader->shaders[FRAGMENT] = 0;
    shader->shaders[GEOMETRY] = 0;
    shader->shaders[COMPUTE] = 0;
}

void shader_delete(Shader *shader) {
    glDeleteProgram(shader->program);
    shader->program = 0;
}

int shader_load_text(Shader *shader, enum ShaderType type, const char *src) {
    // Create shader
    GLenum gl_type;
    switch(type) {
        case VERTEX:
            gl_type = GL_VERTEX_SHADER;
            break;
        case GEOMETRY:
            gl_type = GL_GEOMETRY_SHADER;
            break;
        case FRAGMENT:
            gl_type = GL_FRAGMENT_SHADER;
            break;
        case COMPUTE:
            gl_type = GL_COMPUTE_SHADER;
            break;
        default:
            fprintf(stderr, "ERROR: Invalid ShaderType!\n");
            return CODE_INVALID_SHADER_TYPE;
    }

    GLuint gl_shader = glCreateShader(gl_type);
    glShaderSource(gl_shader, 1, &src, NULL);

    // Compile + error check
    int status;
    glCompileShader(gl_shader);
    glGetShaderiv(gl_shader, GL_COMPILE_STATUS, &status);
    if (!status) {
        // Get error and print
        int32_t log_size;
        glGetShaderiv(gl_shader, GL_INFO_LOG_LENGTH, &log_size);
        char* log = malloc(log_size * sizeof(char));
        glGetShaderInfoLog(gl_shader, log_size, NULL, log);
        fprintf(stderr, "ERROR: Failed to compile shader! Message follows:\n%s", log);

        // Clean up
        free(log);
        glDeleteShader(gl_shader);

        //return code
        return CODE_SHADER_COMPILE_ERROR;
    }

    shader->shaders[type] = gl_shader;
    return CODE_SUCCESS;
}

int shader_load_file(Shader* shader, enum ShaderType type, const char* file) {
    FILE* fp = fopen(file, "rb");
    if (!fp) {
        fprintf(stderr, "ERROR: Failed to open file %s\n", file);
        return CODE_INVALID_FILENAME;
    }
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    char* data = malloc((size + 1) * sizeof(char));
    fread(data, sizeof(char), size, fp);
    data[size] = 0;
    fclose(fp);

    int error_code = shader_load_text(shader, type, data);
    free(data);
    return error_code;
}

int shader_compile(Shader* shader) {
    // Create and attach shaders
    shader->program = glCreateProgram();
    for (int i = 0; i < 4; i ++) {
        if (shader->shaders[i]) {
            glAttachShader(shader->program, shader->shaders[i]);
        }
    }

    // Link
    int32_t status;
    glLinkProgram(shader->program);
    glGetProgramiv(shader->program, GL_LINK_STATUS, &status);
    if (!status) {
        // Get error and print
        int32_t log_size;
        glGetProgramiv(shader->program, GL_INFO_LOG_LENGTH, &log_size);
        char* log = malloc(log_size * sizeof(char));
        glGetProgramInfoLog(shader->program, log_size, NULL, log);
        fprintf(stderr, "ERROR: Failed to link shader! Message follows:\n%s", log);

        // Clean up
        free(log);
        glDeleteProgram(shader->program);

        //return code
        return CODE_SHADER_LINK_ERROR;
    }

    for (int i = 0; i < 4; i ++) {
        if (shader->shaders[i]) {
            glDetachShader(shader->program, shader->shaders[i]);
            glDeleteShader(shader->shaders[i]);
        }
    }
    return CODE_SUCCESS;
}

void shader_uniform_mat4(Shader* shader, const char* name, const mat4 data) {
    GLuint loc = glGetUniformLocation(shader->program, name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, data);
}

void shader_uniform_vec3(Shader* shader, const char* name, const vec3 data) {
    GLuint loc = glGetUniformLocation(shader->program, name);
    glUniform3fv(loc, 1, data);
}

void shader_uniform_float(Shader* shader, const char* name, float data) {
    GLuint loc = glGetUniformLocation(shader->program, name);
    glUniform1f(loc, data);
}

void shader_uniform_int(Shader* shader, const char* name, int data) {
    GLuint loc = glGetUniformLocation(shader->program, name);
    glUniform1i(loc, data);
}

void shader_bind_ubo(Shader* shader, const char* name, uint32_t slot) {
    GLuint loc = glGetUniformBlockIndex(shader->program, name);
    glUniformBlockBinding(shader->program, loc, slot);
}

void register_texture(Shader *shader, Texture *texture, unsigned int slot) {
    glActiveTexture(GL_TEXTURE0 + slot);
    glUniform1i(glGetUniformLocation(shader->program, texture_type_map[texture->type]), slot);
}

void shader_bind(Shader *shader) {
    glUseProgram(shader->program);
}

void shader_unbind() {
    glUseProgram(0);
}