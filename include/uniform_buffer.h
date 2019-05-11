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

#ifndef _UNIFORM_BUFFER_H_
#define _UNIFORM_BUFFER_H_

#include <stdint.h>

#include <shader.h>

typedef struct {
    GLuint ubo;
} UniformBuffer;

/**
 * Creates a new Uniform Buffer with of a specified size.
 *
 * @param buffer    Pointer to UniformBuffer struct
 * @param size      Size of buffer to create.
 * @param slot      Slot to allocate buffer in.
 */
void uniform_buffer_create(UniformBuffer* buffer, size_t size, uint32_t slot);

/**
 * Destroys a Uniform Buffer.
 *
 * @param buffer    Pointer to UniformBuffer struct
 */
void uniform_buffer_delete(UniformBuffer* buffer);

/**
 * Store data in the uniform buffer
 *
 * @param buffer    Pointer to UniformBuffer struct
 * @param offset    Offset in bytes of where to put the data
 * @param size      Size of the data
 * @param data      The data.
 */
void uniform_buffer_store(UniformBuffer* buffer, size_t offset, size_t size, const void* data);

#endif
