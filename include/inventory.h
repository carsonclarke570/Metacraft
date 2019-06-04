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
#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"



typedef struct {
    uint8_t count;
    Item item;
} ItemSlot;



typedef struct {
    uint16_t id;
    uint8_t slotCount;
    ItemSlot *itemSlots;
} Inventory;



typedef struct {
    uint16_t capacity;
    uint16_t count;
    Inventory **inventories;
} InventoryCache;



/*


Parameters:
Returns:
    InventoryCache * - 
Errors:
    CODE_MALLOC_ERROR
*/
InventoryCache *create_inventoryCache();



/*


Parameters:
    InventoryCache *cache - 
Returns:
Errors:
*/
void free_inventoryCache(InventoryCache *cache);



/*


Parameters:
    uint16_t id - 
Returns:
    Inventory * - 
Errors:
    CODE_MALLOC_ERROR
*/
Inventory *create_inventory(uint16_t id);



/*


Parameters:
    Inventory *inventory - 
Returns:
Errors:
*/
void free_inventory(Inventory *inventory);



/*


Parameters:
    FILE *file - 
Returns:
    Inventory * - 
Errors:
*/
Inventory *read_inventory(FILE *file);



/*


Parameters:
    Inventory *inventory - 
    FILE *file - 
Returns:
Errors:
*/
void write_inventory(Inventory *inventory, FILE *file);



#endif


