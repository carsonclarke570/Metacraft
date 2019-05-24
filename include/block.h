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

#include "common.h"



typedef struct {
    uint16_t blockID : 12; // BlockMeta ID
    uint16_t tag : 12;     // index of tag data in TagCache
} Block;



typedef struct {
    uint16_t itemID : 12;    // 
    bool isOpaque : 1;       // is semi-transparent
    bool isSolid : 1;        // has a physical model
    bool isStable : 1;       // will not be destroyed by water or loss of contact
    bool is : 1;       // 
    uint8_t toolLevel;       // the minimum tool quality required
    uint8_t blastResistance; // 
    bool hasAnimation;
    bool isLightsource;
    uint8_t stateTagCount;
    uint8_t stateTags[8];     // up to 8 state tags
} BlockMeta;



// Global BlockMetas
const BlockMeta blockMetas[] = {

}



#endif


