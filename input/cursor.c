#include "cursor.h"
#include <stdlib.h>
#include <ncurses.h>
#include "config.h"
#include "screen/screen.h"
Cursor *cursor_create(int x, int y){
    Cursor *c = malloc(sizeof(Cursor));
    if (!c) {
        perror("Failed to allocate cursor");
        exit(1);
    }
    c->x = x;
    c->y = y;
    return c;
}
// returns TRUE if is out of borders ELSE FALSE
static bool is_out_of_borders(const int x, const int y){
    return x > MAX_LINE_LENGTH || y > MAX_LINES || x < 0 || y < 0;
}
int vertical_move_get_new_x(const Cursor *c, int new_y, const char (*buffer)[MAX_LINE_LENGTH]){
    // todo
    return 0;
}
void cursor_move_vertical(Cursor *c, int value, const char (*buffer)[MAX_LINE_LENGTH]){
    int new_y = c->y+value;
    if(is_out_of_borders(c->x, new_y))
        return;
    c->x = vertical_move_get_new_x(c, new_y, buffer);
    c->y = new_y;
}
void cursor_move_horizontal(Cursor *c, int value, const char (*buffer)[MAX_LINE_LENGTH]){
    int new_x = c->x + value;
    if(is_out_of_borders(new_x, c->y))
        return;
    c->x = new_x;
}
void cursor_move_up(Cursor *c, const char (*buffer)[MAX_LINE_LENGTH]){
    cursor_move_vertical(c, -1, buffer);
}
void cursor_move_down(Cursor *c, const char (*buffer)[MAX_LINE_LENGTH]){
    cursor_move_vertical(c, 1, buffer);
}
void cursor_move_right(Cursor *c, const char (*buffer)[MAX_LINE_LENGTH]){
    cursor_move_horizontal(c, 1, buffer);
}
void cursor_move_left(Cursor *c, const char (*buffer)[MAX_LINE_LENGTH]){
    cursor_move_horizontal(c, -1, buffer);
}
int cursor_get_x(const Cursor *c){
    return c->x + OFFSET_X;
}
int cursor_get_y(const Cursor *c){
    return c->y + OFFSET_Y;
}