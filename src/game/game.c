/*
game.c



*/
#include "game.h"




void game_load(World *world, Gamemode *gamemode) {
  
  // load game env
  
  // game menu loop
  while (running) {
    
    // re-enter the game loop on resume
    game_loop();
    
    // handle menu
    
    if (1) {
      running = 0;
    }
  }
  
  // save and exit
  save_world(world);
}






void game_loop() {
  
  
  while (1) {
    // get input
    // send input to gui
    // send input to player
    // update physics
    // tick redstone
    // tick world
    // draw world to buffer
    // draw gui to buffer
    // swap buffer
    
    game_tick_handler(game);
  }
  
}


