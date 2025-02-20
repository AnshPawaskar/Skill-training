#include <stdio.h>
#include <string.h>

void countWordsAndLines(char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot read file: %s\n", filename);
        return;
    }
    char line[1000];
    int linecount = 0;
    int wordcount = 0;
    while (fgets(line, strlen(line), file)) {
        linecount++;
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            wordcount++;
            token = strtok(NULL, " \t\n");
        }
    }
    fclose(file);
}

int main() {
    char filename[100];
    int linecount,wordcount;
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    countWordsAndLines(filename);
    printf("Total Lines: %d\n", linecount);
    printf("Total Words: %d\n", wordcount);
    return 0;
}
