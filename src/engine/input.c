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

#include <input.h>


void input_init(Input* input, Window* window) {
    double xpos, ypos;
    glfwGetCursorPos(window->window, &xpos, &ypos);

    input->cursor_offset[0] = 0.0f;
    input->cursor_offset[1] = 0.0f;
    input->cursor_position[0] = (float) xpos;
    input->cursor_position[1] = (float) ypos;
}

void input_poll(Input* input, Window* window) {
    double xpos, ypos;
    glfwGetCursorPos(window->window, &xpos, &ypos);

    input->cursor_offset[0] = xpos - input->cursor_position[0];
    input->cursor_offset[1] = input->cursor_position[1] - ypos;
    input->cursor_position[0] = xpos;
    input->cursor_position[1] = ypos;
}

void input_cursor_mode(Window* window, enum CursorMode mode) {
    glfwSetInputMode(window->window, GLFW_CURSOR, mode);
}



