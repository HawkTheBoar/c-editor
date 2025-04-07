#include <ncurses.h>
#include<stdlib.h>
#include "screen/screen.h"
#include "input/cursor.h"
#include "input/handler.h"
char (*create_buffer())[MAX_LINE_LENGTH]{
    char (*buffer)[MAX_LINE_LENGTH] = malloc(MAX_LINES * sizeof(*buffer));
    if (!buffer) {
        perror("Failed to allocate buffer");
        exit(1);
    }
    for(int y = 0; y < MAX_LINES; y++)
        for(int x = 0; x < MAX_LINE_LENGTH; x++)
            buffer[y][x] = '\0';
    return buffer;
}
int main(){
    screen_init();
    char (*buffer)[MAX_LINE_LENGTH] = create_buffer();
    Cursor *c = cursor_create(0, 0);
    int keyboard_input;
    do{
        screen_render(buffer, c, MAX_LINE_LENGTH, MAX_LINES);
        refresh();
        keyboard_input = getch();
        handle_input(&keyboard_input, c, buffer);
        clear();
    } while((keyboard_input != KEY_EXIT));

    endwin();           // Restore terminal
    free(c);
    free(buffer);
    return 0;
}