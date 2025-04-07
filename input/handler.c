#include "input/handler.h"
#include "input/cursor.h"
#include <ncurses.h>
void buffer_put_c(int input, int x, int y, char (*buffer)[MAX_LINE_LENGTH]){
    buffer[y][x] = input;
}
bool is_ascii(const int *key){
    return *key >= 32 && *key <= 126;
}
int handle_input(const int *input, Cursor *c, char (*buffer)[MAX_LINE_LENGTH]){
    switch(*input){
        case KEY_EXIT:
            return 0;
        case KEY_UP:
            cursor_move_up(c, buffer);
            break;
        case KEY_DOWN:
            cursor_move_down(c, buffer);
            break;
        case KEY_LEFT:
            cursor_move_left(c, buffer);
            break;
        case KEY_RIGHT:
            cursor_move_right(c, buffer);
            break;
        case KEY_BACKSPACE:
            cursor_move_left(c, buffer);
            char *ch;
            do{
                ch = buffer[c->y]
            } while(c != '\0');
            break;
        default:
            if(is_ascii(input)){
                buffer_put_c(*input, c->x, c->y, buffer);
                cursor_move_right(c, buffer);
            }
            break;
    }
}
