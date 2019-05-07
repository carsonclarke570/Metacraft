/*
world.c



*/
#include "world.h"
#include "common.h"



/*

*/
void load_chunk(World *world, int x, int y) {
    ChunkCache *cache = world->chunkCache;
    Chunk *chunk;
    double compliance, c;
    int i, ui;
    int px = world->playerList[0]->x / 16;
    int py = world->playerList[0]->y / 16;
    vec2 velocity = { x - px, y - py };
    
    // update load velocity
    cache->loadVelocity[0] = (0.9 * cache->loadVelocity[0]) + (0.1 * velocity[0]);
    cache->loadVelocity[1] = (0.9 * cache->loadVelocity[1]) + (0.1 * velocity[1]);
    
    // look for chunk in cache and determine potential unload/uncache element
    for (i = 0; i < cache->cached; i++) {
        
        // check for least compliance for the unload chunk candidate index
        velocity[0] = cache->data[i]->x - px;
        velocity[1] = cache->data[i]->y - py;
        c = dot_product(velocity, cache->loadVelocity);
        if (c < compliance) {
            compliance = c;
            ui = i;
        }
        
        if (cache->data[i]->x == x && cache->data[i]->y == y) {
            if (i >= cache->loaded) {
                chunk = cache->data[i];
                cache->data[i] = cache->data[cache->loaded];
                cache->data[cache->loaded] = chunk;
                cache->loaded++;
            }
            
            return;
        }
    }
    
    // create pointer to chunk to read or generate
    if (cache->cached < cache->capacity) {
        
        // cache is not full, allocate new chunk
        cache->data[cache->cached] = cache->data[cache->loaded];
        cache->cached++;
        chunk = cache->data[cache->loaded];
        if (!(chunk = malloc(sizeof(Chunk)))) {
            LOG_E("Failed to allocate Chunk.\n");
            exit(MALLOC_ERROR);
        }
    } else if (cache->capacity < cache->maximum) {
        
        // cache is full, resize cache
        cache->capacity += 16;
        
        if (cache->capacity > cache->maximum)
            cache->capacity = cache->maximum;
        
        if (!(cache->data = realloc(cache->data, cache->capacity * sizeof(Chunk *)))) {
            LOG_E("Failed to reallocate ChunkCache.\n");
            exit(MALLOC_ERROR);
        }
        
        chunk = cache->data[cache->loaded];
        if (!(chunk = malloc(sizeof(Chunk)))) {
            LOG_E("Failed to allocate Chunk.\n");
            exit(MALLOC_ERROR);
        }
    } else if (cache->loaded < cache->cached) {
        
        // cache is full, uncache chunk
        chunk = cache->data[ui];
        cache->data[ui] = cache->data[cache->loaded];
        cache->data[cache->loaded] = chunk;
    } else {
        
        // cache is full, uncache chunk
        chunk = cache->data[ui];
        cache->data[ui] = cache->data[cache->loaded];
        cache->data[cache->loaded] = chunk;
    }
    
    // look for chunk in persistent storage
    for (i = 0; i < genList->size; i++) {
        if (xy == genlist[i]) {
            read_chunk(chunk, genlist[i]);
            cache->loaded++;
            return;
        }
    }
    
    // generte the chunk
    generate_chunk(chunk, world, x, y);
    cache->loaded++;
}



/*

*/
generate_chunk(Chunk *chunk, World *world, int x, int y) {
    
    
}



/*
Allocates space for an entire World struct. No initialization is done.
*/
void allocate_world(World *world) {
    if (
        !(world = malloc(sizeof(World))) ||
        !(world->chunkCache = calloc(sizeof(ChunkCache))) ||
        !(world->playerList = calloc(sizeof(PlayerList))) ||
        !(world->version = malloc(sizeof(Version))) ||
        !(world->weather = malloc(sizeof(Weather)))
    ) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(MALLOC_ERROR);
    }
}



/*
Frees the Player, Weather, and Chunk data used by the World.
No data is saved.
*/
void free_world(World *world) {
    int i;
    
    for (i = 0; i < world->playerList->size; i++)
        free_player(world->playerList[i]);
    free(world->playerList->players);
    free(world->playerList);
    
    for (i = 0; i < world->chunkCache->cached; i++)
        free_chunk(world->chunkCache[i]);
    free(world->chunkCache->chunks);
    free(world->chunkCache);
    
    free(world->weather);
    
    free(world);
    world = NULL;
}



/*

*/
void read_world(World *world, FILE *file) {
    fread(world, sizeof(World), 1, file);
    fread(world->version, sizeof(Version), 1, file);
    fread(world->weather, sizeof(Weather), 1, file);
}



/*

*/
void write_world(World *world, FILE *file) {
    fwrite(world, sizeof(World), 1, file);
    fwrite(world->version, sizeof(Version), 1, file);
    fwrite(world->weather, sizeof(Weather), 1, file);
}














