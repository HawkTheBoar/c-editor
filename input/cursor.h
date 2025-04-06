#ifndef CURSOR_H
#define CURSOR_H
typedef struct {
    int x;
    int y;
} Cursor;
Cursor *cursor_create();
void cursor_move_up();
void cursor_move_down();
#endif