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
#ifndef GUI_H
#define GUI_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>



// GUIElement IDs
#define GUI_KEYBOARD ( 0)
#define GUI_MOUSE    ( 1)

#define GUI_PANEL    ( 2)
#define GUI_IMAGE    ( 3)
#define GUI_BUTTON   ( 4)
#define GUI_LABEL    ( 5)
#define GUI_TEXTBOX  ( 6)
#define GUI_SLIDER   ( 7)
#define GUI_CHECKBOX ( 8)
#define GUI_TABPANEL ( 9)

#define GUI_ITEM_INVENTORY (10)
#define GUI_ITEM_SLOT      (11)
#define GUI_ITEM_STACK     (12)

// GUIElement anchors
#define GUI_TOP     ( 1)
#define GUI_BOTTOM  ( 2)
#define GUI_LEFT    ( 4)
#define GUI_RIGHT   ( 8)
#define GUI_CENTERW (16)
#define GUI_CENTERH (32)



typedef struct {
    char *uri;       // Unique Resource Identifier
    bool managed;    // if true, this resource will not be automatically freed
    uint8_t format;  // image format (1, 2, 4, 8, 16, 13, ARGB, FONT)
    uint16_t width;  // image width
    uint16_t height; // image height
    uint8_t *data;   // image data
} GUIResource;



typedef struct {
    uint16_t capacity;
    uint16_t count;
    GUIResource *internal; // array of internal resources
} GUIResourceManager;



typedef struct {
    uint8_t modelID;  // GUIElement Model ID
    void *model;      // pointer to specific GUIElement model
    uint8_t tabIndex; // if 0, not a tabstop
    uint8_t anchor;   // position anchor flags
    float x;          // offset scaled to screen width
    float y;          // offset scalled to screen height
    float width;      // scaled to screen width (offset if anchored to left and right)
    float height;     // scaled to screen height (offset if anchored to top and bottom)
    bool enabled;     // if true, handlers may be called
    bool managed;     // if true, will not be freed automatically
} GUIElement;



typedef struct {
    void (*hide)();       // called before screen is hidden
    bool managed;         // if true, will not be freed automatically
    GUIElement *mouse;    // mouse GUIElement
    GUIElement *focused;  // GUIElement recieving GUIKeyEvent focus
    GUIElement *elements; // child GUIElements
} GUIScreen;



/*
GUIElement Models

To Register:
create a new struct
create a new define
add the apropriate 'cases' to the functions 'load_ge()', 'draw_ge()', and 'free_ge()'

*/




// Special GUIElement Models
/*
Stores cursor information and state. Used for drag and drop operations
and GUIMouseEvent handling.
*/
typedef struct {
    float x;              // pointer X screen coordinate
    float y;              // pointer Y screen coordinate
    bool isDown;          // 
    uint8_t buttons;      // 
    GUIElement *over;     // pointer to GUIElement where mouse is over
    GUIElement *down;     // GUIElement where mouse is down
    GUIElement *children; // child GUIElements
} GUIMouse;



/*
Stores keyboard information and state. Used for key mapping and GUIKeyEvent
handling.
*/
typedef struct {
    char *keymap; // holds raw, mapped, and down key state array
} GUIKeyboard;



// General GUIElement Models
/*

*/
typedef struct {
    GUIResource *background; // background image
    GUIElement *elements;    // array of child GUIElements
} GUIPanel;



typedef struct {
    char *text;         // displayed text
    uint8_t anchor;     // text anchor flags
    float x;            // fraction of screen width
    float y;            // fraction of screen height
    void *font;         // pointer to font glyph set (ALWAYS MANAGED)
    float fontSize;     // DPI
    uint32_t fontColor; // ARGB color value
} GUILabel;



typedef struct {
    // label stuff here
    bool acceptsENTER; // if true, ENTER will be typed, passed otherwise
    bool acceptsTAB;   // if true, TAB will be typed, passed otherwise
    void *background;  // 
    void *disabled;    // 
} GUITextBox;



typedef struct {
    // label stuff here
    void *normal;   // 
    void *focused;  // 
    void *pressed;  // 
    void *disabled; // 
} GUIButton;



typedef struct {
    GUIResource *image; // image
} GUIImage;



typedef struct {
    bool ticked;
    float start;
    float step;
    float stop;
    float value;
    char *backgroundImage; // loaded image
    void *sliderImage;     // pointer to loaded image
} GUISlider;



typedef struct {
} GUIDivider;



// Custom GUIElement Models
typedef struct {
    //GUIItemSlot *slot; // last or current container slot ID
    uint16_t itemID;   // item ID
    uint8_t count;     // number of items in stack
    bool effect;       // has enchantment effect
    GUIResource *image; // 
} GUIItemStack;



typedef struct {
    char *text;              // 
    GUIResource *background; // 
} GUIItemHover;



typedef struct {
    uint16_t slotID;         // 
    GUIItemStack *itemStack; // 
} GUIItemSlot;



typedef struct {
} GUIInventory;









