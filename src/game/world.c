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

void world_init(World* world) {
    chunk_allocate(&world->chunk);

    // CHUNK STUFF
    /*uint32_t temp = FACE_EAST << 24;
    uint32_t faces[4] = {
            temp & (0 << 8) & 0,
            temp & (16 << 8) & 0,
            temp & (16 << 8) & 16,
            temp & (0 << 8) & 16,
    };

    chunk_mesh(&world->chunk, &world->chunk_mesh, faces, 4, 4); */
    model_create(&world->chunk_mesh, "cube.obj");

    // TEXTURES
    texture_pool_allocate(10);
    create_texture(&texture_pool.textures[0], "dirt.png", TEXTURE_DIFFUSE);

    // SHADERS
    shader_load_file(&world->shader, VERTEX, "main.vert");
    shader_load_file(&world->shader, FRAGMENT, "main.frag");
    shader_compile(&world->shader);

    mat4 v_mat;
    mat4 p_mat;

    // PROJECTION MATRIX
    mat4_projection(p_mat, 90.0f, 0.1f, 100.0f, (float) WIN_WIDTH / (float) WIN_HEIGHT);

    // VIEW MATRIX
    vec3 test = {0.0f, 0.0f, -10.0f};
    mat4_translate(v_mat, test);

    // SHADER BINDING
    shader_bind(&world->shader);
    register_texture(&world->shader, &texture_pool.textures[0], 1);
    shader_uniform_mat4(&world->shader, "projection", p_mat);
    shader_uniform_mat4(&world->shader, "view", v_mat);

    // TRANSFORM for chunk
    transform_default(&world->transform);
    world->transform.scale[0] = 0.001f;
    world->transform.scale[1] = 0.001f;
    world->transform.scale[2] = 1.0f;
}

void world_update(World* world) {

    // uniforms
    float s = (float) sin(glfwGetTime()) / 5.0f;
    //transform.scale[0] = s * 0.001f;
    // transform.scale[1] = s * 0.001f;
    //transform.scale[2] = 1.0f;

    //transform.translation[0] = -0.00015f;

    quat q;
    mat4 mat;
    vec3 axis = {0.0f, 1.0f, 0.0f};
    quat_axis_angle(q, axis, s * 360.0f);
    memcpy(world->transform.rotation, q, sizeof(quat));

    transform_to_matrix(&world->transform, mat);
    shader_uniform_mat4(&world->shader, "model", mat);
}

void world_render(World* world) {
    bind_texture(&texture_pool.textures[0], 1);
    //mesh_render(&world->chunk_mesh, &world->shader);
    model_render(&world->chunk_mesh, &world->shader);
}

void world_delete(World* world) {
    // Clean up
    chunk_delete(&world->chunk);
    shader_destroy(&world->shader);
    //mesh_destroy(&world->chunk_mesh);
    model_delete(&world->chunk_mesh);

    // Global cleanup
    texture_pool_delete();
}