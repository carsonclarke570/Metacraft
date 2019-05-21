/*
path.h



*/
#ifndef PATH_H
#define PATH_H

#include "common.h"
#include "entity.h"


#define DIST_BLOCK (4.0) // default arrival distance for blocks is 4.0m
#define DIST_MOB (1.0) // default arrival distance for mobs is 1.0m
#define DIST_COLLECTIVE (16.0) // default arrival distance for collectives is 16.0m


typedef struct {
    bool hasGravity;    // the Path is influenced by gravity
    bool isTraversable; // destination can be reached
    Entity *traveler;   // Entity following the Path
    Entity *target;     // Entity being followed
    double destination[3];   // coordinates being moved to (target and destination are  mutually exclusive)
    uint16_t stopCount; // number of stops defining the Path
    double *stops[3];        // array of coordinates defining the Path
} Path;



/*
Function Prototypes
*/
void allocate_path(Path *path);
void free_path(Path *path);

void read_path(Path *path, FILE *file);
void write_path(Path *path, FILE *file);

bool verify_path(Path *path, bool recalculate);

Path *path_to_block(Entity *traveler, double *destination, double *distance, bool aoa, bool los);
Path *path_to_entity(Entity *traveler, Entity *target, double *distance, bool aoa, bool los);



#endif


