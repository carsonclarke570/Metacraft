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
#include "inventory.h"



InventoryCache *create_inventoryCache() {
    InventoryCache *cache;
    uint16_t capacity = 1024;
    
    if (
        !(cache = malloc(sizeof(InventoryCache))) ||
        !(cache->inventories = malloc(sizeof(Inventory *) * capacity))
    ) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
    
    cache->capacity = capacity;
    cache->count = 0;
    return cache;
}



void free_inventoryCache(InventoryCache *cache) {
    // free each inventory with warnings
    free(cache);
}



Inventory *create_inventory(uint16_t id) {
    Inventory *inventory;
    uint16_t slotCount = 32;
    
    if (
        !(inventory = malloc(sizeof(InventoryCache))) ||
        !(inventory->itemSlots = malloc(sizeof(ItemSlot *) * slotCount))
    ) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
    
    inventory->slotCount = slotCount;
    return inventory;
}



void free_inventory(Inventory *inventory) {
    // free each item with warnings
    free(inventory);
}



Inventory *read_inventory(FILE *file) {
    uint16_t id;
    
    // read inventory id
    fread(&id, 2, 1, file);
    Inventory *inventory = create_inventory(id);
    
    // read slot data
    for (id = 0; id < inventory->slotCount; id++)
        fread(&inventory->itemSlots[id], sizeof(ItemSlot), 1, file);
    
    return inventory;
}



void write_inventory(Inventory *inventory, FILE *file) {
    
    // write inventory id
    fwrite(&inventory->id, 2, 1, file);
    
    // write slot data
}


