#include <ncurses.h>
#include<stdlib.h>
#include "screen/screen.h"
#include "input/cursor.h"
#include "input/handler.h"
#include "handlefile.h"
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

int main(int argc, char *argv[]){
    screen_init();
    char (*buffer)[MAX_LINE_LENGTH] = create_buffer();
    char *title = "new_file";
    if(argc == 2){
        if(read_file(argv[1], buffer)){
            printf("Error: couldnt save file content to buffer. file: {%s}", argv[1]);
            exit(1);
        }
        title = argv[1];
    }
    Cursor *c = cursor_create(0, 0);
    int keyboard_input;
    do{
        screen_render(buffer, c, MAX_LINE_LENGTH, MAX_LINES, title);
        // printw("%d", keyboard_input);
        refresh();
        keyboard_input = getch();
        handle_input(&keyboard_input, c, buffer);
        clear();
    } while((keyboard_input != 27));

    endwin();           // Restore terminal
    write_to(title, buffer);
    free(c);
    free(buffer);
    return 0;
}