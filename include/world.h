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

#ifndef _WORLD_H_
#define _WORLD_H_

#include <GLFW/glfw3.h>

#include <chunk.h>
#include <model.h>
#include <transform.h>

typedef struct {
    Chunk chunk;

    // Test materials
    mat4 model_matrix;
    Shader shader;

    // Chunk
    Mesh chunk_mesh;
    Transform chunk_t;

    // Test Cube
    Model test_cube;
    Transform cube_t;

} World;

/**
 * Initializes a world.
 *
 * @param world     World struct
 */
void world_init(World* world);

/**
 * Update a world.
 *
 * @param world     World struct
 */
void world_update(World* world);

/**
 * Render a world.
 *
 * @param world     World struct
 */
void world_render(World* world);

/**
 * Delete a world.
 *
 * @param world     World struct
 */
void world_delete(World* world);


#endif
