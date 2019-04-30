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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>

#include <Common.h>
#include <Matrix.h>
#include <Texture.h>

enum ShaderType {
    VERTEX, FRAGMENT, GEOMETRY, COMPUTE
};

typedef struct {
    GLuint program;
    GLuint shaders[4];
} Shader;

/**
 * Constructs a new Shader object.
 *
 * @param shader    Pointer to Shader struct
 */
void shader_create(Shader* shader);

/**
 * Destroys a Shader object
 *
 * @param shader    Pointer to Shader struct
 */
void shader_destroy(Shader* shader);

/**
 * Loads and attaches a shader from text.
 *
 * @param shader    Pointer to Shader struct
 * @param type      Type of shader to attach.
 * @param src       The text of the shader.
 * @return  CODE_SUCCESS if success, else a relevant error code.
 */
int shader_load_text(Shader* shader, enum ShaderType type, const char* src);

/**
 * Loads and attaches a shader from a file.
 *
 * @param shader    Pointer to Shader struct
 * @param type      Type of shader to attach.
 * @param file      File path of the file to open and read.
 * @return  CODE_SUCCESS if success, else a relevant error code.
 */
int shader_load_file(Shader* shader, enum ShaderType type, const char* file);

/**
 * Attempts to compiles all attached shaders. To prevent memory
 * leakages, make sure to call dispose() when you're done using the
 * shader.
 *
 * @param shader    Pointer to Shader struct
 * @return  CODE_SUCCESS if success, else a relevant error code.
 */
int shader_compile(Shader* shader);

/**
 * Registers an attribute to a Shader object.
 *
 * @param shader    Pointer to Shader struct
 * @param attrib    Name of the attribute to register.
 */
void shader_register_attrib(Shader* shader, const char* attrib);

/**
 * Registers a uniform by querying its location in the shader and
 * storing it in a map.
 *
 * @param shader    Pointer to Shader struct
 * @param uniform   Name of the uniform to register.
 */
void shader_register_uniform(Shader* shader, const char* uniform);

/**
 * Updates a shader's mat4 uniform.
 *
 * @param shader    Pointer to Shader struct.
 * @param name      Name of uniform to update.
 * @param data      mat4 data to update with.
 */
void shader_uniform_mat4(Shader* shader, const char* name, mat4 data);

/**
 * Registers a texture to the shader
 *
 * @param shader    Pointer to Shader struct
 * @param texture   The texture to register
 * @param slot      The slot number to register it to
 */
void register_texture(Shader* shader, Texture* texture, unsigned int slot);

/**
 * Binds the shader by making it the active shader.
 *
 * @param shader    Pointer to Shader struct
 */
void shader_bind(Shader* shader);


/**
 * Unbinds shaders.
 */
void shader_unbind();

#endif
