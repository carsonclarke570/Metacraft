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

    // CUBE
    mesh_cube(&world->test_cube);

    // TEXTURES
    texture_pool_allocate(3);
    create_texture(&texture_pool.textures[0], TEXTURE_DIFFUSE);
    create_texture(&texture_pool.textures[1], TEXTURE_NORMAL);
    create_texture(&texture_pool.textures[2], TEXTURE_SPECULAR);
    texture_sampling(&texture_pool.textures[0], GL_CLAMP_TO_EDGE, GL_LINEAR);
    texture_sampling(&texture_pool.textures[1], GL_CLAMP_TO_EDGE, GL_LINEAR);
    texture_sampling(&texture_pool.textures[2], GL_CLAMP_TO_EDGE, GL_LINEAR);
    texture_load(&texture_pool.textures[0], "gold_ore.png");
    texture_load(&texture_pool.textures[1], "gold_ore_n.png");
    texture_load(&texture_pool.textures[2], "gold_ore_s.png");

    /* PBR Lighting Shader */
    shader_load_file(&world->pbr_shader, VERTEX, "light.vert");
    shader_load_file(&world->pbr_shader, FRAGMENT, "light.frag");
    shader_compile(&world->pbr_shader);

    shader_bind(&world->pbr_shader);
    shader_uniform_int(&world->pbr_shader, "buf_position", 0);
    shader_uniform_int(&world->pbr_shader, "buf_normal", 1);
    shader_uniform_int(&world->pbr_shader, "buf_albedo", 2);
    shader_unbind();

    /* Geometry Pass Shader */
    shader_load_file(&world->geometry, VERTEX, "geometry.vert");
    shader_load_file(&world->geometry, FRAGMENT, "geometry.frag");
    shader_compile(&world->geometry);

    /* Geometry Pass Configuration */
    shader_bind(&world->geometry);
    shader_bind_ubo(&world->geometry, "mvp_mat", 0);
    register_texture(&world->geometry, &texture_pool.textures[0], 5);
    register_texture(&world->geometry, &texture_pool.textures[1], 6);
    register_texture(&world->geometry, &texture_pool.textures[2], 7);
    shader_unbind();


    /* Day/Night Cycle */
    const vec3 day_sky = {0.0, 0.0, 1.0};
    const vec3 day_hor = {0.32, 0.92, 1.0};
    const vec3 night_sky = {0.1, 0.1, 0.1};
    const vec3 night_hor = {0.1, 0.1, 0.1};
    world->day_cycle.time = 0.0f;
    world->day_cycle.lerp = 0.0f;

    /* Skybox Shader + Configuration */
    shader_load_file(&world->sky_shader, VERTEX, "skybox.vert");
    shader_load_file(&world->sky_shader, FRAGMENT, "skybox.frag");
    shader_compile(&world->sky_shader);

    shader_bind(&world->sky_shader);
    shader_uniform_vec3(&world->sky_shader, "day_sky", day_sky);
    shader_uniform_vec3(&world->sky_shader, "day_hor", day_hor);
    shader_uniform_vec3(&world->sky_shader, "night_sky", night_sky);
    shader_uniform_vec3(&world->sky_shader, "night_hor", night_hor);
    shader_bind_ubo(&world->sky_shader, "mvp_mat", 0);
    shader_unbind();

    cubemap_create(&world->sky_box);

    /* PBR Framebuffer Creation */
    Attachment attachments[] = {
            {GL_RGBA16F, GL_RGBA, GL_FLOAT, GL_TEXTURE_2D, GL_NEAREST},      // Position + metallic
            {GL_RGBA16F, GL_RGBA, GL_FLOAT, GL_TEXTURE_2D, GL_NEAREST},      // Normal + roughness
            {GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, GL_TEXTURE_2D, GL_NEAREST}    // Color
    };
    ivec2  size;
    size[0] = WIN_WIDTH;
    size[1] = WIN_HEIGHT;
    framebuffer_create(&world->g_buffer, attachments, 3, size, true);

    /* Screen Quad Creation */
    mesh_quad(&world->frame);

    /* Model View Projection Uniform buffer */
    uniform_buffer_create(&world->mvp_mat, 3 * sizeof(mat4), 0);
    mat4 v_mat;
    mat4 p_mat;

    // PROJECTION MATRIX
    mat4_projection(p_mat, 45.0f, 0.1f, 100.0f, (float) WIN_WIDTH / (float) WIN_HEIGHT);
    uniform_buffer_store(&world->mvp_mat, 2 * sizeof(mat4), sizeof(mat4), p_mat);

    // VIEW MATRIX
    camera_view_matrix(&world->camera, v_mat);
    uniform_buffer_store(&world->mvp_mat, sizeof(mat4), sizeof(mat4), v_mat);

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

    // Update camera
    camera_move(&world->camera, &game->window, delta);
    camera_look(&world->camera, game->input.cursor_offset);

    /* DAY NIGHT CYCLE */
    day_update(&world->day_cycle, delta);

    /* OTHER UPDATES */
    float s = sinf(glfwGetTime() / 2.0f);

    quat q;
    vec3 axis = {0.0f, 1.0f, 0.0f};
    quat_axis_angle(q, axis, s * 360.0f);

    // Cube
    //memcpy(world->cube_t.rotation, q, sizeof(quat));

    // Chunk
    //memcpy(world->chunk_t.rotation, q, sizeof(quat));
}

