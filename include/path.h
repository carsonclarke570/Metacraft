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
#ifndef PATH_H
#define PATH_H

#include "common.h"
#include "entity.h"


#define DIST_BLOCK (4.0)       // default arrival distance for blocks is 4.0m
#define DIST_MOB (1.0)         // default arrival distance for mobs is 1.0m
#define DIST_COLLECTIVE (16.0) // default arrival distance for collectives is 16.0m


typedef struct {
    bool hasGravity;       // the Path is influenced by gravity
    bool isTraversable;    // destination can be reached
    Entity *traveler;      // Entity following the Path
    Entity *target;        // Entity being followed
    double destination[3]; // coordinates being moved to (target and destination are  mutually exclusive)
    uint16_t stopCount;    // number of stops defining the Path
    double *stops;         // array of coordinates defining the Path (iterate by 3's!)
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


