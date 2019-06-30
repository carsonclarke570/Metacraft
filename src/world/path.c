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
#include "path.h"



Path *path_to_block(Entity *traveler, double *destination, double *distance, bool aoa, bool los) {
    Path *path;

    if (!(path = malloc(sizeof(Path)))) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }

    path->destination[0] = destination[0];
    path->destination[1] = destination[1];
    path->destination[2] = destination[2];
    path->hasGravity = false;
    
    return path;
}



Path *path_to_entity(Entity *traveler, Entity *target, double *distance, bool aoa, bool los) {
    Path *path;
    
    if (!(path = malloc(sizeof(Path)))) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
    
    path->destination[0] = target->position[0];
    path->destination[1] = target->position[1];
    path->destination[2] = target->position[2];
    path->hasGravity = false;
    
    aoa = los = false;
    distance = NULL;
    
    return path;
}



bool verify_path(Path *path, bool recalculate) {
    int valid = 1;
    
    for (int si = 0; si < path->stopCount; si++) {
        if (!valid) {
            if (recalculate) {
                path->stopCount = --si;
                path->stops = realloc(path->stops, 3 * sizeof(double) * si);
                return path->isTraversable = false;
            } else {
                return path->isTraversable = false;
            }
        }
    }
    
    return path->isTraversable = true;
}



Path *allocate_path() {
    Path *path;
    uint16_t stopCount = 32;
    
    if (
        !(path = malloc(sizeof(Path))) ||
        !(path->stops = malloc(3 * sizeof(double) * stopCount))
    ) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
    
    path->stopCount = stopCount;

    return path;
}



void free_path(Path *path) {
    free(path->stops);
    free(path);
    path = NULL;
}



void read_path(Path *path, FILE *file) {
    fread(path, sizeof(Path), 1, file);
}



void write_path(Path *path, FILE *file) {
    fwrite(path, sizeof(Path), 1, file);
}


