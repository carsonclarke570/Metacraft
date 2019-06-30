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

#ifndef _FRAMEBUFFER_H_
#define _FRAMEBUFFER_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <glad/glad.h>

#include <shader.h>
#include <vector.h>

typedef struct {
    GLint internal_format;
    GLenum format;
    GLenum type;
    GLenum target;
    GLenum filter;
} Attachment;

typedef struct {
    GLuint buffer;
    GLuint* textures;
    GLuint depth;
    ivec2 size;
    int n;
} Framebuffer;

/**
 * Creates a framebuffer.
 *
 * @param buffer        Pointer to Framebuffer struct
 * @param attachments   List of attachments for the framebuffer
 * @param n             Number of attachments
 * @param size          Size of the3 framebuffer
 * @param depth         Whether or to attach a depth buffer
 */
void framebuffer_create(Framebuffer* buffer, Attachment* attachments, int n, ivec2 size, bool depth);

/**
 * Destroys a framebuffer.
 *
 * @param buffer    Pointer to Framebuffer struct
 */
void framebuffer_delete(Framebuffer* buffer);

/**
 * Binds the framebuffer for writing.
 *
 * @param buffer    Pointer to Framebuffer struct
 */
void framebuffer_bind(Framebuffer* buffer);

/**
 * Unbinds the frambuffer.
 *
 * @param buffer    Pointer to Framebuffer struct
 */
void framebuffer_unbind();

/**
 * Binds all the attachments to textures 0 to N of a particular shader.
 *
 * @param buffer    Pointer to Framebuffer struct
 * @param shader    Shader to update
 */
void framebuffer_bind_textures(Framebuffer* buffer, Shader* shader);

/**
 * If there is a depth buffer, attempts to blit the buffer.
 *
 * @param buffer    Pointer to Framebuffer struct
 */
void framebuffer_blit_depth(Framebuffer* buffer);

#endif
