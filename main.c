#include <ncurses.h>
#include "screen/screen.h"
#include "input/cursor.h"

int main(){
    screen_init();
    char buffer[MAX_LINES][MAX_LINE_LENGTH];
    Cursor *c = cursor_create();
    int keyboard_input;
    do{
        screen_render(&buffer, c, MAX_LINE_LENGTH, MAX_LINES);
        keyboard_input = getch();
    } while((keyboard_input != KEY_EXIT));

    endwin();           // Restore terminal
    return 0;
}