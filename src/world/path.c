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



/*
Finds a path from one Entity to another.

Parameters:
    Entity *traveler - The Entity that will be traversing the Path.
    vec3 *destination - The Block to approach.
    vec3 *distance - The maximum arrival distance from 'target'.
    bool aoa - True if 'distance' defines a required angle of approach for the Path.
    bool los - True if the Path must have a clear line of sight to 'target'.
Returns:
    Path * - A valid Path.
    NULL - No Path exists.
Errors:
*/
Path *path_to_block(Entity *traveler, double *destination, double *distance, bool aoa, bool los) {
    return NULL;
}



/*
Finds a path from one Entity to another.

Parameters:
    Entity *traveler - The Entity that will be traversing the Path.
    Entity *target - The Entity to approach.
    vec3 *distance - The maximum arrival distance from 'target'.
    bool aoa - True if 'distance' defines a required angle of approach for the Path.
    bool los - True if the Path must have a clear line of sight to 'target'.
Returns:
    Path * - A valid Path.
    NULL - No Path exists.
Errors:
*/
Path *path_to_entity(Entity *traveler, Entity *target, double *distance, bool aoa, bool los) {
    return NULL;
}



/*
Determines if a Path is still traversable, and will attempt to find a new
route if necessary. The traversibility of the Path is returned.

Parameters:
    Path *path - The Path to verify and potentially modify.
    bool recalcualte - The Path should be recalculated if it is not found to
                       be traversible.
Returns:
    bool - The traversability of the Path.
Errors:
*/
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



void allocate_path(Path *path, uint16_t stopCount) {
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



