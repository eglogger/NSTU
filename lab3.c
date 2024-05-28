#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** splitWords(const char* text, int* wordCount) {

    int count = 0;
    const char* p = text;
    while (*p) {

        while (isspace(*p)) {
            p++;
        }
        if (*p) {
            count++;
            while (*p && !isspace(*p)) {
                p++;
            }
        }
    }

    char** words = (char**)malloc(count * sizeof(char*));

    p = text;
    int i = 0;
    while (*p) {

        while (isspace(*p)) {
            p++;
        }
        if (*p) {

            const char* start = p;

            while (*p && !isspace(*p)) {
                p++;
            }

            int length = p - start;
            words[i] = (char*)malloc((length + 1) * sizeof(char));

            strncpy(words[i], start, length);
            words[i][length] = '\0';
            i++;
        }
    }

    *wordCount = count;
    return words;
}

int main() {

    const char* text = "example1 example2 example3";
    int wordCount;
    char** words = splitWords(text, &wordCount);

    printf("Words in text:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);

    return 0;
}