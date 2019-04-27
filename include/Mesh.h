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

#ifndef _MESH_H_
#define _MESH_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <glad/glad.h>

#include <Shader.h>
#include <Texture.h>
#include <Vector.h>

typedef struct {
    vec3 position;
    vec3 normal;
    vec2 texture;
} Vertex;

typedef struct {
    Texture **textures;
    GLuint vbo;
    GLuint vao;
    GLuint ibo;
    unsigned int num_elements;
    unsigned int num_textures;
    bool indexed;
} Mesh;

/**
 * Constructs a new Mesh object. The indices is set to NULL, the mesh
 * will draw it's vertices sequentially and ignore num_i. Assigns the Textures
 * to slots sequentially.
 *
 * @param mesh          Pointer to Mesh struct
 * @param vertices      Vertices to add into the Mesh's buffer.
 * @param num_v         Number of vertices to add.
 * @param indices       Indices to add inti the Mesh's buffer.
 * @param num_i         Number of indices to add.
 * @param textures      Array of pointers to the textures the mesh uses.
 */
void mesh_create(Mesh* mesh, Vertex* vertices, unsigned int num_v, unsigned int* indices, unsigned int num_i, Texture **textures, unsigned int num_t);

/**
 * Destroys a Mesh struct
 *
 * @param mesh  Pointer to Mesh struct
 */
void mesh_destroy(Mesh* mesh);

/**
 * Renders the Mesh to the screen. Shader is not bound in this function, user
 * must ensure that they have bound the shader.
 *
 * @param mesh      Pointer to Mesh struct
 * @param shader    Shader to update texture data to
 */
void mesh_render(Mesh* mesh, Shader* shader);


#endif
