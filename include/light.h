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

#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <shader.h>

typedef struct {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
} Light;

typedef struct {
    float constant;
    float linear;
    float quadratic;
} Attenuation;

typedef struct {
    vec3 direction;
    Light light;
} DirectionalLight;

/**
 * Updates a shader's DirectionalLight uniform.
 *
 * @param shader    Pointer to shader struct
 * @param name      Name of the uniform to update.
 * @param light     Directional Light data to update with
 */
void light_dirlight(Shader* shader, DirectionalLight* light);


#endif
