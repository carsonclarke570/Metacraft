/*
gui.c



*/
#include "gui.h"



/*

*/
void mouse_event_handler(GUIScreen *screen, GUIMouseEvent *event) {
  GUIElement *element;
  int i;
  
  for (i = 0; i < screen->elementCount; i++) {
    element = screen->elements[i];
    
    if (
      event->x >= element->x &&
      event->y >= element->y &&
      event->x < element->x + element->width &&
      event->y < element->y + element->width
    ) {
      
      // Make event cooerdinates relative to element.
      event->x -= element->x;
      event->y -= element->y;
      
      // Make this the first element in the list since subsequent
      // calls are likely to hit this element again.
      if (i) {
        screen->elements[i] = screen->elements[0];
        screen->elements[0] = element;
      }
      
      // hover event
      screen->over = element;
      
      if (event->down) {
        screen->down = element;
      } else {
        if (element == screen->down) {
          
          // click event
          screen->focus = element;
          click(element, event);
        } else {
          
          // click event
          screen->down = NULL;
        }
        
        screen->down = NULL;
      }
      
      return;// TODO: this is not friendly to overlapped GUIElements
    }
  }
  
  screen->over = NULL;
}



/*

*/
void key_event_handler(GUIScreen *screen, GUIKeyEvent *event) {
  if (event->down) {
    screen->focus->;
  } else {
    ;
  }
}



/*

*/
void draw_guiScreen(GUIScreen *screen) {
    // 
}



/*

*/
void create_guiScreen(GUIScreen *screen, int elementCount) {
    if (
        !(screen = malloc(sizeof(GUIScreen))) ||
        !(screen->elements = malloc(elementCount * sizeof(GUIElement)))
    ) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(MALLOC_ERROR);
    }
    
    screen->elementCount = elementCount;
}



/*

*/
void delete_guiScreen(GUIScreen *screen) {
    int i;
    
    for (i = 0; i < screen->elementCount; i++)
        delete_guiElement(screen->elements[i]);
    
    free(screen);
    screen = NULL;
}



/*

*/
void create_guiElement(GUIElement *element) {
    if (!(element = malloc(sizeof(GUIElement)))) {
        LOG_E(LOG_MSG_MALLOC_ERROR);
        exit(MALLOC_ERROR);
    }
}



/*

*/
void delete_guiElement(GUIElement *element) {
    free(element);
    element = NULL;
}



