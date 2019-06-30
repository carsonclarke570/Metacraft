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

#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>

#include <glad/glad.h>

#include <input.h>
#include <window.h>

typedef struct st_game {
    Window window;
    Input input;
    void (*init)(struct st_game* game);
    void (*update)(struct st_game* game, double delta);
    void (*render)(struct st_game* game, double delta);
    void (*cleanup)();
} Game;

/**
 * Initializes the engine.
 */
int engine_init();

/**
 * Runs the engine on Game structure containing the logic and rendering
 * mechanics. All function pointers must be implemented in the Game struct.
 *
 * @param engine    Engine to use.
 * @param game      Game to run.
 */
int engine_run(Game* game);

#endif
