#ifndef HANDLER_H
#define HANDLER_H
#include "input/cursor.h"
#include "screen/screen.h"

int handle_input(const int *input, Cursor *c, char (*buffer)[MAX_LINE_LENGTH]);

#endif