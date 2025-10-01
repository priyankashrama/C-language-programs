// filename: wordcount.c
// Compile: gcc wordcount.c -o wordcount
// Run: ./wordcount sample.txt

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int ch, lines = 0, words = 0, chars = 0, inWord = 0;

    while ((ch = fgetc(file)) != EOF) {
        chars++;

        if (ch == '\n') lines++;

        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    fclose(file);

    printf("File: %s\n", argv[1]);
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);

    return 0;
}
