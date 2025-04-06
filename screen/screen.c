#include <ncurses.h>
#include "input/cursor.h"
#include "screen.h"
int maxY, maxX, offsetX, offsetY;
void screen_init(){
    initscr();          // Initialize ncurses
    cbreak();           // Disable line buffering
    noecho();           // Don't echo typed characters
    keypad(stdscr, TRUE); // Enable special keys (F1, arrows, etc.)
    maxX = getmaxx(stdscr);
    maxY = getmaxy(stdscr);
    offsetX = 3;
    offsetY = 4;
}
void screen_render(char (*buffer)[MAX_LINES], Cursor *c, int max_line_length, int max_lines){
    move(0, 0);
    if(c == NULL){
        printw("Cursor is undefined");
        return;
    }
    
    // header  
    printw("In file %s", "#TODO#");
    move(offsetY-1, 0);
    char line[maxX];
    for(int i = 0; i < maxX; i++)
        line[i] = '#';
    printw("%s", line);
    // main
    for(int y = 0; y < max_lines; y++){
        move(y+offsetY, offsetX);
        printw("%s", buffer[y]);
    }
    // cursor
        // TODO: handle when on character
    move(c->y+offsetY, c->x+offsetX);
    printw("#"); 
    // footer
    
}



