#ifndef CURSOR_H
#define CURSOR_H
#include "config.h"
typedef struct {
    int x;
    int y;
} Cursor;
Cursor *cursor_create(int x, int y);
void cursor_move_vertical(Cursor *c, int value, const char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_horizontal(Cursor *c, int value, const char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_up(Cursor *c, const char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_down(Cursor *c, const char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_right(Cursor *c, const char (*buffer)[MAX_LINE_LENGTH]);
void cursor_move_left(Cursor *c, const char (*buffer)[MAX_LINE_LENGTH]);
int cursor_get_x(const Cursor *c);
int cursor_get_y(const Cursor *c);
#endif