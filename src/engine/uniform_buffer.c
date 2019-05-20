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

#include "uniform_buffer.h"


void uniform_buffer_create(UniformBuffer* buffer, size_t size, uint32_t slot) {
    glGenBuffers(1, &buffer->ubo);
    glBindBuffer(GL_UNIFORM_BUFFER, buffer->ubo);
    glBufferData(GL_UNIFORM_BUFFER, size, NULL, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    glBindBufferRange(GL_UNIFORM_BUFFER, slot, buffer->ubo, 0, size);
}


void uniform_buffer_delete(UniformBuffer* buffer) {
    glDeleteBuffers(1, &buffer->ubo);
}


void uniform_buffer_store(UniformBuffer* buffer, size_t offset, size_t size, const void* data) {
    glBindBuffer(GL_UNIFORM_BUFFER, buffer->ubo);
    glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
