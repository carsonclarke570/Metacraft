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

#ifndef _COMMON_H_
#define _COMMON_H_

// Error Codes
#define CODE_SUCCESS            0
#define CODE_GLFW_INIT_ERR      1
#define CODE_WINDOW_CREATE_ERR  2
#define CODE_GLAD_INIT_ERR      3

// GL
#define GL_VER_MAJ  3
#define GL_VER_MIN  3

#define GL_CLEAR_COLOR_R 0.2f
#define GL_CLEAR_COLOR_G 0.3f
#define GL_CLEAR_COLOR_B 0.3f

#define NO_COPY(T)                     \
    T(const T&) = delete;              \
    void operator=(const T&) = delete;

#endif
