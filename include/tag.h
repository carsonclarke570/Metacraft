/*
tag.c



*/
#ifndef TAG_H
#define TAG_H

#include <stdio.h>
#include <stdint.h>


#define T_CARDINAL_FLAGS (0)
#define T_NORTH (0)
#define T_SOUTH (0)
#define T_EAST (0)
#define T_WEST (0)
#define T_WATERLOGGED (0)



void read_tag(uint8_t *tag, FILE *file);
void write_tag(uint8_t *tag, FILE *file);



#endif


