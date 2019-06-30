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

#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include <vector.h>
#include <matrix.h>

typedef float quat[4];

/**
 * Creates a quaternion from an axis and an angle
 *
 * @param q     Quaternion
 * @param axis  Axis to rotate around.
 * @param angle Angle to rotate by.
 */
void quat_axis_angle(quat q, vec3 axis, float angle);

/**
 * Normalizes a quaternions.
 *
 * @param q     Quaternion to normalize
 * @param y     Result of normalization
 */
void normalize(quat q, quat y);

/**
 * Creates a rotation matrix from a quaternion.
 *
 * @param q     Quaternion
 * @param mat   Resulting matrix.
 */
void quat_rotation(quat q, mat4 mat);

#endif
