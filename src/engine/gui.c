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



void allocate_gs(GUIScreen *screen) {
   if (!(screen = malloc(sizeof(GUIScreen)))) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
}



void free_gs(GUIScreen *screen) {
    if (screen->managed)
        return;
    
    for (GUIElement *element = screen->elements; element; element++)
        free_ge(element);
    
    free(screen);
    screen = NULL;
}



void show_gs(GUIScreen *screen) {
    // default show function
}



void hide_gs(GUIScreen *screen) {
    // default hide function
}



void draw_gs(GUIScreen *screen) {
    
    // initialize the drawing environment
    //draw_ge(NULL, 0, 0, guiScale * scaledWidth, guiScale * screenHeight);
    
    // draw each child element
    //for (GUIElement *element = screen->elements; element; element++)
        //draw_ge(element, 0, 0, width, height);
}



void allocate_ge(GUIElement *element) {
    if (!(element = malloc(sizeof(GUIElement)))) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(CODE_MALLOC_ERROR);
    }
}



void free_ge(GUIElement *element) {
    if (element->managed)
        return;
    
    switch (element->modelID) {
        case GUI_KEYBOARD:
            break;
        default:
            break;
    }
    
    free(element);
    element = NULL;
}



void draw_ge(GUIElement *element, uint16_t px, uint16_t py, uint16_t pw, uint16_t ph) {
    static int scaledWidth;
    static int scaledHeight;
    /*
    // if no element is given, set static values
    if (!element) {
        scaledWidth = pw;
        scaledHeight = ph;
        return;
    }
    
    // determine absolute element position and size values
    uint16_t ex = px + (scaledWidth * element->x);
    uint16_t ey = py + (scaledHeight * element->y);
    uint16_t ew = scaledWidth * element->width;
    uint16_t eh = scaledHeight * element->height;
    
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
                draw_ge(child, ex, ey, ew, eh);
            
            // draw cursor on top
            //if (mouse->active)
            //    draw_image(mouse->cursor, ex, ey);
            
            break;
        case GUI_PANEL:
            GUIPanel *panel = element->model;
            
            // draw background
            //if (panel->background)
            //    draw_image(panel->background, ex, ey);
            
            // draw held elements
            //GUIBuffer *buffer;
            //for (child = panel->children; child; child++)
            //    drawb_ge(child, buffer);
            //draw_buffer(buffer, x, y, w, h);
            
            // draw scroll bar
            //if (panel->vScrollBar)
            //    draw_ge(panel->vScrollBar, ex, ey, ew, eh);
            
            break;
        case GUI_IMAGE:
            GUIImage *image = element->model;
            //if (image->image)
            //    draw_image(image->image, ex, ey, ew, eh);
            break;
        case GUI_BUTTON:
            GUIButton *button = element->model;
            //if (element->pressed)
            //    draw_image(button->pressed, ex, ey, ew, eh);
            //else if (element->focused)
            //    draw_image(button->focused, ex, ey, ew, eh);
            //else if (element->enabled)
            //    draw_image(button->normal, ex, ey, ew, eh);
            //else
            //    draw_image(button->disabled, ex, ey, ew, eh);
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
            //GUITab tab = element->model;
            
            // draw background
            //if (tab->background)
            //    draw_image(tab->background, ex, ey, ew, eh);
            
            // draw tab buttons
            //for (child = tab->buttons; child; child++)
            //    draw_ge(child, ex, ey, ew, eh);
            
            // draw panel
            //if (tab->panels)
            //    draw_ge(tab->panels[tab->selected], ex, ey, ew, eh);
            
            break;
        case GUI_ITEM_INVENTORY:
            break;
        case GUI_ITEM_SLOT:
            break;
        case GUI_ITEM_STACK:
            break;
        default:
            break;
    }*/
}



