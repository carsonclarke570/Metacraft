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

#ifndef _SKYBOX_H_
#define _SKYBOX_H_

#include <shader.h>

typedef struct {
    GLuint vao;
    GLuint vbo;
} CubeMap;

/**
 * Creates a new sky box.
 *
 * @param box   Pointer to SkyBox struct
 */
void cubemap_create(CubeMap *box);

/**
 * Destroys a sky box.
 *
 * @param box   Pointer to SkyBox struct
 */
void cubemap_delete(CubeMap *box);

/**
 * Renders a sky box.
 *
 * @param box       Pointer to SkyBox struct
 * @param shader    Shader to run on the sky box
 */
void cubemap_render(CubeMap *box, Shader *shader);

#endif
