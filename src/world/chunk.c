/*
chunk.c



*/
#include "chunk.h"
#include "common.h"




void calculate_visibility(Chunk *chunk) {
    int x, y, z;
    
    Chunk *lx, *hx, *lz, *hz;

    if (px->loaded) {
        
    }
    
    chunk->visible[0] = ~0;
    for (y = 1; y < 512; y++) {
        chunk->visible[y] = chunk->visible[y - 1];
        
        for (x = 0; x < 16; x++) {
            
            for (z = 0; z < 16; z++) {
        
                if (blocks[y][x][z]->property->isOpaque) {
                    ;// set axis alligned blocks to visible
                }
            }
        }
    }
}






/*
Sends a block tick to three randomly selected blocks.
*/
void chunk_tick_handler(Chunk *chunk) {
    int i;
    
    for (i = 0; i < 3; i++)
      block_tick_handler(chunk->blocks[i][2 * i][3 * i]);
}



/*

*/
    if (!(chunk = malloc(sizeof(Chunk)))) {
        LOG_E("Failed to create Chunk at line %d of '%s'.\n", __LINE__, __FILE__);
        exit(MALLOC_ERROR);
    }
}



/*

*/
void delete_chunk(Chunk *chunk) {
    free(chunk->blocks);
    free(chunk);
    chunk = NULL;
}



/*

*/
    
}



/*

*/
    
}



/*
Allocates space for a Chunk.
No initialization is done.
*/
void allocate_chunk(Chunk *chunk) {
    if (!(chunk = malloc(sizeof(Chunk)))) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(MALLOC_ERROR);
    }
}



/*
Frees the data used by the Chunk.
No data is saved.
*/
void free_chunk(Chunk *chunk) {
    free(chunk);
    chunk = NULL;
}



/*

*/
void read_chunk(Chunk *chunk, FILE *file) {
    fread(chunk, sizeof(Chunk), 1, file);
}



/*

*/
void write_chunk(Chunk *chunk, FILE *file) {
    fwrite(chunk, sizeof(Chunk), 1, file);
}






