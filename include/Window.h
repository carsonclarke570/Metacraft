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

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <cstdint>
#include <string>

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Common.h"

namespace daybreak {

    class Window {
        NO_COPY(Window)
    private:
        GLFWwindow* _window;
    public:

        /**
         * Constructs a new Window object.
         */
        Window();

        /**
         * Creates a new, empty window.
         *
         * @param width         Initial width of the window
         * @param height        Initial height of the window
         * @param title         Title to display on the window
         * @param full_screen   Initialize to full screen mode if true, else windowed mode
         * @return  CODE_SUCCESS if success, else returns a relevant error code.
         */
        int32_t create(uint16_t width, uint16_t height, const std::string& title, bool full_screen);

        /**
         * Destroys the Window object.
         */
        void destroy();

        /**
         * Checks if the window should close.
         *
         * @return True if the window should close, else false.
         */
        inline bool should_close() { return glfwWindowShouldClose(_window); }

        /**
         * Swaps the back screen buffer with the front buffer.
         */
        inline void swap_buffers() { glfwSwapBuffers(_window); }

        /**
         * Polls events.
         */
        inline void poll_events() { glfwPollEvents(); }

        // Getters / Setter
        inline const GLFWwindow* get_window() { return _window; };
        inline glm::ivec2 get_size() {
            int32_t width, height;
            glfwGetFramebufferSize(_window, &width, &height);
            return glm::ivec2(width, height);
        }
    };
}


#endif
