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

#include <Shader.h>

namespace daybreak {

    Shader::Shader() {
        _shader = 0;
        _shaders[VERTEX] = 0;
        _shaders[FRAGMENT] = 0;
        _shaders[GEOMETRY] = 0;
        _shaders[COMPUTE] = 0;
        _attributes.clear();
        _uniforms.clear();
    }

    Shader::~Shader() {
        _attributes.clear();
        _uniforms.clear();
    }

    int32_t Shader::load_text(ShaderType type, const std::string &src) {
        // Create shader
        uint32_t gl_type;
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

        uint32_t shader = glCreateShader(gl_type);
        const char* str = src.c_str();
        glShaderSource(shader, 1, &str, nullptr);

        // Compile + error check
        int32_t status;
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if (!status) {
            // Get error and print
            int32_t log_size;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_size);
            char* log = new char[log_size];
            glGetShaderInfoLog(shader, log_size, nullptr, log);
            fprintf(stderr, "ERROR: Failed to compile shader! Message follows:\n%s", log);

            // Clean up
            delete[] log;
            glDeleteShader(shader);

            //return code
            return CODE_SHADER_COMPILE_ERROR;
        }

        _shaders[type] = shader;
        return CODE_SUCCESS;
    }

    int32_t Shader::load_file(ShaderType type, const char *file) {
        std::ifstream parser;
        parser.open(file, std::ios_base::in);
        if (parser) {
            std::string buffer(std::istreambuf_iterator<char>(parser), (std::istreambuf_iterator<char>()));
            return load_text(type, buffer);
        }
        fprintf(stderr, "ERROR: Invalid file path \"%s\"\n", file);
        return CODE_INVALID_FILENAME;
    }

    int32_t Shader::compile() {
        // Create and attach shaders
        _shader = glCreateProgram();
        for (uint32_t s: _shaders) {
            if (s) {
                glAttachShader(_shader, s);
            }
        }

        // Link
        int32_t status;
        glLinkProgram(_shader);
        glGetProgramiv(_shader, GL_LINK_STATUS, &status);
        if (!status) {
            // Get error and print
            int32_t log_size;
            glGetProgramiv(_shader, GL_INFO_LOG_LENGTH, &log_size);
            char* log = new char[log_size];
            glGetProgramInfoLog(_shader, log_size, nullptr, log);
            fprintf(stderr, "ERROR: Failed to link shader! Message follows:\n%s", log);

            // Clean up
            delete[] log;
            glDeleteProgram(_shader);

            //return code
            return CODE_SHADER_LINK_ERROR;
        }

        for (uint32_t s: _shaders) {
            if (s) {
                glDetachShader(_shader, s);
                glDeleteShader(s);
            }
        }
        return CODE_SUCCESS;
    }

    void Shader::dispose() {
        glDeleteProgram(_shader);
        _shader = -1;
    }

    void Shader::register_attrib(const char *attrib) {
        _attributes[attrib] = glGetAttribLocation(_shader, attrib);
    }

    void Shader::register_uniform(const char *uniform) {
        _uniforms[uniform] = glGetUniformLocation(_shader, uniform);
    }

    void Shader::bind() {
        glUseProgram(_shader);
    }

    void Shader::unbind() {
        glUseProgram(0);
    }
}