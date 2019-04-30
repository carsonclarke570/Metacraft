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

#include <mesh.h>


void mesh_create(Mesh* mesh, Vertex* vertices, unsigned int num_v, unsigned int* indices, unsigned int num_i, Texture **textures, unsigned int num_t) {
    mesh->textures = textures;
    mesh->num_textures = num_t;

    if (indices) {
        mesh->num_elements = num_i;
        mesh->indexed = true;
    } else {
        mesh->num_elements = num_v;
        mesh->indexed = false;
    }
    glGenVertexArrays(1, &mesh->vao);
    glGenBuffers(1, &mesh->vbo);
    glGenBuffers(1, &mesh->ibo);

    glBindVertexArray(mesh->vao);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * num_v, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * num_i, indices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position)); // Position
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal)); // Normal
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texture)); // Normal

    glBindVertexArray(0);
}

void mesh_destroy(Mesh* mesh) {
    glDeleteVertexArrays(1, &mesh->vao);
    glDeleteBuffers(1, &mesh->vbo);
    glDeleteBuffers(1, &mesh->ibo);
}


void mesh_render(Mesh* mesh, Shader* shader) {
    for (unsigned int i = 0; i < mesh->num_textures; i++) {
        register_texture(shader, mesh->textures[i], i);
        bind_texture(mesh->textures[i], i);
    }
    glBindVertexArray(mesh->vao);
    if (mesh->indexed) {
        glDrawElements(GL_TRIANGLES, mesh->num_elements, GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, mesh->num_elements);
    }
}
