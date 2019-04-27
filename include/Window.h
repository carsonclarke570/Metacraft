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

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Common.h>
#include <Vector.h>

typedef struct {
    GLFWwindow* window;
} Window;

/**
 * Creates a new, empty window and initializes the Window struct.
 *
 * @param window        Pointer to window struct
 * @param width         Initial width of the window
 * @param height        Initial height of the window
 * @param title         Title to display on the window
 * @param full_screen   Initialize to full screen mode if true, else windowed mode
 * @return  CODE_SUCCESS if success, else returns a relevant error code.
 */
int32_t window_create(Window* window, uint16_t width, uint16_t height, const char* title, bool full_screen);

/**
 * Destroys the Window structure.
 *
 * @param window    Pointer to Window structure
 */
void window_destroy(Window* window);

/**
 * Checks if the window should close.
 *
 * @param window    Pointer to Window struct
 * @return True if the window should close, else false.
 */
bool window_should_close(Window* window);

/**
 * Gets the current size of the framebuffer
 *
 * @param window    Pointer to Window struct
 * @param size      The size of the window in a vec2 formatted { width, height }
 */
void window_size(Window* window, ivec2* size);

#endif
