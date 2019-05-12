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

#include <camera.h>
#include <chunk.h>
#include <engine.h>
#include <cubemap.h>
#include <transform.h>
#include <uniform_buffer.h>

#define N_DEBUG 0

typedef struct {
    // Scene materials
    Camera camera;
    UniformBuffer mvp;
    CubeMap sky_box;
#if N_DEBUG
    Shader normal_shader;
#endif

    Shader sky_shader;

    // Test materials
    Chunk chunk;

    mat4 model_matrix;
    Shader shader;

    // Chunk
    Mesh chunk_mesh;
    Transform chunk_t;

    // Test Cube
    Mesh test_cube;
    Transform cube_t;

} World;

/**
 * Initializes a world.
 *
 * @param world     World struct
 * @param game      Game object to allow access global game stuff
 */
void world_init(World* world, Game* game);

/**
 * Update a world.
 *
 * @param world     World struct
 * @param game      Game object to allow access global game stuff
 * @param delta     Time since last update.
 */
void world_update(World* world, Game* game, double delta);

/**
 * Render a world.
 *
 * @param world     World struct
 * @param game      Game object to allow access global game stuff
 * @param delta     Time since last render.
 */
void world_render(World* world, Game* game, double delta);

/**
 * Delete a world.
 *
 * @param world     World struct
 * @param game      Game object to allow access global game stuff
 */
void world_delete(World* world);


#endif
