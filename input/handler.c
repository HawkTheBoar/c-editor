#include "input/handler.h"
#include "input/cursor.h"
#include <ncurses.h>
#include "config.h"
void write_ch(int input, int x, int y, char (*buffer)[MAX_LINE_LENGTH]){
    buffer[y][x] = input;
}
void write_ch_and_move_right(Cursor *c, int input, int x, int y, char (*buffer)[MAX_LINE_LENGTH]){
    write_ch(input, x, y, buffer);
    cursor_move_right(c, buffer);
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
            int i = 0;
            do{
                ch = &buffer[c->y][c->x+i];
                *ch = buffer[c->y][c->x+1+i];
                i++;
            } while(*ch != '\0');
            break;
        case ENTER_KEY:
            write_ch('\n', c->x, c->y, buffer);
            cursor_move_down(c, buffer);
            break;
        case '\t':
            for(int i = 0; i < TAB_SPACES; i++)
                write_ch_and_move_right(c, ' ', c->x, c->y, buffer);
            break;
        default:
            if(is_ascii(input)){
                write_ch(*input, c->x, c->y, buffer);
                cursor_move_right(c, buffer);
            }
            // move(3, 2);
            // printw("Unhandled key: %d\n", *input);
            break;
    }
}
