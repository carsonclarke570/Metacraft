#include "include/Window.h"
#include <Shader.h>
#include <Mesh.h>

using namespace daybreak;

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: GLFW failed to initialize!\n");
        return CODE_GLFW_INIT_ERR;
    }

    Window window;
    int32_t err = window.create(640, 480, "Daybreak Test", false);
    if (err) {
        return err;
    }

    Shader shader;
    if ((err = shader.load_file(VERTEX, "main.vert"))) {
        return err;
    }
    if ((err = shader.load_file(FRAGMENT, "main.frag"))) {
        return err;
    }
    shader.compile();

    Vertex vertices[4];
    vertices[0].position = glm::vec3(0.5f, 0.5f, 0.0f);
    vertices[1].position = glm::vec3(0.5f, -0.5f, 0.0f);
    vertices[2].position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vertices[3].position = glm::vec3(-0.5f, 0.5f, 0.0f);

    uint32_t indices[] = {
            0, 1, 3,
            1, 2, 3
    };

    Mesh mesh(vertices, 4, indices, 6);

    while (!window.should_close()) {
        // Clear buffer
        glClearColor(GL_CLEAR_COLOR_R, GL_CLEAR_COLOR_G, GL_CLEAR_COLOR_B, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render
        shader.bind();
        mesh.render();

        // Swap buffers, poll IO events
        window.swap_buffers();
        window.poll_events();
    }

    // Clean up
    shader.dispose();
    window.destroy();
    glfwTerminate();

    return CODE_SUCCESS;
}