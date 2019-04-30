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

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <matrix.h>
#include <quaternion.h>

typedef struct {
    vec3 translation;
    vec3 scale;
    quat rotation;
} Transform;


/**
 * Constructs a default transform:
 *  translate = {0, 0, 0};
 *  scale = {1, 1, 1}
 *  rotate = {0, 0, 0, 1}
 *
 * @param transform Pointer to transform struct.
 */
void transform_default(Transform* transform);

/**
 * Creates a transformation matrix
 *
 * @param transform Pointer to transform struct.
 * @param mat       Resulting transformation matrix
 */
void transform_to_matrix(Transform* transform, mat4 mat);


#endif
