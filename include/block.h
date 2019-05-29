/*
    Copyright 2019 Wesley Dahar

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
#ifndef BLOCK_H
#define BLOCK_H

#include "item.h"



// redefine Item as Block
typedef Item Block;



/*
isTransparent : 1; // is semi-transparent
isSolid : 1;       // has a physical model
isStable : 1;      // will not be destroyed by water or loss of contact
isLightSource : 1; // this block can emit light (see tag for value)
requiresUpdate : 1;

toolType : 4;      // the tool required to break
toolLevel : 4;     // the minimum tool quality required to break
*/
typedef struct {
    uint8_t flags;
    uint8_t toolFlags;
    uint16_t blastResistance; // 
    uint8_t animationFrame;  // animation frame counter for updating mesh texture
    uint8_t stateTagCount;   // number of static tag data bytes preceding dynamic tags
    uint8_t stateTags[8];    // up to 8 static block state tags
    int *mesh;//Mesh *mesh;              // block Mesh
    int *body;//RigidBody *body;         // block physical model
} BlockMeta;



void set_block(Block *block);

void break_block(Block *block);
void place_block(Block *block);

char *generate_blockLore(Block *block);



// Global BlockMetas
const BlockMeta blockMetas[] = {
    {0b1010, 0b00000000, 0, 0, 0, {0}, NULL, NULL},// AIR
    {0},
    {0b0110, 0b00010001, 30, 0, 0, {0}, NULL, NULL} // STONE
};



#endif


