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

#include "item.h"



/*
Tags are a universal abstract data interface. They store attribute information
for items, blocks, and entities. The TagCache is

Ideally, tags will modify base attributes when applied and unapplied, so that
they are not repeatedly read or modified each frame.
*/



// Tag Attributes
#define TA_WATERLOGGED ()  // true, false
#define TA_LIGHTSOURCE ()  // true, false
#define TA_FIREPROOF   ()  // true, false
#define TA_ORIENTATION ()  // north, south, east, west, up, down
#define TA_STICKY      ()  // true, false



// Tag Values
#define TV_TRUE  (1)
#define TV_FALSE (0)

#define TV_NORTH ( 1)
#define TV_SOUTH ( 2)
#define TV_EAST  ( 4)
#define TV_WEST  ( 8)
#define TV_UP    (16)
#define TV_DOWN  (32)



typedef struct {
    uint16_t space;
    uint16_t next;
    uint8_t *data;
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
void create_tag(Item *item);



/*

*/
void free_tag(Item *item);



/*

*/
void insert_tag(Item *item);



/*

*/
void remove_tag(Item *item);



/*

*/
uint8_t *get_tagData(Item *item);



/*

*/
void modify_tag(Item *item, uint8_t property, uint8_t *data);



/*

*/
void read_tag(Item *item, FILE *file);



/*

*/
void write_tag(Item *item, FILE *file);



// Internal TagCache
static TagCache *sTagCache;



// Global
char *gTagAttributeStrings[] = {
    "\0",
    "\0",
    "\0",
    "\0"
};



char *gTagValueStrings[] = {
    "true\0",
    "false\0",
    "\0",
    "\0"
};



#endif


