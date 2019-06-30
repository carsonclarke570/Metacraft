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
#include "world.h"



void load_chunk(int64_t x, int64_t z) {
    ChunkCache *cache = &sWorld.chunkCache;
    Chunk *chunk;
    double compliance, c;
    int i, ui;
    int px = sWorld.playerCache.players[0].entity->position[1] / 16;
    int pz = sWorld.playerCache.players[0].entity->position[2] / 16;
    double velocity[2] = {x - px, z - pz};
    
    // update load velocity
    cache->loadVelocity[0] = (0.9 * cache->loadVelocity[0]) + (0.1 * velocity[0]);
    cache->loadVelocity[1] = (0.9 * cache->loadVelocity[1]) + (0.1 * velocity[1]);
    
    // look for chunk in cache and determine potential unload/uncache element
    for (i = 0; i < cache->cached; i++) {
        
        // check for least compliance for the unload chunk candidate index
        velocity[0] = cache->chunks[i]->x - px;
        velocity[1] = cache->chunks[i]->z - pz;
        c = dot_product(velocity, cache->loadVelocity);
        if (c < compliance) {
            compliance = c;
            ui = i;
        }
        
        if (cache->chunks[i]->x == x && cache->chunks[i]->z == z) {
            if (i >= cache->loaded) {
                chunk = cache->chunks[i];
                cache->chunks[i] = cache->chunks[cache->loaded];
                cache->chunks[cache->loaded] = chunk;
                cache->loaded++;
            }
            
            return;
        }
    }
    
    // create pointer to chunk to read or generate
    if (cache->cached < cache->capacity) {
        
        // cache is not full, allocate new chunk
        cache->chunks[cache->cached] = cache->chunks[cache->loaded];
        cache->cached++;
        chunk = cache->chunks[cache->loaded];
        if (!(chunk = malloc(sizeof(Chunk)))) {
            LOG_E(LOG_MSG_MALLOC_ERROR);
            exit(CODE_MALLOC_ERROR);
        }
    } else if (cache->capacity < cache->maximum) {
        
        // cache is full, resize cache
        cache->capacity += 16;
        
        if (cache->capacity > cache->maximum)
            cache->capacity = cache->maximum;
        
        if (!(cache->chunks = realloc(cache->chunks, cache->capacity * sizeof(Chunk *)))) {
            LOG_E(LOG_MSG_MALLOC_ERROR);
            exit(CODE_MALLOC_ERROR);
        }
        
        chunk = cache->chunks[cache->loaded];
        if (!(chunk = malloc(sizeof(Chunk)))) {
            LOG_E(LOG_MSG_MALLOC_ERROR);
            exit(CODE_MALLOC_ERROR);
        }
    } else if (cache->loaded < cache->cached) {
        
        // cache is full, uncache chunk
        chunk = cache->chunks[ui];
        cache->chunks[ui] = cache->chunks[cache->loaded];
        cache->chunks[cache->loaded] = chunk;
    } else {
        
        // cache is full, uncache chunk
        chunk = cache->chunks[ui];
        cache->chunks[ui] = cache->chunks[cache->loaded];
        cache->chunks[cache->loaded] = chunk;
    }
    
    // look for chunk in persistent storage
    /*
    for (i = 0; i < genList->size; i++) {
        if (xy == genlist[i]) {
            read_chunk(chunk, genlist[i]);
            cache->loaded++;
            return;
        }
    }
    */
    
    // generte the chunk
    generate_chunk(chunk, &sWorld, x, z);
    cache->loaded++;
}



void unload_chunk(Chunk *chunk) {
    // save
    // clear misc data
}



Chunk *generate_chunk(int64_t x, int64_t z) {
    // if found in cache, regen
    // else gen
}



char *generate_blockLore(Block *block) {
    static char buffer[128];
    uint16_t id = *block >> 4;
    //uint16_t tag = (uint64_t) chunk - (uint64_t) block;
    uint8_t *data = get_tagData(block);
    int i = 0;
    /*
    for (i = 0; i < blockMetas[id].stateTagCount; i++) {
        i += strcpy(&gTagAttributeStrings[blockMetas[id].stateTags[id]], &buffer[i]);
        i += strcpy(&gTagValueStrings[blockMetas[id].stateTags[id]], &buffer[i]);
        buffer[i] = '\n';
    }
    
    if (tag) {
        while (data[i]) {
            i += strcpy(&gTagAttributeStrings[blockMetas[id].stateTags[id]], &buffer[i]);
            i += strcpy(&gTagValueStrings[blockMetas[id].stateTags[id]], &buffer[i]);
            buffer[i] = '\n';
            i++;
        }
    }
    */
    buffer[i] = '\0';
    return buffer;
}



void load_world() {
    
}



void unload_world() {
    
}



void initialize_world() {
    sWorld.version.major = METACRAFT_VERSION_MAJOR;
    sWorld.version.minor = METACRAFT_VERSION_MINOR;
    sWorld.version.stable = METACRAFT_VERSION_STABLE;
    sWorld.version.release = METACRAFT_VERSION_RELEASE;
    sWorld.version.date = METACRAFT_VERSION_DATE_STRING;
    
    sWorld.name = NULL;
    
    memcpy(&sWorld.gamerule, &sGamerule, sizeof(Gamerule));
    
    sWorld.ticks = 0;
    
    sWorld.seed = 0;
    sWorld.sealevel = 128;
    sWorld.buildheight = 512;
    sWorld.spawnChunkX = 0;
    sWorld.spawnChunkY = 0;

    sWorld.playerCache.capacity = 0;
    sWorld.playerCache.cached = 0;
    sWorld.playerCache.players = 0;
}



void free_world() {
    int i;
    
    for (i = 0; i < sWorld.playerCache.cached; i++)
        free_player(sWorld.playerCache.players[i]);
    free(sWorld.playerCache.players);
    
    for (i = 0; i < sWorld.chunkCache.cached; i++)
        free_chunk(sWorld.chunkCache.chunks[i]);
    free(sWorld.chunkCache.chunks);
}



void read_world(FILE *file) {
    fread(&sWorld, sizeof(World), 1, file);
    fread(&sWorld.version, sizeof(Version), 1, file);
}



void write_world(FILE *file) {
    fwrite(&sWorld, sizeof(World), 1, file);
    fwrite(&sWorld.version, sizeof(Version), 1, file);
}



void set_block(int64_t x, int64_t y, int64_t z, uint16_t id) {
    // get chunk
    // remove block
    // set block
    // update neighbors
}



void fill_blocks(int64_t x0, int64_t y0, int64_t z0, int64_t x1, int64_t y1,
        int64_t z1, uint16_t id) {
    // remove blocks
    // set blocks
    // update neighbors
}



void place_block(int64_t x, int64_t y, int64_t z, Block *block) {
    // destroy replaced block
    // place block
    // update neghbors
}



void break_block(int64_t x, int64_t y, int64_t z) {
    // 
}


