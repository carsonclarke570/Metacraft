#include "include/Window.h"

using namespace daybreak;

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: GLFW failed to initialize!\n");
        return CODE_GLFW_INIT_ERR;
    }

    Window window(640, 480, "Daybreak Test");
    window.create(false);

    while (!window.should_close()) {
        // Clear buffer
        glClearColor(GL_CLEAR_COLOR_R, GL_CLEAR_COLOR_G, GL_CLEAR_COLOR_B, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers, poll IO events
        window.swap_buffers();
        window.poll_events();
    }

    // Clean up
    window.destroy();
    glfwTerminate();

    return CODE_SUCCESS;
}