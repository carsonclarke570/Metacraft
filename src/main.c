#include <Mesh.h>
#include <Window.h>
#include <Shader.h>
#include <Texture.h>

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: GLFW failed to initialize!\n");
        return CODE_GLFW_INIT_ERR;
    }

    Window window;
    int32_t err = window_create(&window, 640, 480, "Daybreak Test", false);
    if (err) {
        return err;
    }

    Shader shader;
    if ((err = shader_load_file(&shader, VERTEX, "main.vert"))) {
        return err;
    }
    if ((err = shader_load_file(&shader, FRAGMENT, "main.frag"))) {
        return err;
    }
    shader_compile(&shader);

    Texture texture = 0;
    create_texture(texture);
    if ((err = load_texture(texture, "dirt.png"))) {
        return err;
    }

    Vertex vertices[4] = {
            {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
            {{0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
            {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
            {{-0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}}
            // Position             Normal              Texture
    };

    uint32_t indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    Mesh mesh;
    mesh_create(&mesh, vertices, 4, indices, 6);

    shader_bind(&shader);
    glUniform1i(glGetUniformLocation(shader.program, "tex"), 0);

    while (!window_should_close(&window)) {
        // Clear buffer
        glClearColor(GL_CLEAR_COLOR_R, GL_CLEAR_COLOR_G, GL_CLEAR_COLOR_B, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind tetures
        bind_texture(texture, 0);

        // render
        shader_bind(&shader);
        mesh_render(&mesh);

        // Swap buffers, poll IO events
        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }

    // Clean up
    destroy_texture(texture);
    shader_destroy(&shader);
    mesh_destroy(&mesh);
    window_destroy(&window);
    glfwTerminate();

    return CODE_SUCCESS;
}