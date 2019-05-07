/*
world.h


*/
#ifndef WORLD_H
#define WORLD_H

#include "chunk.h"
#include "player.h"
#include "weather.h"



typedef struct {
    int maximum;        // maximum allocated cache size
    int capacity;       // allcated cache size
    int cached;         // number of Chunks cached
    int loaded;         // number of Chunks loaded
    vec2 loadVelocity;  // vector representation of load direction
    Chunk **data;       // array of Chunk pointers
} ChunkCache;



typedef struct {
    int capacity;     // maximum list size
    int size;         // number of Players listed
    Player *players;  // Player data
} PlayerList;



typedef struct {
    bool precipitating; // 
    int ticks;          // number of game ticks elapsed since end of last precipitation event
    int cloudCover;     // 
} Weather;



typedef struct {
    int major;
    int minor;
    bool stable;
    long date;
} Version;



typedef struct {
    Version *version;
    char *name;
    long lastPlayed;
    long sizeOnDisk;
    
    int gamemode;
    int gamerules[16];
    int difficulty;
    bool difficultyLocked;
    bool allowCommands;
    long time;
    long ticks;             // 
    long seed;              // 
    int spawnChunk[2];
    int sealevel;           // sealevel
    int buildheight;        // world Build height
    Meta *meta;
    ChunkCache *chunkCache; // 
    Border *border; // 
    PlayerList *playerList; // 
    Weather *weather;       // 
} World;



/*
Function Prototypes
*/
World *create_world();
void delete_world(World *world);

void read_world(World *world, FILE *file);
void write_world(World *world, FILE *file);

void load_chunk(World *world, int x, int y);
Chunk *get_chunk(World *world, int x, int y);
Chunk *generate_chunk(World *world, int x, int y);
void calculate_visibility(Chunk *chunk);
void chunk_tick_handler(Chunk *chunk);



/*
Global
*/

// global pointer to the World
World *world;



#endif



