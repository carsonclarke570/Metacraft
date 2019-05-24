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
#include "tag.h"
#include "common.h"



void initialize_tagCache() {
    uint16_t space = 1024;
    
    if (
        !(sTagCache = malloc(sizeof(TagCache))) ||
        !(sTagCache->data8 = malloc(space)) ||
        !(sTagCache->data16 = malloc(space)) ||
        !(sTagCache->data32 = malloc(space)) ||
        !(sTagCache->data64 = malloc(space))
    ) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }

    sTagCache->space = space;
    sTagCache->next8 = 0;
    sTagCache->next16 = 0;
    sTagCache->next32 = 0;
    sTagCache->next64 = 0;
}



void free_tagCache() {
    if (sTagCache->next8)
        LOG_W("Freeing TagCache containing %d byte aligned tags.", tagCache->next8);
    if (sTagCache->next16)
        LOG_W("Freeing TagCache containing %d 2 byte aligned tags.", tagCache->next16);
    if (sTagCache->next32)
        LOG_W("Freeing TagCache containing %d 4 byte aligned tags.", tagCache->next32);
    if (sTagCache->next64)
        LOG_W("Freeing TagCache containing %d 8 byte aligned tags.", tagCache->next64);
    
    free(sTagCache->data8);
    free(sTagCache->data16);
    free(sTagCache->data32);
    free(sTagCache->data64);
    free(sTagCache);
    sTagCache = NULL;
}



void create_tag(uint8_t *tag) {

}



void free_tag(uint8_t *tag) {

}



void insert_tag(uint8_t *tag) {

}



void remove_tag(uint8_t *tag) {

}



void modify_tag(uint8_t *tag, uint8_t property, void *value) {

}



void read_tag(uint8_t *tag, FILE *file) {

}


void write_tag(uint8_t *tag, FILE *file) {

}


