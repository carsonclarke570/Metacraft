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

#ifndef LIST_H
#define LIST_H

#include <common.h>

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define GROWTH_FACTOR 2

typedef struct {
  void* data;
  size_t size;
  size_t capacity;
  size_t data_size;
} Array;

/**
 * Constructs a new dynamic array with an initial capacity to hold elements of
 * size data_size.
 *
 * @param array     Pointer to the array struct.
 * @param capacity  Initial capacity.
 * @param data_size Size of each element in number of bytes..
 */
void array_allocate(Array* array, size_t capacity, size_t data_size);

/**
 * Destroys an existing dynamic array.
 *
 * @param array     Pointer to the Array struct.
 */
void array_delete(Array* array);

/**
 * Gets an element in the dynamic array.
 *
 * @param array     Pointer to the Array struct.
 * @param i         Index to get element at.
 * @return          The element at index i, NULL if index i does not exist.
 */
void* array_get(Array* array, uint64_t i);

/**
 * Sets an element in the dynamic array.
 *
 * @param array     Pointer to the Array struct.
 * @param i         Index to set.
 * @param data      Data to add at the index.
 * @return          An error code if an error occurs.
 */
int array_set(Array* array, uint64_t i, void* data);

/**
 * Adds an element to the end of a dynamic array.
 *
 * @param array     Pointer to Array struct.
 * @param data      Data to add.
 */
void array_add(Array* array, void* data);

/**
 * Clears an array but keeps the current capacity.
 *
 * @param array     Pointer to Array struct.
 */
void array_clear(Array* array);

#endif
