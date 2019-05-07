/*
option.h


*/
#ifndef OPTION_H
#define OPTION_H



typedef struct {
  int fov;
  
} GameOptions;



typedef struct {
  int quality;
  int fps;
  int fullscreen;
  int shadows;
  int gui;
  int clouds;
  int particles;
} VideoOptions;



typedef struct {
  int master_volume;
  
  int music;
  int weather;
  int hostile_creatures;
  int players;
  int voice_speech;
  
  int jukeblock_noteblocks;
  int blocks;
  int friendly_creatures;
  int ambient_environment;
  
  struct X show_subtitles;
} SoundOptions;



typedef struct {
  int sensitivity;
  char *keymap[];
} InputOptions;



#endif



