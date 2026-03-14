#include "screen.h"

static volatile char* VIDEO_MEMORY = (volatile char*)0xB8000;
static int cursor_pos = 0;

void putchar(char c) {
    if (c == '\n') cursor_pos += 80 - (cursor_pos % 80);
    else VIDEO_MEMORY[cursor_pos*2] = c;
    VIDEO_MEMORY[cursor_pos*2+1] = 0x07; // light grey on black
    cursor_pos++;
}

void print(const char* str) {
    while (*str) putchar(*str++);
}

void clear_screen(void) {
    for (int i = 0; i < 80*25; i++) {
        VIDEO_MEMORY[i*2] = ' ';
        VIDEO_MEMORY[i*2+1] = 0x07;
    }
    cursor_pos = 0;
}
