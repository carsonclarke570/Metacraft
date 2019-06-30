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

#ifndef MESH_FACTORY_H
#define MESH_FACTORY_H

#include <mesh.h>
#include <chunk.h>
#include <list.h>


#define TEX_PER_ROW     10
#define TEX_UNIT        (1.0f / TEX_PER_ROW)
#define TEX_X(i)        (i % TEX_PER_ROW) * TEX_UNIT
#define TEX_Y(i)        (int)(i / TEX_PER_ROW) * TEX_UNIT

const vec3 OFFSET_MAP[NUM_FACES][4] = {
        {{1.0f, 1.0f, -1.0f}, {0.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f, -1.0f}},
        {{0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}},
        {{1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, -1.0f}, {1.0f, 0.0f, -1.0f},{1.0f, 0.0f, 0.0f}},
        {{0.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, -1.0f}},
        {{0.0f, 1.0f, -1.0f}, {1.0f, 1.0f, -1.0f},{1.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}},
        {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
};

const vec3 NORMAL_MAP[NUM_FACES] = {
        {0.0f, 0.0f, -1.0f},
        {0.0f, 0.0f, 1.0f},
        {1.0f, 0.0f, 0.0f},
        {-1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, -1.0f, 0.0f},
};

const vec3 TEXTURE_MAP[4] = {
        {0.0f, 0.0f},
        {TEX_UNIT, 0.0f},
        {TEX_UNIT, TEX_UNIT},
        {0.0f, TEX_UNIT},
};



/**
 * Generates a mesh from a given Chunk and metadata.
 *
 * @param mesh      Pointer to Mesh struct.
 * @param chunk     Chunk data to extrapolate mesh data from.
 * @param metadata  Chunk metadata describing which blocks to render.
 * @param len       Length of the chunk metadata.
 */
void create_chunk_mesh(Mesh* mesh, Chunk* chunk, const uint32_t* metadata, size_t len) {

    Array vertices;
    array_allocate(&vertices, len * 4, sizeof(Vertex));

    // temporary
    uint8_t id = ID_OAK_PLANK;

    Vertex vertex;
    uint32_t idx;
    uint8_t flags, x, y, z;
    for (int i = 0; i < len; i++) {
        idx = metadata[i] >> 15u;
        flags = metadata[i] >> 9u;

        x = 0;
        y = 0;
        z = 0;

        int flag = 0;
        for (int j = 0; j < 6; j++) {
            if (flags & 0x1u) {
                for (int k = 0; k < 4; k++) {
                    vertex.position[0] = (x * BLOCK_SIZE) + OFFSET_MAP[flag][k][0];
                    vertex.position[1] = (y * BLOCK_SIZE) + OFFSET_MAP[flag][k][1];
                    vertex.position[2] = (z * BLOCK_SIZE) + OFFSET_MAP[flag][k][2];

                    vertex.normal[0] = NORMAL_MAP[flag][0];
                    vertex.normal[1] = NORMAL_MAP[flag][1];
                    vertex.normal[2] = NORMAL_MAP[flag][2];

                    vertex.texture[0] = TEXTURE_MAP[k][0] + TEX_X(id);
                    vertex.texture[1] = 1.0f - TEX_Y(id) - TEXTURE_MAP[k][1];
                }
                array_add(&vertices, &vertex);
            }
            flag++;
            flags = flags >> 1u;
        }

    }

    // TO-DO: Add configuration to mesh generation
    mesh_create(mesh, vertices.data, vertices.size, NULL, 0);
    array_delete(&vertices);
}

#endif
