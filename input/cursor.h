#ifndef CURSOR_H
#define CURSOR_H
#include "config.h"
typedef struct {
    int x;
    int y;
} Cursor;
Cursor *cursor_create(int x, int y);
void cursor_move_vertical(Cursor *c, int value, char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_horizontal(Cursor *c, int value, char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_up(Cursor *c, char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_down(Cursor *c, char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_right(Cursor *c, char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_left(Cursor *c, char (*buffer)[MAX_LINE_LENGTH]);
int cursor_get_x(Cursor *c);
int cursor_get_y(Cursor *c);
#endif