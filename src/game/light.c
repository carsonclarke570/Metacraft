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

#include <light.h>

void light_dirlight(Shader* shader, DirectionalLight* light) {
    shader_uniform_vec3(shader, "sun_light.direction", light->direction);
    shader_uniform_vec3(shader, "sun_light.ambient", light->light.ambient);
    shader_uniform_vec3(shader, "sun_light.diffuse", light->light.diffuse);
    shader_uniform_vec3(shader, "sun_light.specular", light->light.specular);
}

