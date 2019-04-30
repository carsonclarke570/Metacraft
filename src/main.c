#include <Mesh.h>
#include <Window.h>
#include <Shader.h>
#include <Texture.h>
#include <Model.h>
#include <Matrix.h>

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
    int32_t err = window_create(&window, 640, 480, "Daybreak Test", false);
    if (err) {
        return err;
    }
    glEnable(GL_DEPTH_TEST);

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

    ivec2 size;
    window_size(&window, size);
    mat4_projection(p_mat, 90.0f, 0.1f, 100.0f, (float) size[0] / (float) size[1]);
    //mat4_identity(p_mat);
    mat4_print(p_mat);

    vec3 test = {0.0f, 0.0f, -3.0f};
    mat4_translate(v_mat, test);

    shader_bind(&shader);
    register_texture(&shader, &texture, 1);
    shader_uniform_mat4(&shader, "projection", p_mat);
    shader_uniform_mat4(&shader, "view", v_mat);

    while (!window_should_close(&window)) {
        // Clear buffer
        glClearColor(GL_CLEAR_COLOR_R, GL_CLEAR_COLOR_G, GL_CLEAR_COLOR_B, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // uniforms
        float s = (float) fabs(sin(glfwGetTime()));
        vec3 scale = {s * 0.001f, s * 0.001f, 1.0f};
        vec3 translate = {-0.00015f, 0.0f, 0.0f};
        mat4_transform(m_mat, scale, translate);
        //mat4_translate(m_mat, translate);
        //mat4_scale(m_mat, scale);
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