/*
    Copyright 2019 Carson Clarke-Magrab

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

#include "list.h"

void array_allocate(Array* array, size_t capacity, size_t data_size) {
    array->size = 0;
    array->capacity = capacity;
    array->data_size = data_size;
    array->data = malloc(capacity * data_size);
}

void array_delete(Array* array) {
    free(array->data);
    array->data = NULL;
}

void* array_get(Array* array, uint64_t i) {
    if (i >= array->size) return NULL;

    return (uint8_t*) array->data + (i * array->data_size);
}

int array_set(Array* array, uint64_t i, void* data) {
    if (i >= array->size) return CODE_INDEX_OUT_OF_BOUNDS;

    memcpy(((uint8_t*) array->data) + (i * array->data_size), data, array->data_size);
    return 0;
}

void array_add(Array* array, void* data) {
    if (array->size == array->capacity) {
        if (!array->capacity) array->capacity = 1;
        array->capacity = array->capacity * GROWTH_FACTOR;
        array->data = realloc(array->data, array->capacity * array->data_size);
    }

    memcpy((uint8_t*) array->data + (array->size * array->data_size), data, array->data_size);
    array->size++;
}

void array_clear(Array* array) {
    array->size = 0;
}