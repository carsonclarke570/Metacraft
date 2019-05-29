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
#include "block.h"
#include "tag.h"



void set_block(Chunk *chunk, uint16_t id, uint64_t y, uint64_t x, uint64_t z) {

}



void break_block(Block *block) {

}



void place_block(Block *block) {

}



char *generate_blockLore(Block *block) {
    static char buffer[128];
    uint16_t id = block->id | ((block->nibble & 0x0F) << 8);
    uint16_t tag = block->tag | ((block->nibble & 0xF0) << 4);
    uint8_t *data = get_tagData(block);
    int i = 0;
    
    for (i = 0; i < blockMetas[id].stateTagCount; i++) {
        i += strcpy(&gTagAttributeStrings[blockMetas[id].stateTags[id]], &buffer[i]);
        i += strcpy(&gTagValueStrings[blockMetas[id].stateTags[id]], &buffer[i]);
        buffer[i] = '\n';
    }
    
    if (tag) {
        while (data[i]) {
            i += strcpy(&gTagAttributeStrings[blockMetas[id].stateTags[id]], &buffer[i]);
            i += strcpy(&gTagValueStrings[blockMetas[id].stateTags[id]], &buffer[i]);
            buffer[i] = '\n';
            i++;
        }
    }
    
    buffer[i] = '\0';
    return buffer;
}


