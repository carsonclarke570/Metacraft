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

#include "chunk.h"

void chunk_allocate(Chunk* chunk) {
    chunk->chunk = malloc(CHUNK_HEIGHT * CHUNK_WIDTH * CHUNK_WIDTH * sizeof(uint16_t));
}

void chunk_mesh(Chunk* chunk, Mesh* mesh, const uint32_t* indices, int num_indices, int num_faces) {
    mesh_delete(mesh);

    Vertex *m_vertices = malloc(num_faces * 4 * sizeof(Vertex));
    unsigned int *m_indices = malloc(num_faces * 6 * sizeof(unsigned int));

    int v_i = 0;
    int i_i = 0;

    uint32_t idx;
    uint8_t r, c, h, faces;
    for (int i = 0; i < num_indices; i++) {
        idx = indices[i];
        c = idx & 0xFFu;
        r = (idx >> 8u) & 0xFFu;
        h = (idx >> 16u) & 0xFFu;
        faces = (idx >> 24u) & 0xFFu;

        float off = (CHUNK_MESH_SIZE / 2.0f);
        if (faces & FACE_EAST) {
            // Construct face
            Vertex face[4] = {
                    {{-off + ((c+1) * BLOCK_SIZE), h * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
                    {{-off + ((c+1) * BLOCK_SIZE), (h+1) * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
                    {{-off + ((c+1) * BLOCK_SIZE), (h+1) * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
                    {{-off + ((c+1) * BLOCK_SIZE), h * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}}
            };
            memcpy(&m_vertices[v_i], face, sizeof(Vertex) * 4);

            // Construct face indices
            m_indices[i_i] = v_i;
            m_indices[i_i + 1] = v_i + 3;
            m_indices[i_i + 2] = v_i + 2;
            m_indices[i_i + 3] = v_i + 2;
            m_indices[i_i + 4] = v_i + 1;
            m_indices[i_i + 5] = v_i;
            v_i += 4;
            i_i += 6;
        }
        if (faces & FACE_WEST) {
            // Construct face
            Vertex face[4] = {
                    {{-off + (c * BLOCK_SIZE), h * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
                    {{-off + (c * BLOCK_SIZE), (h+1) * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
                    {{-off + (c * BLOCK_SIZE), (h+1) * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {-1.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
                    {{-off + (c * BLOCK_SIZE), h * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {-1.0f, 0.0f, 0.0f}, {1.0f, 0.0f}}
            };
            memcpy(&m_vertices[v_i], face, sizeof(Vertex) * 4);

            // Construct face indices
            m_indices[i_i] = v_i + 2;
            m_indices[i_i + 1] = v_i + 3;
            m_indices[i_i + 2] = v_i;
            m_indices[i_i + 3] = v_i;
            m_indices[i_i + 4] = v_i + 1;
            m_indices[i_i + 5] = v_i + 2;
            v_i += 4;
            i_i += 6;
        }
        if (faces & FACE_UP) {
            // Construct face
            Vertex face[4] = {
                    {{-off + ((c+1) * BLOCK_SIZE), (h+1) * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
                    {{-off + (c * BLOCK_SIZE), (h+1) * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
                    {{-off + (c * BLOCK_SIZE), (h+1) * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},
                    {{-off + ((c+1) * BLOCK_SIZE), (h+1) * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f}}
            };
            memcpy(&m_vertices[v_i], face, sizeof(Vertex) * 4);

            // Construct face indices
            m_indices[i_i] = v_i;
            m_indices[i_i + 1] = v_i + 2;
            m_indices[i_i + 2] = v_i + 1;
            m_indices[i_i + 3] = v_i;
            m_indices[i_i + 4] = v_i + 3;
            m_indices[i_i + 5] = v_i + 2;
            v_i += 4;
            i_i += 6;
        }

        if (faces & FACE_DOWN) {
            // Construct face
            Vertex face[4] = {
                    {{-off + (c * BLOCK_SIZE), h * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {0.0f, -1.0f, 0.0f}, {0.0f, 1.0f}},
                    {{-off + ((c+1) * BLOCK_SIZE), h * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {0.0f, -1.0f, 0.0f}, {1.0f, 1.0f}},
                    {{-off + (c * BLOCK_SIZE), h * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f}},
                    {{-off + ((c+1) * BLOCK_SIZE), h * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {0.0f, -1.0f, 0.0f}, {1.0f, 0.0f}}
            };
            memcpy(&m_vertices[v_i], face, sizeof(Vertex) * 4);

            // Construct face indices
            m_indices[i_i] = v_i;
            m_indices[i_i + 1] = v_i + 2;
            m_indices[i_i + 2] = v_i + 1;
            m_indices[i_i + 3] = v_i + 1;
            m_indices[i_i + 4] = v_i + 2;
            m_indices[i_i + 5] = v_i + 3;
            v_i += 4;
            i_i += 6;
        }

        if (faces & FACE_NORTH) {
            // Construct face
            Vertex face[4] = {
                    {{((c+1) * BLOCK_SIZE) - off, (h+1) * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f}},
                    {{(c * BLOCK_SIZE) - off, (h+1) * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {0.0f, 0.0f, -1.0f}, {1.0f, 1.0f}},
                    {{((c+1) * BLOCK_SIZE) - off, h * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f}},
                    {{(c * BLOCK_SIZE) - off, h * BLOCK_SIZE, off - ((r+1) * BLOCK_SIZE)},
                            {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f}}
            };
            memcpy(&m_vertices[v_i], face, sizeof(Vertex) * 4);

            // Construct face indices
            m_indices[i_i] = v_i;
            m_indices[i_i + 1] = v_i + 2;
            m_indices[i_i + 2] = v_i + 1;
            m_indices[i_i + 3] = v_i + 1;
            m_indices[i_i + 4] = v_i + 2;
            m_indices[i_i + 5] = v_i + 3;
            v_i += 4;
            i_i += 6;
        }

        if (faces & FACE_SOUTH) {
            // Construct face
            Vertex face[4] = {
                    {{(c * BLOCK_SIZE) - off, (h+1) * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
                    {{((c+1) * BLOCK_SIZE) - off, (h+1) * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
                    {{(c * BLOCK_SIZE) - off, h * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
                    {{((c+1) * BLOCK_SIZE) - off, h * BLOCK_SIZE, off - (r * BLOCK_SIZE)},
                            {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}}
            };
            memcpy(&m_vertices[v_i], face, sizeof(Vertex) * 4);

            // Construct face indices
            m_indices[i_i] = v_i;
            m_indices[i_i + 1] = v_i + 2;
            m_indices[i_i + 2] = v_i + 1;
            m_indices[i_i + 3] = v_i + 1;
            m_indices[i_i + 4] = v_i + 2;
            m_indices[i_i + 5] = v_i + 3;
            v_i += 4;
            i_i += 6;
        }
    }
    mesh_create(mesh, m_vertices, num_faces * 4, m_indices, num_faces * 6);

    free(m_vertices);
    free(m_indices);
}

void chunk_delete(Chunk* chunk) {
    free(chunk->chunk);
    chunk->chunk = NULL;
}