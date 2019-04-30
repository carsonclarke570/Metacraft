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

#include <Matrix.h>

void mat4_identity(mat4 mat) {
    memset(mat, 0, 16 * sizeof(float));
    mat[INDEX(0, 0)] = 1.0f;
    mat[INDEX(1, 1)] = 1.0f;
    mat[INDEX(2, 2)] = 1.0f;
    mat[INDEX(3, 3)] = 1.0f;
}

void mat4_projection(mat4 mat, float fov, float near, float far, float aspect) {
    float r = tan(fov * 0.5f * GL_PI * 180.0f);

    memset(mat, 0, 16 * sizeof(float));
    mat[INDEX(0, 0)] = 1.0f / (r * aspect);
    mat[INDEX(1, 1)] = 1.0f / r;
    mat[INDEX(2, 2)] = (-far - near) / (far - near);
    mat[INDEX(3, 2)] = (-2.0f * far * near) / (far - near);
    mat[INDEX(2, 3)] = -1.0f;
}

void mat4_translate(mat4 mat, const vec3 translation) {
    mat4_identity(mat);
    mat[INDEX(3, 0)] = translation[0];
    mat[INDEX(3, 1)] = translation[1];
    mat[INDEX(3, 2)] = translation[2];
}

void mat4_scale(mat4 mat, const vec3 scale) {
    memset(mat, 0, 16 * sizeof(float));
    mat[INDEX(0, 0)] = scale[0];
    mat[INDEX(1, 1)] = scale[1];
    mat[INDEX(2, 2)] = scale[2];
    mat[INDEX(3, 3)] = 1.0f;
}

void mat4_transform(mat4 mat, const vec3 scale, const vec3 translate) {
    mat4 s;
    mat4 t;
    mat4_translate(t, translate);
    mat4_scale(s, scale);

    mat4_mul(t, s, t);
    memcpy(mat, t, sizeof(float) * 16);
}

void mat4_mul(mat4 a, mat4 b, mat4 y) {
    mat4 temp;
    float sum;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            sum = 0.0f;
            for (int i = 0; i < 4; i++) {
                sum = sum + (a[INDEX(i, r)] * b[INDEX(c, i)]);
            }
            temp[INDEX(c, r)] = sum;
        }
    }
    memcpy(y, temp, sizeof(float) * 16);
}

void mat4_print(mat4 mat) {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            printf("%f ", mat[INDEX(r, c)]);
        }
        printf("\n");
    }
}