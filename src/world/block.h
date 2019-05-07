/*
block.h

A physical representation of an item.

*/
#ifndef BLOCK_H
#define BLOCK_H

#include "item.h"



typedef struct {
    uint16_t item_id;
    int blastResistance;
    int isOpaque;
    int isSolid;
    void (*place_handler)();
    void (*break_handler)(Item *);
    void (*action_handler)(Item *);
    void (*tick_handler)();
} BlockProperty;



typedef struct {
    uint16_t block_id; // BlockProperty ID
    Tag *tag;          // meta data
} Block;



// Global

BlockProperty blockMeta[] = {
  item_id
}



#endif