/*
Function Prototypes
*/
void allocate_gs(GUIScreen *screen);
void free_gs(GUIScreen *screen);
void show_gs(GUIScreen *screen);
void hide_gs(GUIScreen *screen);
void draw_gs(GUIScreen *screen);

void allocate_ge(GUIElement *element);
void free_ge(GUIElement *element);
void draw_ge(GUIElement *element, uint16_t px, uint16_t py, uint16_t pw, uint16_t ph);



/*
Called before the GUIScreen is shown. Loads any unloaded resources so long as
all GUIElement models are registered. All loaded resources will be managed
internally.

Parameters:
    GUIScreen *screen - The GUIScreen for which to load resources.
*/
//void show_gs(GUIScreen *screen);



/*
Called before the GUIScreen is shown. Performs any screen specific on-load
operations.
Used when screen must load data on any type of enter
*/
void show_gsSelectWorld();
void show_gsCreateWorld();
void show_gsCustomizeWorld();
void show_gsRenameWorld();
void show_gsDeleteWorld();
void show_gsMultiplayer();
void show_gsAddServer();
void show_gsDirectConnect();
void show_gsWorldOptions();
void show_gsVideoOptions();
void show_gsSoundOptions();
void show_gsInputOptions();



/*
Called before the GUIScreen is hidden.
Performs any screen specific on-free operations.
Used when screen must save data on any type of leave (game close, escape, back, etc.)
*/
void hide_gsCreateWorld();
void hide_gsCustomizeWorld();
void hide_gsWorldOptions();
void hide_gsVideoOptions();
void hide_gsSoundOptions();
void hide_gsInputOptions();
void hide_gsGame();



/*
GUIElement Models
*/
//const GUIKeyboard gm_keyboard = {NULL};
//const GUIKeyboard gm_mouse = {0.0f, 0.0f, false, 0b0, NULL, NULL, NULL};



/*
GUIScreens
*/
/*
const GUIScreen gsSplash = {
    hide_gs, true, NULL, NULL, {
        {
            GUI_IMAGE, "splash.png\0",
            NULL, NULL, 0.0f, 0.0f, 1.0f, 1.0f, true, true
        }, NULL
    }
};
*/
/*
const GUIScreen gsTitle = {
    NULL, true, NULL, NULL, {
        {
            GUI_IMAGE, "title.png\0",
            NULL, GUI_CENTERW, 0.17647f, 0.125f, 0.647f, 0.2f, true, true
        }, {
            GUI_BUTTON, {
                "Singleplayer\0", GUI_VERTICAL, 0.8f, 0.0f, 0.0f,
                "singleplayer_disabled.png\0",
                "singleplayer_button_default.png\0",
                "singleplayer_over.png\0",
                "singleplayer_down.png\0",
                show_gsSelectWorld
            }, 1, GUI_CENTERW, 0.27f, 0.458f, 0.47f, 0.0833f, true, true
        }, {
            GUI_BUTTON, {
                "Multiplayer\0", GUI_CENTERW, 0.8f, 0.0f, 0.0f,
                "multiplayer_dissabled.png\0",
                show_gsMultiplayer
            }, 2, GUI_CENTERW, 0.27f, 0.458f, 0.47f, 0.0833f, false, true
        }, {
            GUI_BUTTON, {
                "Options\0", GUI_CENTERW, 0.8f, 0.0f, 0.0f,
                "",
                show_gsWorldOptions
            }, 3, GUI_CENTERW, 0.27f, 0.485f, 0.47f, 0.0833f, true, true
        }, {
            GUI_BUTTON, {
                "Quit Game\0", GUI_CENTERW | GUI_CENTERH, 0.8f, 0.0f, 0.0f,
                "",
                quit_game_bceH
            }, 4, GUI_CENTERW, 0.27f, 0.458f, 0.0f, 0.0833f, true, true
        }, {
            GUI_LABEL, {
                VERSION_STRING, NULL, 0.8f, 0.0f, 0.0f,
            }, NULL, GUI_BOTTOM | GUI_LEFT, 0.0f, 0.0f, 0.0f, 0.041667f, true, true
        }, {
            GUI_LABEL, {
                COPYRIGHT_STRING, NULL, 0.041667f, 0.0f, 0.0f,
            }, NULL, GUI_BOTTOM | GUI_RIGHT, 0.958333f, 0.0f, 0.0f, 0.041667f, true, true
        }, NULL
    }
};
*/
const GUIScreen gs_selectWorld = {};
const GUIScreen gs_createWorld = {};
const GUIScreen gs_customizeWorld = {};
const GUIScreen gs_deleteWorld = {};
const GUIScreen gs_renameWorld = {};

const GUIScreen gs_multiplayer = {};
const GUIScreen gs_addServer = {};
const GUIScreen gs_directConnect = {};

const GUIScreen gs_options = {};

const GUIScreen gs_worldOptions = {};
const GUIScreen gs_videoOptions = {};
const GUIScreen gs_soundOptions = {};
const GUIScreen gs_inputOptions = {};

const GUIScreen gs_loading = {};
const GUIScreen gs_menu = {};
const GUIScreen gs_game = {};



#endif



