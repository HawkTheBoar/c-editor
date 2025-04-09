#ifndef SCREEN_H
#define SCREEN_H
#include "config.h"
#include "input/cursor.h"

void screen_init();

void screen_render(char (*buffer)[MAX_LINE_LENGTH], Cursor *c, int max_line_length, int max_lines, char *title);

#endif