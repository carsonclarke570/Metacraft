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

// GUIResourceManager
#define GUI_GRM_INITIAL_CAPACITY (100)
#define GUI_GRM_RESIZE_FACTOR (1.5f)

// GUIResource Formats
#define GUI_FONT    ( 1) // ignores others
#define GUI_CENTER  ( 2) // ignores GUI_STRETCH
#define GUI_TILE    ( 4) // ignores GUI_FILL and GUI_STRETCH
#define GUI_FILL    ( 8) // ignores GUI_STRETCH
#define GUI_STRETCH (16) 
#define GUI_UNROLL  (32) // defines border width (used with GUI_STRETCH)

// GUIElement Model IDs
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
    GUIResourceEntry *entry; // GUIResourceEntry representing this GUIResource
    uint8_t format;          // image format (1, 2, 4, 8, 16, 13, ARGB, FONT)
    int16_t width;           // image width
    int16_t height;          // image height
    uint8_t *data;           // image data
    uint16_t *glyphOffsets;  // font glyph offsets
    bool managed;            // if true, will not be freed automatically
} GUIResource;



typedef struct {
    char *uri;             // Unique Resource Identifier
    uint16_t references;   // the number of GUIElements depending on this GUIResource
                           // (unused by 'managed' resources)
    GUIResource *resource; // GUIResource
} GUIResourceEntry;



typedef struct {
    uint16_t capacity;         // maximum capaciy
    uint16_t count;            // number of GUIResourceEntries
    GUIResourceEntry *entries; // array of GUIResourceEntries
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
    bool enabled;     // if true, state may be changed
    bool managed;     // if true, will not be freed automatically
} GUIElement;



typedef struct GUIScreen_t {
    void (*onShow)(struct GUIScreen_t *); // called before screen is shown
    void (*onHide)(struct GUIScreen_t *); // called before screen is hidden
    GUIElement *focused;                  // GUIElement recieving GUIKeyEvent focus
    GUIElement *elements;                 // child GUIElements
    bool managed;                         // if true, will not be freed automatically
} GUIScreen;



// Special GUIElement Models
/*
Stores cursor information and state. Used for drag and drop operations
and GUIMouseEvent handling.
*/
typedef struct {
    float x;              // pointer x screen coordinate
    float y;              // pointer y screen coordinate
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
    GUIResource *font;   // pointer to font glyph set
    float fontSize;     // fraction of screen height
    uint32_t fontColor; // ARGB color value
} GUILabel;



typedef struct {
    void (*onEnter)();
    bool acceptsENTER; // if true, ENTER will be typed, passed otherwise
    bool acceptsTAB;   // if true, TAB will be typed, passed otherwise
    GUILabel *label;
    GUIResource *background;  // 
} GUITextBox;



