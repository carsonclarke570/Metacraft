#include <mesh.h>
#include <window.h>
#include <shader.h>
#include <texture.h>
#include <matrix.h>
#include <transform.h>
#include <world.h>

#include <testing.h>

extern TexturePool texture_pool;

World world;

void init(Game* game) {
    world_init(&world, game);
}

void update(Game* game, double delta) {
    world_update(&world, game, delta);
}

void render(Game* game, double delta) {
    world_render(&world, game, delta);
}

void cleanup() {
    world_delete(&world);
}

int main() {

    UNIT_TEST();

    // Start Up Code
    Game game;
    game.init = init;
    game.render = render;
    game.cleanup = cleanup;
    game.update = update;

    int err;
    if (err = engine_init(&game)) return err;

    engine_run(&game);

    return CODE_SUCCESS;
}