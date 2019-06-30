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

#ifndef _INPUT_H_
#define _INPUT_H_

#include <vector.h>
#include <window.h>

typedef struct {
    vec3 cursor_position;
    vec3 cursor_offset;
} Input;

enum CursorMode {
    CURSOR_NORMAL = GLFW_CURSOR_NORMAL,
    CURSOR_DISABLED = GLFW_CURSOR_DISABLED,
    CURSOR_HIDDEN = GLFW_CURSOR_HIDDEN
};

/**
 * Initializes input.
 *
 * @param input     Pointer to Input struct
 * @param window    Window object to bind input to
 */
void input_init(Input* input, Window* window);

/**
 * Polls input.
 *
 * @param input     Pointer to Input struct
 * @param window    Window object to bind input to
 */
void input_poll(Input* input, Window* window);

/**
 * Sets the cursor mode.
 * Modes:
 *  - Normal: Mouse behaves normally
 *  - Disabled: Hides cursor and locks it to the center
 *  - Hidden: Hides cursor, behaves normally.
 *
 * @param window    Window object to bind input to
 * @param mode      Cursor mode.
 */
void input_cursor_mode(Window* window, enum CursorMode mode);

#endif
