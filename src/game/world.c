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

#include "world.h"

extern TexturePool texture_pool;

void world_init(World* world, Game* game) {
    // CAMERA
    camera_init(&world->camera);

    // CHUNK STUFF
    chunk_allocate(&world->chunk);
    uint32_t temp = (FACE_EAST | FACE_WEST | FACE_UP) << 24u;
    uint32_t faces[8] = {
            temp | (7u << 8u) | 7u,
            temp | (7u << 8u) | 8u,
            temp | (8u << 8u) | 8u,
            temp | (8u << 8u) | 7u,
            temp | (1u << 16u) | (0u << 8u) | 0u,
            temp | (1u << 16u) | (15u << 8u) | 0u,
            temp | (1u << 16u) | (0u << 8u) | 15u,
            temp | (1u << 16u) | (15u << 8u) | 15u
    };
    chunk_mesh(&world->chunk, &world->chunk_mesh, faces, 8, 24);

    // CUBE
    mesh_cube(&world->test_cube);

    // TEXTURES
    texture_pool_allocate(1);
    create_texture(&texture_pool.textures[0], "dirt.png", TEXTURE_DIFFUSE);

    // SHADERS
    shader_load_file(&world->shader, VERTEX, "main.vert");
    shader_load_file(&world->shader, FRAGMENT, "main.frag");
    shader_compile(&world->shader);

    mat4 v_mat;
    mat4 p_mat;

    // PROJECTION MATRIX
    mat4_projection(p_mat, 45.0f, 0.1f, 100.0f, (float) WIN_WIDTH / (float) WIN_HEIGHT);

    // VIEW MATRIX
    camera_view_matrix(&world->camera, v_mat);

    // SHADER BINDING
    shader_bind(&world->shader);
    register_texture(&world->shader, &texture_pool.textures[0], 1);
    shader_uniform_mat4(&world->shader, "projection", p_mat);
    shader_uniform_mat4(&world->shader, "view", v_mat);

    // TRANSFORM
    transform_default(&world->chunk_t);
    world->chunk_t.translation[0] = 5.0f;
    world->chunk_t.translation[1] = -2.5f;
    world->chunk_t.translation[2] = -10.0f;

    transform_default(&world->cube_t);
    world->cube_t.translation[0] = -5.0f;
    world->cube_t.translation[2] = -10.0f;
}

void world_update(World* world, Game* game, double delta) {

    camera_move(&world->camera, &game->window, delta);
    camera_look(&world->camera, game->input.cursor_offset);

    float s = sinf(glfwGetTime() / 2.0f);

    quat q;
    vec3 axis = {0.0f, 1.0f, 0.0f};
    quat_axis_angle(q, axis, s * 360.0f);

    // Cube
    memcpy(world->cube_t.rotation, q, sizeof(quat));

    // Chunk
    memcpy(world->chunk_t.rotation, q, sizeof(quat));
}

void world_render(World* world, Game* game, double delta) {
    bind_texture(&texture_pool.textures[0], 1);

    mat4 mat;

    // Update view
    camera_view_matrix(&world->camera, mat);
    shader_uniform_mat4(&world->shader, "view", mat);

    // Render chunk
    transform_to_matrix(&world->chunk_t, mat);
    shader_uniform_mat4(&world->shader, "model", mat);
    mesh_render(&world->chunk_mesh, &world->shader);

    // Render cube
    transform_to_matrix(&world->cube_t, mat);
    shader_uniform_mat4(&world->shader, "model", mat);
    mesh_render(&world->test_cube, &world->shader);
}

void world_delete(World* world) {
    // Clean up
    chunk_delete(&world->chunk);
    shader_destroy(&world->shader);
    mesh_destroy(&world->chunk_mesh);
    mesh_destroy(&world->test_cube);

    // Global cleanup
    texture_pool_delete();
}