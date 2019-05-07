/*
game.h


*/
#ifndef GAME_H
#define GAME_H

#include "world.h"






typedef struct {
  GameOptions gameOpt;
  VideoOptions videoOpt;
  SoundOptions soundOpt;
  InputOptions inputOpt;
  World *world;
} Game;




/*
Function Prototypes
*/
void game_load(World *world);
void game_loop();



#endif



