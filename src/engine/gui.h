/*
gui.h



*/
#ifndef GUI_H
#define GUI_H



typedef enum {
    PANEL,
    DIVIDER,
    LABEL,
    BUTTON,
    SLIDER,
    TEXTBOX
} GUIElementType;



typedef struct {
    bool down;
    int button;
    int x;
    int y;
} GUIMouseEvent;



typedef struct {
  bool down; // the 
  char key;  // ke
  bool shift;
  bool ctrl;
} GUIKeyEvent;



typedef struct {
    int x;
    int y;
    int width;
    int height;
    char *text;
    GUIElementType type;
} GUIElement;



typedef struct {
    GUIElement *over;     // pointer to gui element where mouse is over
    GUIElement *down;     // pointer to gui element where mouse is down
    GUIElement *focused;  // pointer to child recieving key event focus
    int elementCount;     // number of child gui elements
    GUIElement *elements; // pointer to array of child gui elements
} GUIScreen;



/*
Function Prototypes
*/
void create_guiScreen(GUIScreen *screen, int elementCount);
void delete_guiScreen(GUIScreen *screen);

void create_guiElement(GUIElement *element);
void delete_guiElement(GUIElement *element);

void draw_guiScreen(GUIScreen *screen);

void mEvent_handler(GUIMouseEvent *event);
void kEvent_handler(GUIKeyEvent *event);



#endif



