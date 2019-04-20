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

#include <Window.h>

namespace daybreak {

    void resize_callback(GLFWwindow* window, int width, int height);

    void Window::create(uint16_t width, uint16_t height, const std::string& title, bool full_screen) {
        // Create window and context
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VER_MAJ);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VER_MIN);
        _window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!_window) {
            fprintf(stderr, "ERROR: Failed to create window!\n");
            exit(CODE_WINDOW_CREATE_ERR);
        }
        glfwMakeContextCurrent(_window);

        // Set callback functions
        glfwSetFramebufferSizeCallback(_window, resize_callback);

        // Load glad to access OpenGL
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            fprintf(stderr, "ERROR: Failed to initialize GLAD!\n");
            exit(CODE_GLAD_INIT_ERR);
        }
    }

    void Window::destroy() {
        glfwDestroyWindow(_window);
    }

    void resize_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
}
