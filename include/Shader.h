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

#ifndef _SHADER_H_
#define _SHADER_H_

#include <cstdint>
#include <fstream>
#include <map>
#include <string>

#include <glad/glad.h>

#include "Common.h"

namespace daybreak {

    enum ShaderType {
        VERTEX, FRAGMENT, GEOMETRY, COMPUTE
    };

    class Shader {
        NO_COPY(Shader)
    private:
        std::map<std::string, uint32_t> _attributes;
        std::map<std::string, uint32_t> _uniforms;
        uint32_t _shader;
        uint32_t _shaders[4];
    public:
        /**
         * Constructs a new Shader object.
         */
        Shader();

        /**
         * Destroys a Shader object.
         */
        ~Shader();

        /**
         * Loads and attaches a shader from text.
         *
         * @param type  Type of shader to attach.
         * @param src   The text of the shader.
         * @return  CODE_SUCCESS if success, else a relevant error code.
         */
        int32_t load_text(ShaderType type, const std::string& src);

        /**
         * Loads and attaches a shader from a file.
         *
         * @param type  Type of shader to attach.
         * @param file  File path of the file to open and read.
         * @return  CODE_SUCCESS if success, else a relevant error code.
         */
        int32_t load_file(ShaderType type, const char* file);

        /**
         * Attempts to compiles all attached shaders. To prevent memory
         * leakages, make sure to call dispose() when you're done using the
         * shader.
         *
         * @return  CODE_SUCCESS if success, else a relevant error code.
         */
        int32_t compile();

        /**
         * Destroys the shader module. Be sure to call this on every Shader
         * object you create before exiting the program.
         */
        void dispose();

        /**
         * Registers an attribute to this Shader object.
         *
         * @param attrib    Name of the attribute to register.
         */
        void register_attrib(const char* attrib);

        /**
         * Registers a uniform by querying its location in the shader and
         * storing it in a map.
         *
         * @param uniform   Name of the uniform to register.
         */
        void register_uniform(const char* uniform);

        /**
         * Binds the shader by making it the active shader.
         */
        void bind();

        /**
         * Unbinds the shader by removing the active shader.
         */
        void unbind();

        // Getters/Setters
        inline uint32_t get_shader() { return _shader; }
    };
}

#endif
