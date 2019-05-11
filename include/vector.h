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
void vec3_normalize(const vec3 vec, vec3 y);
void vec2_normalize(const vec2 vec, vec2 y);

/**
 *  Computes the dot product of two vectors.
 *
 * @param a     First vector.
 * @param b     Second vector.
 * @return      The dot (innner) product.
 */
float vec3_dot(const vec3 a, const vec3 b);
float vec2_dot(const vec2 a, const vec2 b);

/**
 * Computes the cross product of two vectors.
 *
 * @param a     First vector.
 * @param b     Second vector.
 * @param y     Resulting vector.
 */
void vec3_cross(const vec3 a, const vec3 b, vec3 y);

/**
 * Subtracts two vectors. y = a - b.
 *
 * @param a     First vector.
 * @param b     Second vector.
 * @param y     Resulting vector.
 */
void vec3_sub(const vec3 a, const vec3 b, vec3 y);

/**
 * Adds two vectors. y = a + b.
 *
 * @param a     First vector.
 * @param b     Second vector.
 * @param y     Resulting vector.
 */
void vec3_add(const vec3 a, const vec3 b, vec3 y);

/**
 * Scales a vector by a constant. y = c * a
 *
 * @param a     Vector to scale.
 * @param c     Constant scale factor.
 * @param y     Resulting vector.
 */
void vec3_mulf(const vec3 a, float c, vec3 y);
void vec2_mulf(const vec2 a, float c, vec2 y);

#endif
