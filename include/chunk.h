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

#ifndef _CHUNK_H_
#define _CHUNK_H_

#include <stdint.h>

#include <block_id.h>
#include <mesh.h>

#define NORTH_FACE  0
#define SOUTH_FACE  1
#define EAST_FACE   2
#define WEST_FACE   3
#define UP_FACE     4
#define DOWN_FACE   5
#define NUM_FACES   6

typedef struct {
    uint16_t* chunk;
} Chunk;

/**
 * Allocates a Chunk in memory.
 *
 * @param chunk    Pointer to Chunk struct
 */
void chunk_allocate(Chunk* chunk);

/**
 *  Creates a chunk mesh from chunk data and a list of exposed faces/blocks.
 *  Format:
 *      [31 - 24]   Mask for exposed faces
 *      [23 - 15]   Height index
 *      [15 - 8]    Row index
 *      [7 - 0]     Column index
 *
 * @param chunk         Pointer to Chunk struct.
 * @param mesh          Pointer to resulting mesh.
 * @param indices       The indices of exposed blocks.
 * @param num_indices   Number of indices
 * @param num_faces     Number of faces visible
 */
//void chunk_mesh(Chunk* chunk, Mesh* mesh, const uint32_t* indices, int num_indices, int num_faces);

/**
 * Deletes a Chunk from memory.
 *
 * @param chunk     Pointer to Chunk struct
 */
void chunk_delete(Chunk* chunk);

#endif
