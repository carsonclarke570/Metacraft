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

void vec3_normalize(vec3 vec, vec3 y) {
    const float n = 1.0f / sqrtf((vec[0] * vec[0]) + (vec[1] * vec[1]) + (vec[2] * vec[2]));
    y[0] = vec[0] * n;
    y[1] = vec[1] * n;
    y[2] = vec[2] * n;
}

void vec2_normalize(vec2 vec, vec2 y) {
    const float n = 1.0f / sqrtf((vec[0] * vec[0]) + (vec[1] * vec[1]));
    y[0] = vec[0] * n;
    y[1] = vec[1] * n;
}