void scene_render(World* world) {
    mat4 mat;

    transform_to_matrix(&world->chunk_t, mat);
    uniform_buffer_store(&world->mvp_mat, 0, sizeof(mat4), mat);
    mesh_render(&world->chunk_mesh);

    transform_to_matrix(&world->cube_t, mat);
    uniform_buffer_store(&world->mvp_mat, 0, sizeof(mat4), mat);
    mesh_render(&world->test_cube);
}

void world_render(World* world, Game* game, double delta) {
    mat4 view;

    /* Begin GEOMETRY Pass */
    glViewport(0, 0, world->g_buffer.size[0], world->g_buffer.size[1]);
    framebuffer_bind(&world->g_buffer);

    camera_view_matrix(&world->camera, view);
    uniform_buffer_store(&world->mvp_mat, sizeof(mat4), sizeof(mat4), view);

    bind_texture(&texture_pool.textures[0], 5);
    bind_texture(&texture_pool.textures[1], 6);
    bind_texture(&texture_pool.textures[2], 7);

    shader_bind(&world->geometry);
    scene_render(world);
    shader_unbind();

    framebuffer_unbind();
    /* End GEOMETRY Pass */

    /* Begin LIGHT Pass */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Ambient light
    shader_bind(&world->pbr_shader);
    framebuffer_bind_textures(&world->g_buffer, &world->pbr_shader);
    shader_uniform_vec3(&world->pbr_shader, "eye_pos", world->camera.position);
    day_shader_update(&world->day_cycle, &world->pbr_shader);
    shader_bind(&world->pbr_shader);
    mesh_render(&world->frame);

    framebuffer_blit_depth(&world->g_buffer);
    /* End LIGHT Pass */

    shader_bind(&world->sky_shader);
    shader_uniform_float(&world->sky_shader, "percent", world->day_cycle.lerp);
    cubemap_render(&world->sky_box, &world->sky_shader);
    shader_unbind();
}

void world_delete(World* world) {
    // Clean up
    chunk_delete(&world->chunk);
    cubemap_delete(&world->sky_box);

    //Shaders
    shader_destroy(&world->sky_shader);
    shader_destroy(&world->pbr_shader);
    shader_destroy((&world->geometry));

    // Meshes
    mesh_delete(&world->chunk_mesh);
    mesh_delete(&world->test_cube);
    mesh_delete(&world->frame);

    // Framebuffers
    framebuffer_delete(&world->g_buffer);

    // Textures
    texture_delete(&texture_pool.textures[0]);
    texture_delete(&texture_pool.textures[1]);
    texture_delete(&texture_pool.textures[2]);

    // Global cleanup
    texture_pool_delete();
}