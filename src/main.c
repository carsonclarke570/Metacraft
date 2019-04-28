#include <Mesh.h>
#include <Window.h>
#include <Shader.h>
#include <Texture.h>
#include <Model.h>

extern TexturePool texture_pool;

int main() {

    // Start Up Code
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: GLFW failed to initialize!\n");
        return CODE_GLFW_INIT_ERR;
    }

    // Code
    texture_pool_allocate(10);

    Window window;
    int32_t err = window_create(&window, 640, 480, "Daybreak Test", false);
    if (err) {
        return err;
    }

    Shader shader;
    if ((err = shader_load_file(&shader, VERTEX, "main.vert"))) {
        return err;
    }
    if ((err = shader_load_file(&shader, FRAGMENT, "main.frag"))) {
        return err;
    }
    shader_compile(&shader);

    Texture texture;
    if ((err = create_texture(&texture, "dirt.png", TEXTURE_DIFFUSE))) {
        return err;
    }
    texture_pool.textures[0] = &texture;

    Model model;
    model_create(&model, "cube.obj");

    shader_bind(&shader);
    register_texture(&shader, &texture, 1);

    while (!window_should_close(&window)) {
        // Clear buffer
        glClearColor(GL_CLEAR_COLOR_R, GL_CLEAR_COLOR_G, GL_CLEAR_COLOR_B, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // render
        bind_texture(&texture, 1);
        model_render(&model, &shader);

        // Swap buffers, poll IO events
        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }

    // Clean up
    destroy_texture(&texture);
    shader_destroy(&shader);
    model_delete(&model);
    window_destroy(&window);

    // Global cleanup
    texture_pool_delete();
    glfwTerminate();

    return CODE_SUCCESS;
}