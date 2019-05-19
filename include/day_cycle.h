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

#ifndef _DAY_CYCLE_H_
#define _DAY_CYCLE_H_

#include <shader.h>
#include <vector.h>

#define DAY_LEN     10.0f
#define NIGHT_LEN   7.0f
#define DUSK_LEN    1.5f
#define DAWN_LEN    1.5f

#define SUNLIGHT_DIFFUSE    {0.9f, 0.9f, 0.9f}
#define MOONLIGHT_DIFFUSE   {0.0f, 0.0f, 0.0f}

#define DAY_END     (DAY_LEN)
#define DUSK_END    (DAY_END + DUSK_LEN)
#define NIGHT_END   (DUSK_END + NIGHT_LEN)
#define DAWN_END    (NIGHT_END + DAWN_LEN)
#define CYCLE_LEN   (DAWN_END)

typedef struct {
    vec3 sun_position;
    vec3 sunlight;
    float lerp;
    float time;
} DayCycle;

/**
 * Updates the day night cycle with the engine's delta value.
 *
 * @param cycle     Pointer to DayCycle struct
 * @param delta     Time since last update.
 */
void day_update(DayCycle* cycle, float delta);

/**
 * Updates relevant day/night shader values.
 *
 * @param cycle     Pointer to DayCycle struct
 * @param shader    Shader to update.
 */
void day_shader_update(DayCycle* cycle, Shader* shader);

#endif
