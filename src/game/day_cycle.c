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

#include <day_cycle.h>

const vec3 DAYLIGHT = SUNLIGHT_DIFFUSE;
const vec3 MOONLIGHT = MOONLIGHT_DIFFUSE;

void day_update(DayCycle* cycle, float delta) {
    cycle->time = cycle->time + delta;
    if (cycle->time > CYCLE_LEN) {
        cycle->time -= CYCLE_LEN;
    }

    float t_adjust = cycle->time * (3.14159265f / LIGHT_CYCLE);
    float sin_t = sinf(t_adjust);
    float cos_t = cosf(t_adjust);

    cycle->sun_position[0] = cos_t;
    cycle->sun_position[1] = sin_t;
    cycle->sun_position[2] = 0.0f;

    float alpha;
    vec3 light;
    float t = cycle->time;

    if (t < DAWN_END) {
        alpha = t / DAWN_LEN;
        cycle->lerp = 1.0f - alpha;
        vec3_lerp(MOONLIGHT, DAYLIGHT, alpha, light);
        cycle->sunlight[0] = light[0];
        cycle->sunlight[1] = light[1];
        cycle->sunlight[2] = light[2];
    } else if (t < DAY_END) {
        cycle->lerp = 0.0f;
        cycle->sunlight[0] = DAYLIGHT[0];
        cycle->sunlight[1] = DAYLIGHT[1];
        cycle->sunlight[2] = DAYLIGHT[2];
    } else if (t < DUSK_END) {
        alpha = (t - DAY_END) / DUSK_LEN;
        cycle->lerp = alpha;
        vec3_lerp(DAYLIGHT, MOONLIGHT, alpha, light);
        cycle->sunlight[0] = light[0];
        cycle->sunlight[1] = light[1];
        cycle->sunlight[2] = light[2];
    } else {
        cycle->lerp = 1.0f;
        cycle->sunlight[0] = MOONLIGHT[0];
        cycle->sunlight[1] = MOONLIGHT[1];
        cycle->sunlight[2] = MOONLIGHT[2];
    }
}

void day_shader_update(DayCycle* cycle, Shader* shader) {
    shader_uniform_vec3(shader, "direction", cycle->sun_position);
    shader_uniform_vec3(shader, "diffuse", cycle->sunlight);
}