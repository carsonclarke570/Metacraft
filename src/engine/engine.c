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

#include <engine.h>

int engine_init(Game* game) {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: GLFW failed to initialize!\n");
        return CODE_GLFW_INIT_ERR;
    }
    fprintf(stdout, "ENGINE: Initialized GLFW!\n");

    int32_t err = window_create(&game->window, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, WIN_FULL);
    if (err) {
        return err;
    }
    fprintf(stdout, "ENGINE: Created window context!\n");

    const GLubyte* vendor = glGetString(GL_VENDOR);
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* language = glGetString(GL_SHADING_LANGUAGE_VERSION);
    const GLubyte* ext = glGetString(GL_EXTENSIONS);

    fprintf(stdout, "ENGINE: OpenGL Details\n\tVendor: %s\n\tRenderer: %s\n\tVersion: %s\n\tGLSL: %s\n\tExts: %s\n",
            vendor, renderer, version, language, ext);

    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    return CODE_SUCCESS;
}

int engine_run(Game* game) {

    game->init();

    while (!window_should_close(&game->window)) {
        // Clear buffer
        glClearColor(GL_CLEAR_COLOR_R, GL_CLEAR_COLOR_G, GL_CLEAR_COLOR_B, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        game->update();
        game->render();

        // Swap buffers, poll IO events
        glfwSwapBuffers(game->window.window);
        glfwPollEvents();
    }
    game->cleanup();

    window_destroy(&game->window);
    glfwTerminate();
}