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
#include <day_cycle.h>
#include <engine.h>
#include <framebuffer.h>
#include <cubemap.h>
#include <transform.h>
#include <uniform_buffer.h>

#define N_DEBUG 0

typedef struct {
    // Scene materials
    Camera camera;

    UniformBuffer mvp_mat;
    Framebuffer g_buffer;
    Mesh frame;

    CubeMap sky_box;
    DayCycle day_cycle;

    Shader sky_shader;
    Shader pbr_shader;
    Shader geometry;
#if N_DEBUG
    Shader normal_shader;
#endif

    // Test materials
    Chunk chunk;

    mat4 model_matrix;

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
 * Renders the scene.
 *
 * @param world
 */
void world_scene(World* world);

/**
 *  Performs a deferred rendering geometry pass. Writes the data to three
 *  framebuffers (G-Buffer) formatted as such:
 *      location 0 - (vec4) position + metallic
 *      location 1 - (vec4) albedo + roughness
 *      location 2 - (vec4) normal + ao
 *
 *  @param world     World struct
 */
void world_geometry_pass(World* world);

/**
 * Performs a physically-based lighting pass. Uses the G-Buffer to obtain data
 * from the scene.
 *
 * @param world     World struct
 */
void world_lighting_pass(World* world);

/**
 * Draws the skybox by rendering the scene six times from the center of the
 * current chunk to six textures. These textures are used as environment
 * mapping for the PBR shading.
 *
 * @param world     World struct
 */
void world_sky_pass(World* world);

/**
 * Delete a world.
 *
 * @param world     World struct
 * @param game      Game object to allow access global game stuff
 */
void world_delete(World* world);


#endif
