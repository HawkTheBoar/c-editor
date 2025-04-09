#include <ncurses.h>
#include "input/cursor.h"
#include "screen.h"
#include "config.h"
int maxY, maxX;
void screen_init(){
    initscr();          // Initialize ncurses
    set_escdelay(25);
    cbreak();           // Disable line buffering
    noecho();           // Don't echo typed characters
    curs_set(0);
    keypad(stdscr, TRUE); // Enable special keys (F1, arrows, etc.)
    maxX = getmaxx(stdscr);
    maxY = getmaxy(stdscr);
}
void screen_render(char (*buffer)[MAX_LINE_LENGTH], Cursor *c, int max_line_length, int max_lines, char *title){
    move(0, 0);
    if(c == NULL){
        printw("Cursor is undefined");
        return;
    }
    
    // header  
    printw("In file %s", title);
    move(OFFSET_Y-1, 0);
    char line[maxX-1];
    for(int i = 0; i < maxX-1; i++)
        line[i] = '_';
    line[maxX-1] = '\0';
    printw("%s", line);
    // main
    // line numbers
    for(int y = 0; y < max_lines; y++){
        if(buffer[y][0] != '\0' || y == 0){
            move(y+OFFSET_Y, 1);
            printw("%d", y+1);
        }
    }
    // buffer content
    for(int y = 0; y < max_lines; y++){
        move(y+OFFSET_Y, OFFSET_X);
        printw("%s", buffer[y]);
    }
    // cursor
        // TODO: handle when on character
    move(cursor_get_y(c), cursor_get_x(c));
    printw("_");
    // footer
    
}



