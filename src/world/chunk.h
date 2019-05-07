/*
chunk.h

...

*/
#ifndef CHUNK_H
#define CHUNK_H

#include "block.h"



/*
A 16x512x16 section of blocks.
Contains Entity and misc metadata.
*/
typedef struct {
    int64_t x;                  // chunk X coordinate
    int64_t y;                  // chunk Y coordinate
    int64_t lastTick;           // last tick value 
    int64_t inhabitedTime;      // number of ticks occupied by players
    EntityCache *entities;      // 
    uint32_t *metadata;         // all chunk metadata
    uint16_t visible[512];      // map of visible Blocks [y]
    Block blocks[512][16][16];  // array of Blocks [y][x][z]
} Chunk;



/*
Function Prototypes
*/
void allocate_chunk(Chunk *chunk);
void free_chunk(Chunk *chunk);

void read_chunk(Chunk *chunk, FILE *file);
void write_chunk(Chunk *chunk, FILE *file);



#endif



