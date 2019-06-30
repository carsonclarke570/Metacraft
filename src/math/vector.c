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

#include <vector.h>

void vec3_normalize(const vec3 vec, vec3 y) {
    const float n = 1.0f / sqrtf((vec[0] * vec[0]) + (vec[1] * vec[1]) + (vec[2] * vec[2]));
    y[0] = vec[0] * n;
    y[1] = vec[1] * n;
    y[2] = vec[2] * n;
}

void vec2_normalize(const vec2 vec, vec2 y) {
    const float n = 1.0f / sqrtf((vec[0] * vec[0]) + (vec[1] * vec[1]));
    y[0] = vec[0] * n;
    y[1] = vec[1] * n;
}

float vec3_dot(const vec3 a, const vec3 b) {
    return (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
}

float vec2_dot(const vec2 a, const vec2 b) {
    return (a[0] * b[0]) + (a[1] * b[1]);
}

void vec3_cross(const vec3 a, const vec3 b, vec3 y) {
    const float x_ = (a[1] * b[2]) - (a[2] * b[1]);
    const float y_ = (a[2] * b[0]) - (a[0] * b[2]);
    const float z_ = (a[0] * b[1]) - (a[1] * b[0]);
    y[0] = x_;
    y[1] = y_;
    y[2] = z_;
}

void vec3_lerp(const vec3 a, const vec3 b, float c, vec3 y) {
    y[0] = a[0] + (c * (b[0] - a[0]));
    y[1] = a[1] + (c * (b[1] - a[1]));
    y[2] = a[2] + (c * (b[2] - a[2]));
}

void vec3_sub(const vec3 a, const vec3 b, vec3 y) {
    y[0] = a[0] - b[0];
    y[1] = a[1] - b[1];
    y[2] = a[2] - b[2];
}

void vec3_add(const vec3 a, const vec3 b, vec3 y) {
    y[0] = a[0] + b[0];
    y[1] = a[1] + b[1];
    y[2] = a[2] + b[2];
}

void vec3_mulf(const vec3 a, float c, vec3 y) {
    y[0] = a[0] * c;
    y[1] = a[1] * c;
    y[2] = a[2] * c;
}

void vec2_mulf(const vec2 a, float c, vec2 y) {
    y[0] = a[0] * c;
    y[1] = a[1] * c;
}
