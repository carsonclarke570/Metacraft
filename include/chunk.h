/*
    Copyright 2019 Wesley Dahar

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
#ifndef CHUNK_H
#define CHUNK_H

#include "block.h"
#include "entity.h"
#include "mesh.h"


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
    Chunk *north;               // adjacent northern chunk
    Chunk *south;               // adjacent southern chunk
    Chunk *east;                // adjacent eastern chunk
    Chunk *west;                // adjacent western chunk
    uint32_t *visible;          // ordered list of visible Block indices
    uint32_t *updated;          // ordered list of Block indicies to be evaluated
    uint32_t *active;           // ordered list of active Block indices
    Mesh *mesh;                 // 
    EntityCache *entityCache;   // 
    int64_t x;                  // chunk X coordinate
    int64_t z;                  // chunk Z coordinate
    uint64_t lastTick;          // last tick value 
    uint64_t inhabitedTime;     // number of ticks occupied by players
    uint32_t visibleCount;      // number of visible Block indicies
    uint32_t updatedCount;      // number of Block indicies to be evaluated
    uint16_t activeCount;       // number of active Block indicies
    uint8_t dirty;              // 
    Block blocks[131072];       // array of Blocks [y = 512][x = 16][z = 16]
} Chunk;



/*
Recalculates the Chunk's 'visible' and 'updated' lists. Any loaded, adjacent
Chunks will have their Blocks along the edge of contact recalculated as well.
This is a resource intensive task and should only be called when a Chunk is
first generated.

WARNING: This method will read, but not use the data in the address range
of +/- 256 blocks of the 'blocks' array.

Parameters:
    Chunk *chunk - The chunck for which to recalculate visibility.
Returns:
Errors:
*/
void calculate_visibility(Chunk *chunk);



/*


Parameters:
Returns:
Errors:
*/
void chunk_tick_handler(Chunk *chunk);



/*
Allocates space for a Chunk. No initialization is done.

Parameters:
Returns:
    Chunk * - The allocated Chunk.
Errors:
    CODE_MALLOC_ERROR
*/
Chunk *allocate_chunk();



/*
Frees the data used by the Chunk.

Parameters:
    Chunk *chunk - The Chunk to free.
Returns:
Errors:
*/
void free_chunk(Chunk *chunk);



/*

Parameters:
    Chunk *chunk - The Chunk to read into.
    FILE *file - The file to read from.
    int64_t x - 
    int64_t z - 
Returns:
Errors:
*/
void read_chunk(Chunk *chunk, int64_t x, int64_t z);



/*

Parameters:
    Chunk *chunk - The Chunk to write from.
Returns:
Errors:
*/
void write_chunk(Chunk *chunk);



/*
The reconsiles outstanding Block updates with the visible Block data,
and uses the Chunks visible block data to generate a renderable Mesh.

Parameters:
    Chunk *chunk - The Chunk for which to generate a Mesh.
Returns:
Errors:
    CODE_MALLOC_ERROR
*/
void generate_chunk_mesh(Chunk *chunk);



// Global Vertex and Index Buffers
static Vertex sVertexBuffer[];
static uint32_t sIndexBuffer[];


#endif


