#include <stdio.h>

void get_last_line(const char *filepath) {
    FILE *file = fopen(filepath, "rb");

    if (! file) return;

    fseek(file, -2, SEEK_END);
    int ch;

    while ( (ch = fgetc(file)) != '\n' ) {
        fseek(file, -2, SEEK_CUR);
    }

    char line[1024];

    fgets(line, sizeof(line), file);
    
    fclose(file);

    printf("%s", line);
}

int main() {
    get_last_line("./storage/file.txt");

    return 0;
}
