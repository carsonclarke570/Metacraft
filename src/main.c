#include <mesh.h>
#include <window.h>
#include <shader.h>
#include <texture.h>
#include <model.h>
#include <matrix.h>
#include <transform.h>
#include <engine.h>
#include <world.h>

extern TexturePool texture_pool;

World world;

void init() {
    world_init(&world);
/*
    // TEXTURES
    texture_pool_allocate(10);
    create_texture(texture_pool.textures[0], "dirt.png", TEXTURE_DIFFUSE);

    // SHADERS
    shader_load_file(&shader, VERTEX, "main.vert");
    shader_load_file(&shader, FRAGMENT, "main.frag");
    shader_compile(&shader);

    // MODELS
    model_create(&model, "cube.obj");
//    Vertex vertices[] = {
//            {{-0.5f, 0.5f, 0.0f},{0.0f, 0.0f, 0.0f},{0.0f, 1.0f}},
//            {{0.5f, 0.5f, 0.0f},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f}},
//            {{0.5f, -0.5f, 0.0f},{0.0f, 0.0f, 0.0f},{1.0f, 0.0f}},
//            {{-0.5f, -0.5f, 0.0f},{0.0f, 0.0f, 0.0f},{0.0f, 0.0f}},
//    };
//
//    unsigned int indices[] = {
//            0, 2, 1,
//            0, 3, 2
//    };
//    Mesh mesh;
//    mesh_create(&mesh, vertices, 4, indices, 6, &texture_pool.textures[0], 1);

    mat4 v_mat;
    mat4 p_mat;

    // PROJECTION MATRIX
    mat4_projection(p_mat, 90.0f, 0.1f, 100.0f, (float) WIN_WIDTH / (float) WIN_HEIGHT);
    //mat4_identity(p_mat);

    // VIEW MATRIX
    vec3 test = {0.0f, 0.0f, -10.0f};
    mat4_translate(v_mat, test);

    // SHADER BINDING
    shader_bind(&shader);
    register_texture(&shader, &texture, 1);
    shader_uniform_mat4(&shader, "projection", p_mat);
    shader_uniform_mat4(&shader, "view", v_mat);

    // TRANSFORM
    transform_default(&transform);
    transform.scale[0] = 0.001f;
    transform.scale[1] = 0.001f;
    transform.scale[2] = 1.0f; */
}

void update() {
    world_update(&world);

    /*
    // uniforms
    float s = (float) sin(glfwGetTime()) / 5.0f;
    //transform.scale[0] = s * 0.001f;
    // transform.scale[1] = s * 0.001f;
    //transform.scale[2] = 1.0f;

    //transform.translation[0] = -0.00015f;

    quat q;
    vec3 axis = {1.0f, 1.0f, 0.0f};
    quat_axis_angle(q, axis, s * 360.0f);
    memcpy(transform.rotation, q, sizeof(quat));

    transform_to_matrix(&transform, m_mat);
    shader_uniform_mat4(&shader, "model", m_mat);
    */
}

void render() {
    world_render(&world);
    // render
    //mesh_render(&mesh, &shader);
    /*bind_texture(&texture, 1);
    model_render(&model, &shader); */
}

void cleanup() {
    world_delete(&world);
}

int main() {

    // Start Up Code
    engine_init();

    Game game;
    game.init = init;
    game.render = render;
    game.cleanup = cleanup;
    game.update = update;

    engine_run(&game);

    return CODE_SUCCESS;
}