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
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "common.h"
#include "gui.h"



// internal global
static GUIScreen *current;



void mouse_event_handler(GUIScreen *screen) {/*, GUIElement *event) {
    GUIElement *element;
    GUIMouse *mouse;
    
    if (mouse = screen->mouse->model)
        for (element = screen->elements; element; element++) {
            if (
                !event->handled && element->active && element->mouse_handler &&
                event->x >= element->x &&
                event->y >= element->y &&
                event->x < element->x + element->width &&
                event->y < element->y + element->height
            ) {
                element->mouse_handler(event);
            }
        }
    }
    
    free(event);
*/}



void key_event_handler(GUIScreen *screen) {/*, GUIElement *event) {
    // map keys, hotkeys, etc.
    
    switch (event->key) {
       case 0:
           break;
       default:
           break;
    }
*/}



GUIResourceManager *create_guiResourceManager() {
    GUIResourceManager *manager;
    
    if (
        !(manager = malloc(sizeof(GUIResourceManager))) ||
        !(manager->data = malloc(sizeof(GUIResourceEntry) * GUI_GRM_INITIAL_CAPACITY))
    ) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
    
    manager->capacity = GUI_GRM_INITIAL_CAPACITY;
    manager->count = 0;
    return manager;
}



void free_guiResourceManager(GUIResourceManager *manager) {
    for (int i = 0; i < manager->count; i++)
        free_guiResource(manager->data[i]);
    
    free(manager);
    manager = NULL;
}



GUIResource *load_guiResource(GUIResourceManager *manager, char *uri,
        uint8_t format) {
    int i;
    
    // check for matching URI
    for (i = 0; i < manager->count; i++)
        if (manager->entries[i]->uri == uri)
            manager->entries[i]->references++;
            return manager->entries[i]->resource;
    
    // Resize if full
    if (manager->count == manager->capacity) {
        manager->capacity *= GUI_GRM_RESIZE_FACTOR;
        
        if (!(manager->data = realloc(manager->data, sizeof(GUIResourceEntry) *
                manager->capacity))) {
            LOG_E(LOG_MSG_MALLOC_ERROR);
            exit(CODE_MALLOC_ERROR);
        }
    }
    
    int width, height;
    uint8_t *data;
    uint16_t *glyphOffsets = NULL;
    
    if (data = stbi_load(uri, &width, &height, &i, 4)) {
        GUIResource *resource;
        
        // load additional font data if required
        if (format & GUI_FONT) {
            FILE *file;
            
            if (!(file = fopen(uri))) {
                free(resource);
                LOG_W("Failed to load \'%s\'.\n", uri);
                return NULL;
            }
            
            if (!(glyphOffsets = malloc(sizeof(uint16_t) * 96))) {
                LOG_E(LOG_MSG_MALLOC_ERROR);
                exit(CODE_MALLOC_ERROR);
            }
            
            fread(glyphOffsets, sizeof(uint16_t), 96, file);
            glyphOffsets -= 32;
        }
        
        // create and add GUIResourceEntry to GUIResourceManager
        if (
            !(resource = malloc(sizeof(GUIResource))) ||
            !(manager->data[manager->count]->uri = malloc(sizeof(char) * strlen(uri)))
        ) {
            LOG_E(LOG_MSG_MALLOC_ERROR);
            exit(CODE_MALLOC_ERROR);
        }
        
        resource->entry = manager->data[manager->count];
        resource->entry->resource = resource;
        resource->entry->references = 1;
        manager->count++;
        
        resource->format = format;
        resource->width = width;
        resource->height = height;
        resource->data = data;
        resource->glyphOffsets = glyphOffsets;
        resource->managed = false;
        return resource;
    } else {
        LOG_W("Failed to load \'%s\'.\n", uri);
        LOG_W(stbi_failure_reason());
        return NULL;
    }
}



GUIResource *add_guiResource(GUIResourceManager *manager, uint8_t *data,
        int16_t width, int16_t height, uint8_t format) {
    int i;
    
    for (i = 0; i < manager->count; i++)
        if (manager->entries[i]->uri == uri)
            return manager->entries[i]->resource;
    
    return NULL;
}



void free_guiResource(GUIResourceManager *manager, GUIResource *resource) {
    if (resource->managed)
        return;

    if (--resource->entry->references) {
        memcpy(
            manager->entries[manager->count],
            resource->entry,
            sizeof(GUIResourceEntry)
        );
        manager->count--;
    }
}



void draw_image(GUIResource *image, int16_t x, int16_t y, int16_t width,
        int16_t height) {
    // 
}



void draw_text(char *text, GUIResource *font, int16_t x, int16_t y,
        int16_t width, int16_t height) {
    // 
}



GUIScreen *create_guiScreen(void *onShow, void *onHide, GUIElement *elements) {
    GUIScreen *screen;
    
    if (!(screen = malloc(sizeof(GUIScreen)))) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
    
    screen->onShow = onShow;
    screen->onHide = onHide;
    screen->focused = NULL;
    screen->elements = elements;
    screen->managed = false;
    
    return screen;
}



