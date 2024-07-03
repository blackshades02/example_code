#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_element(FILE *file, const char *element_to_find, const char *filename) {
    char line[1000];
    int line_number = 0;
      while(fgets(line, sizeof(line), file)) {
        line_number++;
        if (strstr(line, element_to_find)) {
            printf("%s:%d:%s", filename, line_number, line);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Invalid Arguments : Usage: %s <keyword_to_grep> filename\n", argv[0]);
        return 1;
    }

    char element[50], filename[50];
    strcpy(element , argv[1]);
    strcpy(filename , argv[2]);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error in opening file\n");
        return -1;
    }

    search_element(file, element, filename);
    fclose(file);
    return 0;
}