typedef struct {
    void (*onClick)();
    GUILabel *label;
    GUIResource *normal;  // 
    GUIResource *focused; // 
    GUIResource *pressed; // 
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
    GUIResource *background; // loaded image
    GUIResource *slider;     // pointer to loaded image
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
Creates a GUIResourceManager object for controlling what GUIResources are
loaded and when they are freed.

Parameters:
Returns:
    GUIResourceManager * - The created GUIResoureManager.
Errors:
    CODE_MALLOC_ERROR
*/
GUIResourceManager *create_guiResourceManager();



/*
Frees all the GUIResourceManager and all loaded GUIResources.

Parameters:
    GUIResourceManager *manager - The GUIResoureManager to free.
Returns:
Errors:
*/
void free_guiResourceManager(GUIResourceManager *manager);



/*
Attempts to load a GUIResource given a URI and the desired resource format.
If a GUIResource with the same URI has already been loaded in the
GUIResourceManager, it will be returned, otherwise it will be loaded and
added. If the GUIResource cannot be loaded, NULL is returned. The loaded
GUIResource will be marked as 'unmanaged'. The URI will be deep copied
and may be freed afterward.

Parameters:
    GUIResourceManager *manager - The GUIResourceManager to load the
                                  GUIResource into.
    char *uri - The filename of the GUIResource to load.
    uint8_t format - The format ID defining how the GUIResource should be
                     loaded and used.
Returns:
    GUIResource * - Pointer to the loaded GUIResource.
    NULL - The Resource failed to load because of either a file access or
           format error.
Errors:
    CODE_MALLOC_ERROR
*/
GUIResource *load_guiResource(GUIResourceManager *manager, char *uri,
        uint8_t format);



/*
Attempts to add a GUIResource given a pointer to a uint8_t buffer, the
width, height, and the desired resource format for interpreting the data.
If a GUIResource with the same address has already been added in the
GUIResourceManager, it will be returned, otherwise it will be added.
If the GUIResource cannot be loaded, NULL is returned. The added
GUIResource will be marked as 'managed'. The URI will be deep copied
and may be freed afterward.


Parameters:
    GUIResourceManager *manager - The GUIResourceManager to add the
                                  GUIResource into.
    uint8_t *data - Pointer to the data to interpret for the GUIResource.
    int16_t width - The width of the image.
    int16_t height - The height of the image.
    uint8_t format - The format ID defining how the GUIResource should be
                     loaded and used.
Returns:
    GUIResource * - Pointer to the stolen GUIResource.
    NULL - The Resource failed to load because of either a memory access or
           format error.
Errors:
    CODE_MALLOC_ERROR
*/
GUIResource *add_guiResource(GUIResourceManager *manager, uint8_t *data,
        int16_t width, int16_t height, uint8_t format);



/*
Removes and frees a GUIResource from the GUIResourceManager. If the
GUIResource is marked as 'managed' then it will not be freed but will still
be removed from the GUIResourceManager.

Parameters:
    GUIResourceManager *manager - The GUIResourceManager from which to free
                                  the GUIResource.
    GUIResource *resource - The GUIResource to free.
Returns:
Errors:
*/
void free_guiResource(GUIResourceManager *manager, GUIResource *resource);



/*
Draws an image defined by the given GUIResource to the screen at the specified
coordinates with the specified dimensions.

Parameters:
    GUIResource *image - The GUIResource to draw.
    int16_t x - The x screen coordinate.
    int16_t y - The y screen coordinate.
    int16_t width - The width of the drawing area.
    int16_t height - The height of the drawing area.
Returns:
Errors:
*/
void draw_image(GUIResource *image, int16_t x, int16_t y, int16_t width,
        int16_t height);



/*
Draws the given text with the font defined by the given GUIResource to the
screen at the specified coordinates with the specified dimensions.

Parameters:
    char *text - The null terminated string to draw.
    GUIResource *font - The GUIResource to use as the font.
    int16_t x - The x screen coordinate.
    int16_t y - The y screen coordinate.
    int16_t width - The width of the drawing area.
    int16_t height - The height of the drawing area.
Returns:
Errors:
*/
void draw_text(char *text, GUIResource *font, int16_t x, int16_t y,
        int16_t width, int16_t height);



/*
Creates a GUIScreen object for containing the GUIElements to be drawn and
preserving any UI state. The GUIScreen will be marked as 'unmanaged'.

Parameters:
    void *onShow - The screen shown event handler.
    void *onHide - The screen hidden event handler.
    GUIElement *elements - The child GUIElement array.
Returns:
    GUIScreen * - The created GUIScreen.
Errors:
*/
GUIScreen *create_guiScreen(void *onShow, void *onHide, GUIElement *elements);



/*
Frees the given GUIScreen and all GUIElements it contains, as well as any
'unmanaged' GUIResources used exclusively by the screen. If the GUIScreen is marked as
'managed' then neither it nor its GUIElements will be freed.

Parameters:
    GUIScreen *screen - The GUIScreen to free.
Returns:
Errors:
*/
void free_guiScreen(GUIScreen *screen);



/*
Loads any unloaded GUIResources, calls the current GUIScreen's 'onHide' event
handler, calls the given GUIScreen's 'onShow' event handler, and makes it
current.

Parameters:
    GUIScreen *screen - The GUIScreen that will be shown.
Returns:
Errors:
*/
void show_guiScreen(GUIScreen *screen);



/*
Draws the given GUIScreen.

Parameters:
    GUIScreen *screen - The GUIScreen that will be drawn.
Returns:
Errors:
*/
void draw_guiScreen(GUIScreen *screen);



/*
Creates a GUIElement to define some model's general attributes. The GUIElement
will be marked as 'unmanaged'. An anchor value of NULL is interpreted as
relative to the upper left of the parent by default.

If the anchor is set as (GUI_BOTTOM) then 'y' will be relative to the parent's
lower bound. If set as (GUI_RIGHT) then 'x' will be relative to the parent's
right bound.

If the anchor is set as (GUI_TOP | GUI_BOTTOM) then 'height' will be an offset
of the parent's lower bound. If set as (GUI_LEFT | GUI_RIGHT) then 'width'
will be an offset of the parent's right bound.

Parameters:
    uint8_t modelID - The ID of the behavioral and visual model.
    void *model - Pointer to a behavioral and visual model.
    uint8_t tabIndex - The tab index for focus shift ordering.
    uint8_t anchor - The sides which are made relative to its parent's.
    float x - The x position as a fraction of screen width.
    float y - The y position as a fraction of screen height.
    float width - The width as a fraction of screen width.
    float height - The height as a fraction of screen height.
    bool enabled - The interactable state. If false, its state cannot be
                   changed.
Returns:
    GUIElement * - The created GUIElement.
Errors:
*/
GUIElement *create_guiElement(uint8_t modelID, void *model, uint8_t tabIndex,
        uint8_t anchor, float x, float y, float width, float height,
        bool enabled);



/*
Frees the given GUIElement and all 'unmanaged' GUIResources exclusively used.
If it is marked as 'managed' then neither it nor its GUIResources will be
freed.

Parameters:
    GUIElement *element - The GUIElement to free.
Returns:
Errors:
*/
void free_guiElement(GUIElement *element);



/*
Draws the given GUIElement as defined by its anchor, position, and dimensions
relative to the parent dimensions given.

Parameters:
    GUIElement *element - The GUIElement to draw.
    int16_t px - The parent's x position in pixels.
    int16_t py - The parent's y position in pixels.
    int16_t pw - The parent's width in pixels.
    int16_t ph - The parent's height in pixels.
Returns:
Errors:
*/
void draw_guiElement(GUIElement *element, int16_t px, int16_t py, int16_t pw, int16_t ph);



/*
Event handlers called before the GUIScreen is shown. Performs any screen
specific on-load operations. Used when screen must load data before use.
*/
void onShow_SelectWorld(GUIScreen *screen);
void onShow_CreateWorld(GUIScreen *screen);
void onShow_CustomizeWorld(GUIScreen *screen);
void onShow_RenameWorld(GUIScreen *screen);
void onShow_DeleteWorld(GUIScreen *screen);
void onShow_Multiplayer(GUIScreen *screen);
void onShow_AddServer(GUIScreen *screen);
void onShow_DirectConnect(GUIScreen *screen);
void onShow_WorldOptions(GUIScreen *screen);
void onShow_VideoOptions(GUIScreen *screen);
void onShow_SoundOptions(GUIScreen *screen);
void onShow_InputOptions(GUIScreen *screen);



/*
Called before the GUIScreen is hidden.
Performs any screen specific on-free operations.
Used when screen must save data on any type of leave (game close, escape, back, etc.)
*/
void onHide_CreateWorld(GUIScreen *screen);
void onHide_CustomizeWorld(GUIScreen *screen);
void onHide_WorldOptions(GUIScreen *screen);
void onHide_VideoOptions(GUIScreen *screen);
void onHide_SoundOptions(GUIScreen *screen);
void onHide_InputOptions(GUIScreen *screen);
void onHide_Game(GUIScreen *screen);



//const GUIKeyboard gm_keyboard = {NULL};
//const GUIKeyboard gm_mouse = {0.0f, 0.0f, false, 0b0, NULL, NULL, NULL};



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



