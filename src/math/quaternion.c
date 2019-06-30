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

#include <quaternion.h>


void quat_axis_angle(quat q, vec3 axis, float angle) {
    float asin = sinf(angle * 0.5f * GL_PI / 180.0f);

    vec3 naxis;
    vec3_normalize(axis, naxis);

    q[0] = naxis[0] * asin;
    q[1] = naxis[1] * asin;
    q[2] = naxis[2] * asin;
    q[3] = cosf(angle * 0.5f * GL_PI / 180.0f);
}

void normalize(quat q, quat y) {
    const float n = 1.0f / sqrtf((q[0] * q[0]) + (q[1] * q[1]) + (q[2] * q[2]) + (q[3] * q[3]));
    y[0] = q[0] * n;
    y[1] = q[1] * n;
    y[2] = q[2] * n;
    y[3] = q[3] * n;
}

void quat_rotation(quat q, mat4 mat) {
    quat y;
    normalize(q, y);

    float xx2 = 2.0f * y[0] * y[0];
    float yy2 = 2.0f * y[1] * y[1];
    float zz2 = 2.0f * y[2] * y[2];
    float xy2 = 2.0f * y[0] * y[1];
    float zw2 = 2.0f * y[2] * y[3];
    float xz2 = 2.0f * y[0] * y[2];
    float yw2 = 2.0f * y[1] * y[3];
    float yz2 = 2.0f * y[1] * y[2];
    float xw2 = 2.0f * y[0] * y[3];

    mat[INDEX(0, 0)] = 1.0f - yy2 - zz2;
    mat[INDEX(0, 1)] = xy2 + zw2;
    mat[INDEX(0, 2)] = xz2 - yw2;
    mat[INDEX(0, 3)] = 0.0f;

    mat[INDEX(1, 0)] = xy2 - zw2;
    mat[INDEX(1, 1)] = 1.0f - xx2 - zz2;
    mat[INDEX(1, 2)] = yz2 + xw2;
    mat[INDEX(1, 3)] = 0.0f;

    mat[INDEX(2, 0)] = xz2 + yw2;
    mat[INDEX(2, 1)] = yz2 - xw2;
    mat[INDEX(2, 2)] = 1 - xx2 - yy2;
    mat[INDEX(2, 3)] = 0.0f;

    mat[INDEX(3, 0)] = 0.0f;
    mat[INDEX(3, 1)] = 0.0f;
    mat[INDEX(3, 2)] = 0.0f;
    mat[INDEX(3, 3)] = 1.0f;
}