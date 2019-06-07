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
    return NULL;
}



Path *path_to_entity(Entity *traveler, Entity *target, double *distance, bool aoa, bool los) {
    return NULL;
}



bool verify_path(Path *path, bool recalculate) {
    int valid;
    int si;
    
    for (si = 0; si < path->stopCount; si++) {
        valid = 1;
        
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
}



void free_path(Path *path) {
    free(path->stops);
    free(path);
    path = NULL;
}



void read_path(Path *path, FILE *file) {
    // 
}



void write_path(Path *path, FILE *file) {
    // 
}


