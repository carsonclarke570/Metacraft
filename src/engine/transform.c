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
#include <transform.h>

void transform_default(Transform* transform) {
    memset(transform, 0, sizeof(Transform));
    transform->scale[0] = 1.0f;
    transform->scale[1] = 1.0f;
    transform->scale[2] = 1.0f;
    transform->rotation[3] = 1.0f;
}

void transform_to_matrix(Transform* transform, mat4 mat) {
    mat4 s, r, t;
    mat4_scale(s, transform->scale);
    mat4_translate(t, transform->translation);
    quat_rotation(transform->rotation, r);

    mat4_mul(r, s, s);
    mat4_mul(t, s, t);
    memcpy(mat, t, sizeof(float) * 16);
}


