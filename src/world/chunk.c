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
#include "chunk.h"



void calculate_visibility(Chunk *chunk) {
    uint_fast32_t id, v, bi = 0, vi = 0;
    
    // ensures index calculations are within address space
    uint_fast32_t mask;
    
    while (bi < 512 * 16 * 16) {
        while (~(bi & 0xF0)) {
            while (~(bi & 0xF)) {
                id = chunk->blocks[bi] >> BLOCK_ID;
                
                v = blockMetas[chunk->blocks[bi] >> BLOCK_ID].flags &
                        BF_PARTIAL << (13 - BF_PARTIAL);
                
                
                // north face, decreasing z
                v |= ((blockMetas[chunk->blocks[(bi - 1) & mask] >> BLOCK_ID].flags &
                      BF_TRANSLUCENT) << (19 - BF_TRANSLUCENT)) & ~(bi & 0xF);
                
                // south face, increasing z
                v |= ((blockMetas[chunk->blocks[bi + 1] >> BLOCK_ID].flags &
                      BF_TRANSLUCENT) << (18 - BF_TRANSLUCENT)) & (bi & 0xF);
                
                // east face, increasing x
                v |= ((blockMetas[chunk->blocks[bi + 16] >> BLOCK_ID].flags &
                      BF_TRANSLUCENT) << (17 - BF_TRANSLUCENT)) & (bi & 0xF0);
                
                // west face, decreasing x
                v |= ((blockMetas[chunk->blocks[bi - 16] >> BLOCK_ID].flags &
                      BF_TRANSLUCENT) << (16 - BF_TRANSLUCENT)) & (bi & 0xF0);
                
                // top face, increasing y
                v |= ((blockMetas[chunk->blocks[bi + 256] >> BLOCK_ID].flags &
                      BF_TRANSLUCENT) << (15 - BF_TRANSLUCENT)) & (bi & 0x1FF00);
                
                // bottom face, decreasing y
                v |= ((blockMetas[chunk->blocks[bi - 256] >> BLOCK_ID].flags &
                      BF_TRANSLUCENT) << (14 - BF_TRANSLUCENT)) & (bi & 0x1FF00);
                
                if (v) {
                    chunk->visible[vi++] = (bi << 20) | v;
                }
            }
        }
    }
    
    // clear visibility updates
    chunk->updatedCount = 0;
}



void chunk_tick_handler(Chunk *chunk) {
    int i;
    
    for (i = 0; i < 6; i++)
        block_tick_handler(chunk->blocks[i]);
}



void generate_chunk_mesh(Chunk* chunk) {
    mesh_delete(chunk->mesh);
    
    int_fast32_t ui = 0, vi = 0;
    int_fast32_t faces;
    uint32_t *dataRead, *dataWrite;
    
    while (ui < chunk->updatedCount) {
        if (chunk->updated[ui] < chunk->visible[vi]) {
            // add block mesh components
        } else if (!(chunk->updated[ui] ^ chunk->visible[vi]) >> 6) {
            // equal
            ui++;
            // add block mesh components
        } else {
            // apply
            ui++;
            if (1) vi++;
            else vi --;
            // add block mesh components
        }
    }
    
    for (; vi < chunk->visibleCount; vi++) {
        // add block mesh components
        //sVertexBuffer[vi] = {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}};
        //sIndexBuffer[vi] = 0;
    }
    
    chunk->updatedCount = 0;
    
    mesh_create(chunk->mesh, sVertexBuffer, faces * 4, sIndexBuffer, faces * 6);
}



Chunk *allocate_chunk() {
    Chunk *chunk;
    
    if (!(chunk = malloc(sizeof(Chunk)))) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
    
    return chunk;
}



void free_chunk(Chunk *chunk) {
    free(chunk->blocks);
    free(chunk);
    chunk = NULL;
}



void read_chunk(Chunk *chunk, FILE *file, int64_t x, int64_t z) {
    uint8_t compressed, fill[4], index, id, tag;
    int i, j;
    
    // chunk metadata
    chunk->x = x;
    chunk->z = z;
    fread(chunk->lastTick, 8, 1, file);
    fread(chunk->inhabitedTime, 8, 1, file);
    
    // blocks
    for (i = 0; i < 131072; i++) {
        fread(&compressed, 1, 1, file);
        
        if (compressed) {
            fread(&fill, 1, 4, file);
            
            for (j = 0; j < fill[3]; j++) {
                fread(&index, 1, 1, file);
                
                for (; i < index; i++) {
                    chunk->blocks[i] = fill[0];
                }
                
                fread(&chunk->blocks[i], sizeof(Block), 1, file);
                chunk->blocks[i] = fill[0];
            }
            
            for (; i < 256; i++) {
                chunk->blocks[i] = fill[0];
            }
        } else {
            for (i = j; i < 256; i++) {
                fread(&id, 1, 1, file);
                fread(&tag, 1, 1, file);
                chunk->blocks[i] = id;
            }
        }
    }
    
    // entities
    fread(&chunk->entityCache, 8, 1, file);
    
}



/*

*/
void write_chunk(Chunk *chunk, FILE *file) {
    fwrite(chunk, sizeof(Chunk), 1, file);
}


