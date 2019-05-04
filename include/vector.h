/*
    Copyright 2019 Carson Clarke-Magrab

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

#ifndef _MATH_H_
#define _MATH_H_

#include <math.h>

typedef float vec2[2];
typedef float vec3[3];
typedef int ivec2[2];
typedef int ivec3[3];

/**
 * Normalizes a vector.
 *
 * @param vec   Vector to normalize.
 * @param y     Normalized vector.
 */
void vec3_normalize(vec3 vec, vec3 y);
void vec2_normalize(vec2 vec, vec2 y);

#endif