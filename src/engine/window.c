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

#include <window.h>

// Callback definitions
void resize_callback(GLFWwindow* window, int width, int height);
void error_callback(int id, const char *msg);

int32_t window_create(Window* window, uint16_t width, uint16_t height, const char* title, bool full_screen) {
    // Initialize structure members
    window->window = NULL;
    glfwSetErrorCallback(error_callback);

    // Create window and context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VER_MAJ);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VER_MIN);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (full_screen) {
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        window->window = glfwCreateWindow(mode->width, mode->height, title, monitor, NULL);
    } else {
        window->window = glfwCreateWindow(width, height, title, NULL, NULL);
    }

    if (!window->window) {
        fprintf(stderr, "ERROR: Failed to create window!\n");
        return CODE_WINDOW_CREATE_ERR;
    }
    glfwMakeContextCurrent(window->window);

    // Set callback functions
    glfwSetFramebufferSizeCallback(window->window, resize_callback);

    // Load glad to access OpenGL
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwDestroyWindow(window->window);
        fprintf(stderr, "ERROR: Failed to initialize GLAD!\n");
        return CODE_GLAD_INIT_ERR;
    }

    return CODE_SUCCESS;
}

void window_destroy(Window* window) {
    glfwDestroyWindow(window->window);
}

bool window_should_close(Window* window) {
    return glfwWindowShouldClose(window->window);
}
void window_size(Window* window, ivec2 size) {
    int32_t width, height;
    glfwGetFramebufferSize(window->window, &width, &height);
    size[0] = width;
    size[1] = height;
}

// Callbacks
void resize_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void error_callback(int id, const char *msg) {
    fprintf(stderr, "ERROR: ID: %d, MSG: %s\n", id, msg);
}



