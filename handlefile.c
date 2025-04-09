#include "handlefile.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int write_to(char *filename, const char (*buffer)[MAX_LINE_LENGTH]){
    FILE* out = fopen(filename, "w");
    if(!out)
    {
        return 1;
    }
    for(int i = 0; i < MAX_LINES; i++){
        if(buffer[i][0] == '\0')
            continue;
        fprintf(out, "%s", buffer[i]);
    }
    fflush(out);
    fclose(out);
    return 0;
}
int read_file(char *filename, char (*buffer)[MAX_LINE_LENGTH]){
    FILE *in = fopen(filename, "r");
    if (!in) {
        // File doesn't exist? Create it.
        in = fopen(filename, "w");
        if (!in) {
            fprintf(stderr, "Error: Could not create/open file '%s'\n", filename);
            exit(1);
            return 1;
        }
        fclose(in);
    }
    char line[MAX_LINE_LENGTH];
    int lineCount = 0;
    while(fgets(line, sizeof(line), in) && lineCount < MAX_LINES){
        line[strcspn(line, "\n")] = '\0';
        strncpy(buffer[lineCount], line, MAX_LINE_LENGTH);
        lineCount++;
    }

    fclose(in);
}
