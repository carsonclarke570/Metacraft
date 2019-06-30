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
#ifndef WORLD_H
#define WORLD_H

#include "chunk.h"
#include "mob.h"



typedef struct {
    uint16_t maximum;     // maximum allocated cache size
    uint16_t capacity;    // allcated cache size
    uint16_t cached;      // number of Chunks cached
    uint16_t loaded;      // number of Chunks loaded
    double *loadVelocity; // vector representation of load direction
    Chunk **chunks;         // array of Chunk pointers
} ChunkCache;



typedef struct {
    uint16_t capacity; // maximum list size
    uint16_t cached;   // number of Players listed
    Mob *players;      // Player data
} PlayerCache;



typedef struct {
    uint8_t major;
    uint8_t minor;
    bool stable;
    bool release;
    char *date;
} Version;



typedef struct {
    uint8_t difficulty;      // 
    bool difficultyLocked;   // 
    bool allowCommands;      // 


    bool announceAdvancements;       // Whether advancements should be announced in chat
    bool commandBlocksEnabled;       // Whether command blocks should be enabled in-game
    bool commandBlockOutput;         // Whether command blocks should notify admins when they perform commands
    bool disableElytraMovementCheck; // Whether the server should skip checking player speed when the player is wearing elytra. Often helps with jittering due to lag in multiplayer, but may also be used to travel unfairly long distances in survival mode (cheating).
    bool doDaylightCycle;            // Whether the day-night cycle and moon phases progress
    bool doEntityDrops;              // Whether entities that are not mobs should have drops
    bool doFireTick;                 // Whether fire should spread and naturally extinguish
    bool doInsomnia;                 // Whether phantoms will spawn in the nighttime
    bool doLimitedCrafting;          // Whether players should only be able to craft recipes that they've unlocked first
    bool doMobLoot;                  // Whether mobs should drop items
    bool doMobSpawning;              // Whether mobs should naturally spawn. Does not affect monster spawners.
    bool doTileDrops;                // Whether blocks should have drops
    bool doWeatherCycle;             // Whether the weather will change
    bool drowningdamage;             // Whether the player should take damage when drowning
    bool falldamage;                 // Whether the player should take fall damage
    bool firedamage;                 // Whether the player should take fire damage
    bool keepInventory;              // Whether the player should keep items in their inventory after death
    bool logAdminCommands;           // Whether to log admin commands to server log
    uint8_t maxCommandChainLength;   // Determines the number at which the chain command block acts as a "chain".
    uint8_t maxEntityCramming;       // The maximum number of other pushable entities a mob or player can push, before taking 3 (Heart.svgHalf Heart.svg) suffocation damage per half-second. Setting to 0 disables the rule. Damage affects survival-mode or adventure-mode players, and all mobs but bats. Pushable entities include non-spectator-mode players, any mob except bats, as well as boats and minecarts.
    bool mobGriefing;                // Whether creepers, zombies, endermen, ghasts, withers, ender dragons, rabbits, sheep, villagers, and snow golems should be able to change blocks and whether mobs can pick up items
    bool naturalRegeneration;        // Whether the player can regenerate health naturally if their hunger is full enough (doesn't affect external healing, such as golden apples, the Regeneration effect, etc.)
    bool pvp;                        // Whether the player can fight with other players
    uint8_t randomTickSpeed;         // How often a random block tick occurs (such as plant growth, leaf decay, etc.) per chunk section per game tick. 0 will disable random ticks, higher numbers will increase random ticks. Setting to a high integer results in high speeds of decay and growth
    uint8_t reducedDebugInfo;        // Whether the debug screen shows all or reduced information; and whether the effects of F3+B (entity hitboxes) and F3+G (chunk boundaries) are shown.
    bool sendCommandFeedback;        // Whether the feedback from commands executed by a player should show up in chat. Also affects the default behavior of whether command blocks store their output text
    bool showDeathMessages;          // Whether death messages are put into chat when a player dies. Also affects whether a message is sent to the pet's owner when the pet dies.
    uint8_t spawnRadius;             // The number of blocks outward from the world spawn coordinates that a player will spawn in when first joining a server or when dying without a personal spawnpoint.
    bool spectatorsGenerateChunks;   // Whether players in spectator mode can generate chunks
} Gamerule;



typedef struct {
    Version version;         // 
    uint64_t lastPlayed;     // 
    uint64_t sizeOnDisk;     // 
    char *name;              // 
    
    
    uint64_t ticks;          // total number of elapsed game ticks
    
    uint64_t seed;           // used for terrain and structure generation
    uint16_t sealevel;       // sealevel
    uint16_t buildheight;    // world build height
    
    // vapor map
    // temperature map
    // height map
    // feature map
    // ecosystem map
    // event map
    // erosion map
    Gamerule gamerule;       // 
    ChunkCache chunkCache;   // 
    PlayerCache playerCache; // 
    Metadata metadata;       // 
} World;



/*
Initialized the World with default settings.

Parameters:
Returns:
Errors:
*/
void initialize_world();



/*
Frees the Chunk, Weather, and Player data used by the World.
No data is saved.

Parameters:
Returns:
Errors:
*/
void free_world();



/*


Parameters:
Returns:
Errors:
*/
void read_world(FILE *file);



/*


Parameters:
Returns:
Errors:
*/
void write_world(FILE *file);



/*


Parameters:
Returns:
Errors:
*/
void load_chunk(int64_t x, int64_t z);



/*


Parameters:
Returns:
Errors:
*/
Chunk *get_chunk(int64_t x, int64_t z);



/*


Parameters:
Returns:
Errors:
*/
Chunk *generate_chunk(int64_t x, int64_t z);



void set_block(int64_t x, int64_t y, int64_t z, uint16_t id);
void fill_blocks(int64_t x0, int64_t y0, int64_t z0, int64_t x1, int64_t y1,
        int64_t z1, uint16_t id);
void place_block(int64_t x, int64_t y, int64_t z, Block *block);
void break_block(int64_t x, int64_t y, int64_t z);



// Internal World
static World sWorld;



static Gamerule sGamerule = {
    2,
    false,
    false,

    true,
    true,
    true,
    false,
    true,
    true,
    true,
    true,
    false,
    true,
    true,
    true,
    true,
    true,
    true,
    true,
    false,
    true,
    65535,
    24,
    true,
    true,
    3,
    false,
    true,
    true,
    true,
    10,
    true
};



#endif


