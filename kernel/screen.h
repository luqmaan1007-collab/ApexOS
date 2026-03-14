#ifndef SCREEN_H
#define SCREEN_H

// Basic text output
void putchar(char c);         // Print single character
void print(const char* str);  // Print string
void clear_screen(void);      // Clear the screen

// Simple GUI window structure
typedef struct {
    int x, y;                  // Top-left corner
    int w, h;                  // Width and height
    char title[32];            // Window title
} Window;

// GUI functions
Window* create_window(int x, int y, int w, int h, const char* title);
void draw_window(Window* w);
void init_gui(void);

#endif
