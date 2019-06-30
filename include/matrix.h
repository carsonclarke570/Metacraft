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

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <string.h>
#include <math.h>

#include <common.h>
#include <vector.h>

#define INDEX(R, C) (((R) * 4) + (C))

typedef float mat4[16];

/**
 * Creates an identity matrix.
 *
 * @param mat   4 x 4 matrix.
 */
void mat4_identity(mat4 mat);

/**
 * Creates a perspective projection matrix.
 *
 * @param mat       4 x 4 matrix.
 * @param fov     View angle in degrees.
 * @param near      Near plane cutoff value.
 * @param far       Far plane cutoff value.
 * @param aspect    Aspect ratio (WIDTH / HEIGHT).
 */
void mat4_perspective(mat4 mat, float fov, float near, float far, float aspect);

/**
 * Creates a orthographic projection matrix.
 *
 * @param mat       4 x 4 matrix
 * @param left      Left side of viewing volume
 * @param right     Right side of viewing volume
 * @param bottom    Bottom side of viewing volume
 * @param top       Top side of viewing volume
 * @param near      Near plane cutoff value.
 * @param far       Far plane cutoff value.
 */
void mat4_orthographic(mat4 mat, float left, float right, float bottom, float top, float near, float far);

/**
 * Creates a translation matrix.
 *
 * @param mat           4 x 4 matrix.
 * @param translation   A vector holding the x, y and z translate values.
 */
void mat4_translate(mat4 mat, const vec3 translation);

/**
 * Creates a matrix that induces a rotation such that some camera eye faces an
 * object.
 *
 * @param mat       Resulting matrix.
 * @param eye       Camera eye position.
 * @param object    Object or location to look at.
 * @param up        Up vector.
 */
void mat4_look_at(mat4 mat, const vec3 eye, const vec3 object, const vec3 up);

/**
 * Creates a scale matrix.
 *
 * @param mat   4 x 4 matrix
 * @param translation   A vector holding the x, y and z scale values.
 */
void mat4_scale(mat4 mat, const vec3 scale);

/**
 * Multiples two matrices together in the form Y = AB.
 *
 * @param a     The A matrix.
 * @param b     The B matrix.
 * @param y     Result of the operation.
 */
void mat4_mul(const mat4 a, const mat4 b, mat4 y);

/**
 * Prints a matrix to stdout.
 *
 * @param mat   4 x 4 matrix.
 */
void mat4_print(mat4 mat);

#endif