void free_guiScreen(GUIScreen *screen) {
    if (screen->managed)
        return;
    
    for (GUIElement *element = screen->elements; element; element++)
        free_guiElement(element);
    
    free(screen);
    screen = NULL;
}



void show_guiScreen(GUIScreen *screen) {
    current->onHide(current);
    screen->onShow(screen);
    current = screen;
}



void draw_guiScreen(GUIScreen *screen) {
    
    // initialize the drawing environment
    draw_guiElement(NULL, 0, 0, guiScale * screen->width, guiScale * screen->height);
    
    // draw each child element
    for (GUIElement *element = screen->elements; element; element++)
        draw_guiElement(element, 0, 0, screen->width, screen->height);
}



GUIElement *create_guiElement(uint8_t modelID, void *model, uint8_t tabIndex,
        uint8_t anchor, float x, float y, float width, float height,
        bool enabled) {
    GUIElement *element;
    
    if (!(element = malloc(sizeof(GUIElement)))) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
    
    element->modelID = modelID;
    element->model = model;
    element->tabIndex = tabIndex;
    element->anchor = anchor;
    element->x = x;
    element->y = y;
    element->width = width;
    element->height = height;
    element->enabled = enabled;
    element->managed = false;
}



void free_guiElement(GUIElement *element) {
    if (element->managed)
        return;
    
    switch (element->modelID) {
        default:
            break;
    }
    
    free(element);
    element = NULL;
}



void draw_guiElement(GUIElement *element, int16_t px, int16_t py, int16_t pw, int16_t ph) {
    static int scaledWidth;
    static int scaledHeight;
    
    // if no element is given, set static values and return
    if (!element) {
        scaledWidth = pw;
        scaledHeight = ph;
        return;
    }
    
    // determine absolute element position and size values
    int16_t ex = px + (scaledWidth * element->x);
    int16_t ey = py + (scaledHeight * element->y);
    int16_t ew = scaledWidth * element->width;
    int16_t eh = scaledHeight * element->height;
    
    if (element->anchor & !(GUI_TOP | GUI_LEFT)) {
        if (element->anchor & GUI_CENTERW) {
            ex += (pw - ew) / 2;
        } else if (element->anchor & GUI_RIGHT) {
            if (element->anchor & GUI_LEFT) {
                ew = pw - ex + ew;
            } else {
                ex = px + pw - ew;
            }
        }
        
        if (element->anchor & GUI_CENTERH) {
            ey += (ph - eh) / 2;
        } else if (element->anchor & GUI_BOTTOM) {
            if (element->anchor & GUI_TOP) {
                eh = ph - ey + eh;
            } else {
                ey = py + ph - eh;
            }
        }
    }
    
    // draw GUIElement model
    GUIElement *child;
    
    switch (element->modelID) {
        case GUI_KEYBOARD:
            
            GUIKeyboard *keyboard = element->model;
            break;
        case GUI_MOUSE:
            
            GUIMouse *mouse = element->model;
            
            // draw any held elements
            for (child = mouse->children; child; child++)
                draw_guiElement(child, ex, ey, ew, eh);
            
            // draw cursor on top
            if (mouse->enabled)
                draw_guiImage(mouse->cursor, ex, ey);
            
            break;
        case GUI_PANEL:
            
            GUIPanel *panel = element->model;
            
            // draw background
            if (panel->background)
                draw_guiImage(panel->background, ex, ey);
            
            // draw held elements
            //GUIBuffer *buffer;
            for (child = panel->children; child; child++)
                draw_guiElement(child, ex, ey, ew, eh);
            //draw_buffer(buffer, x, y, w, h);
            
            // draw scroll bar
            if (panel->vScrollBar)
                draw_guiElement(panel->vScrollBar, ex, ey, ew, eh);
            
            break;
        case GUI_IMAGE:
            
            GUIImage *image = element->model;
            if (image->image)
                draw_guiImage(image->image, ex, ey, ew, eh);
            break;
        case GUI_BUTTON:
            GUIButton *button = element->model;
            if (element->pressed)
                draw_guiImage(button->pressed, ex, ey, ew, eh);
            else if (element->focused)
                draw_guiImage(button->focused, ex, ey, ew, eh);
            else if (element->enabled)
                draw_guiImage(button->normal, ex, ey, ew, eh);
            else
                draw_guiImage(button->disabled, ex, ey, ew, eh);
            break;
        case GUI_LABEL:
            break;
        case GUI_TEXTBOX:
            break;
        case GUI_SLIDER:
            break;
        case GUI_CHECKBOX:
            break;
        case GUI_TABPANEL:
            
            GUITab tab = element->model;
            
            // draw background
            if (tab->background)
                draw_guiImage(tab->background, ex, ey, ew, eh);
            
            // draw tab buttons
            for (child = tab->buttons; child; child++)
                draw_guiElement(child, ex, ey, ew, eh);
            
            // draw panel
            if (tab->panels)
                draw_guiElement(tab->panels[tab->selected], ex, ey, ew, eh);
            
            break;
        case GUI_ITEM_INVENTORY:
            break;
        case GUI_ITEM_SLOT:
            break;
        case GUI_ITEM_STACK:
            break;
        default:
            break;
    }
}



