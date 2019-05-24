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
#ifndef TAG_H
#define TAG_H

#include <stdio.h>
#include <stdint.h>



/*
Tags are a universal abstract data interface. They store attribute information
for items, blocks, and entities. The TagCache is

Ideally, tags will modify base attributes when applied and unapplied, so that
they are not repeatedly read or modified each frame.
*/



// Tag Identifiers             bytes  type  purpose
#define T_WATERLOGGED ()  //  0      bool   block containes water
#define T_LIGHTSOURCE ()  //  0      bool  
#define T_FIREPROOF   ()  //  0      bool  
#define T_ORIENTATION ()  //  1      flags  stores axis alignment data
#define T_   ()  //  0      bool  



// Common Tag Values
#define T_NORTH ( 1)
#define T_SOUTH ( 2)
#define T_EAST  ( 4)
#define T_WEST  ( 8)
#define T_UP    (16)
#define T_DOWN  (32)



typedef struct {
    uint16_t space;
    uint16_t next8;
    uint16_t next16;
    uint16_t next32;
    uint16_t next64;
    uint8_t *data8;
    uint16_t *data16;
    uint32_t *data32;
    uint64_t *data64;
    uint64_t *preset;
} TagCache;



/*

*/
void initialize_tagCache();



/*

*/
void free_tagCache();



/*

*/
void create_tag(uint8_t *tag);



/*

*/
void free_tag(uint8_t *tag);



/*

*/
void insert_tag(uint8_t *tag);



/*

*/
void remove_tag(uint8_t *tag);



/*

*/
void modify_tag(uint8_t *tag, uint8_t property, uint8_t *data);



/*

*/
void read_tag(uint8_t *tag, FILE *file);



/*

*/
void write_tag(uint8_t *tag, FILE *file);



// Internal TagCache
static TagCache *sTagCache;



#endif


