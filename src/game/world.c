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
    uint32_t temp = (FACE_EAST | FACE_WEST | FACE_UP | FACE_DOWN | FACE_SOUTH | FACE_NORTH) << 24u;
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
    chunk_mesh(&world->chunk, &world->chunk_mesh, faces, 8, 48);

    // SKYBOX
    cubemap_create(&world->sky_box);

    // CUBE
    mesh_cube(&world->test_cube);

    // TEXTURES
    texture_pool_allocate(1);
    create_texture(&texture_pool.textures[0], "dirt.png", TEXTURE_DIFFUSE);

    // LIGHT
    world->sunlight.light.ambient[0] = 0.05f;
    world->sunlight.light.ambient[1] = 0.05f;
    world->sunlight.light.ambient[2] = 0.05f;
    world->sunlight.light.diffuse[0] = 0.4f;
    world->sunlight.light.diffuse[1] = 0.4f;
    world->sunlight.light.diffuse[2] = 0.4f;
    world->sunlight.light.specular[0] = 0.5f;
    world->sunlight.light.specular[1] = 0.5f;
    world->sunlight.light.specular[2] = 0.5f;

    // SHADERS
    shader_load_file(&world->ambient_light, VERTEX, "light.vert");
    shader_load_file(&world->ambient_light, FRAGMENT, "ambient-light.frag");
    shader_compile(&world->ambient_light);

    vec3 ambience = {0.1f, 0.1f, 0.1f};
    shader_bind(&world->ambient_light);
    shader_uniform_vec3(&world->ambient_light, "ambience", ambience);
    shader_uniform_int(&world->ambient_light, "buf_position", 0);
    shader_uniform_int(&world->ambient_light, "buf_normal", 1);
    shader_uniform_int(&world->ambient_light, "buf_albedo", 2);
    shader_unbind();

    /* Geometry Pass Shader */
    shader_load_file(&world->geometry, VERTEX, "geometry.vert");
    shader_load_file(&world->geometry, FRAGMENT, "geometry.frag");
    shader_compile(&world->geometry);

    /* Geometry Pass Configuration */
    shader_bind(&world->geometry);
    shader_bind_ubo(&world->geometry, "mvp_mat", 0);
    shader_unbind();

    /* Normal Debug Shader + Configuration */
#if N_DEBUG
    shader_load_file(&world->normal_shader, VERTEX, "debug.vert");
    shader_load_file(&world->normal_shader, GEOMETRY, "debug.geom");
    shader_load_file(&world->normal_shader, FRAGMENT, "debug.frag");
    shader_compile(&world->normal_shader);
    shader_bind_ubo(&world->normal_shader, "mvp_mat", 0);
#endif

    /* Skybox Shader + Configuration */
    shader_load_file(&world->sky_shader, VERTEX, "skybox.vert");
    shader_load_file(&world->sky_shader, FRAGMENT, "skybox.frag");
    shader_compile(&world->sky_shader);

    shader_bind(&world->sky_shader);
    shader_bind_ubo(&world->sky_shader, "mvp_mat", 0);
    shader_unbind();

    /* Framebuffer Creation */
    Attachment attachments[] = {
            {GL_RGB16F, GL_RGB, GL_FLOAT},          // Position
            {GL_RGB16F, GL_RGB, GL_FLOAT},          // Normal
            {GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE}    // Color + specular
    };
    ivec2 size = {WIN_WIDTH, WIN_HEIGHT};
    framebuffer_create(&world->g_buffer, attachments, 3, size, true);

    /* Screen Quad Creation */
    mesh_quad(&world->frame);

    /* Model View Projection Uniform buffer */
    uniform_buffer_create(&world->mvp_mat, 3 * sizeof(mat4), 0);

    // MODEL - VIEW - PROJECTION
    mat4 v_mat;
    mat4 p_mat;

    // PROJECTION MATRIX
    mat4_projection(p_mat, 45.0f, 0.1f, 100.0f, (float) WIN_WIDTH / (float) WIN_HEIGHT);
    uniform_buffer_store(&world->mvp_mat, 2 * sizeof(mat4), sizeof(mat4), p_mat);

    // VIEW MATRIX
    camera_view_matrix(&world->camera, v_mat);
    uniform_buffer_store(&world->mvp_mat, sizeof(mat4), sizeof(mat4), v_mat);

    // SHADER BINDING
    shader_bind(&world->geometry);
    register_texture(&world->geometry, &texture_pool.textures[0], 5);

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


    // Light
    float inclination = 5.0f;
    float azimuth = glfwGetTime() / 5.0f;

    world->sunlight.direction[0] = sinf(inclination) * cosf(azimuth);
    world->sunlight.direction[0] = sinf(inclination) * sinf(azimuth);
    world->sunlight.direction[0] = cosf(inclination);

    // Cube
    memcpy(world->cube_t.rotation, q, sizeof(quat));

    // Chunk
    memcpy(world->chunk_t.rotation, q, sizeof(quat));
}

void world_render(World* world, Game* game, double delta) {

    /* Begin GEOMETRY Pass */
    framebuffer_bind(&world->g_buffer);

    mat4 mat;

    // Uniform Buffer update
    camera_view_matrix(&world->camera, mat);
    uniform_buffer_store(&world->mvp_mat, sizeof(mat4), sizeof(mat4), mat);

    // Geometry rendering
    shader_bind(&world->geometry);

    bind_texture(&texture_pool.textures[0], 5);
    transform_to_matrix(&world->chunk_t, mat);
    uniform_buffer_store(&world->mvp_mat, 0, sizeof(mat4), mat);

    shader_bind(&world->geometry);
    mesh_render(&world->chunk_mesh);
#if N_DEBUG
    shader_bind(&world->normal_shader);
    mesh_render(&world->chunk_mesh);
#endif

    transform_to_matrix(&world->cube_t, mat);
    uniform_buffer_store(&world->mvp_mat, 0, sizeof(mat4), mat);

    shader_bind(&world->geometry);
    mesh_render(&world->test_cube);
#if N_DEBUG
    shader_bind(&world->normal_shader);
    mesh_render(&world->test_cube);
#endif

    shader_unbind();
    framebuffer_unbind();
    /* End GEOMETRY Pass */

    /* Begin LIGHT Pass*/
    // Ambient light
    framebuffer_bind_textures(&world->g_buffer, &world->ambient_light);
    mesh_render(&world->frame);
    framebuffer_blit_depth(&world->g_buffer);
    /* End LIGHT Pass */

    // Sky rendering
    shader_bind(&world->sky_shader);
    shader_uniform_float(&world->sky_shader, "time", glfwGetTime());
    cubemap_render(&world->sky_box, &world->sky_shader);
}

void world_delete(World* world) {
    // Clean up
    chunk_delete(&world->chunk);
    cubemap_delete(&world->sky_box);

    //Shaders
    shader_destroy(&world->sky_shader);
    shader_destroy(&world->ambient_light);
    shader_destroy((&world->geometry));

    // Meshes
    mesh_delete(&world->chunk_mesh);
    mesh_delete(&world->test_cube);
    mesh_delete(&world->frame);

    // Framebuffers
    framebuffer_delete(&world->g_buffer);

    // Global cleanup
    texture_pool_delete();
}