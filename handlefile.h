#ifndef HANDLEFILE_H
#define HANDLEFILE_H
#include "config.h"
// returns 0 if file was saved to buffer else 1
int read_file(char *filename, char (*buffer)[MAX_LINE_LENGTH]);
// returns 0 if buffer was saved to file else 1
int write_to(char *filename, const char (*buffer)[MAX_LINE_LENGTH]);
#endif