#include <mesh.h>
#include <window.h>
#include <shader.h>
#include <texture.h>
#include <model.h>
#include <matrix.h>
#include <transform.h>

extern TexturePool texture_pool;

int main() {

    // Start Up Code
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: GLFW failed to initialize!\n");
        return CODE_GLFW_INIT_ERR;
    }

    // Code
    texture_pool_allocate(10);

    Window window;
    int32_t err = window_create(&window, 1200, 800, "Definitely Not Minecraft", false);
    if (err) {
        return err;
    }
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    Shader shader;
    if ((err = shader_load_file(&shader, VERTEX, "main.vert"))) {
        return err;
    }
    if ((err = shader_load_file(&shader, FRAGMENT, "main.frag"))) {
        return err;
    }
    shader_compile(&shader);

    Texture texture;
    if ((err = create_texture(&texture, "dirt.png", TEXTURE_DIFFUSE))) {
        return err;
    }
    texture_pool.textures[0] = &texture;

    Model model;
    model_create(&model, "cube.obj");
    Vertex vertices[] = {
            {{-0.5f, 0.5f, 0.0f},{0.0f, 0.0f, 0.0f},{0.0f, 1.0f}},
            {{0.5f, 0.5f, 0.0f},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f}},
            {{0.5f, -0.5f, 0.0f},{0.0f, 0.0f, 0.0f},{1.0f, 0.0f}},
            {{-0.5f, -0.5f, 0.0f},{0.0f, 0.0f, 0.0f},{0.0f, 0.0f}},
    };

    unsigned int indices[] = {
            0, 2, 1,
            0, 3, 2
    };
    Mesh mesh;
    mesh_create(&mesh, vertices, 4, indices, 6, &texture_pool.textures[0], 1);

    mat4 m_mat;
    mat4 v_mat;
    mat4 p_mat;

    // PROJECTION MATRIX
    ivec2 size;
    window_size(&window, size);
    mat4_projection(p_mat, 90.0f, 0.1f, 100.0f, (float) size[0] / (float) size[1]);
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
    Transform transform;
    transform_default(&transform);

    transform.scale[0] = 0.001f;
    transform.scale[1] = 0.001f;
    transform.scale[2] = 1.0f;


    while (!window_should_close(&window)) {
        // Clear buffer
        glClearColor(GL_CLEAR_COLOR_R, GL_CLEAR_COLOR_G, GL_CLEAR_COLOR_B, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

        // render
        //mesh_render(&mesh, &shader);
        bind_texture(&texture, 1);
        model_render(&model, &shader);

        // Swap buffers, poll IO events
        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }

    // Clean up
    destroy_texture(&texture);
    shader_destroy(&shader);
    mesh_destroy(&mesh);
    window_destroy(&window);

    // Global cleanup
    texture_pool_delete();
    glfwTerminate();

    return CODE_SUCCESS;
}