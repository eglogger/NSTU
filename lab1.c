#include <stdio.h>

void compressString(char *str) {

    char *p = str;
    char *q = str;
    char curr_char = *p;
    int count = 1;

    while (*p != '\0') {
        p++;

        if (*p == curr_char) {
            count++;
        }
        else {
            if (count > 1) {
                *q++ = count + '0';
            }
            *q++ = curr_char;
            curr_char = *p;
            count = 1;
        }
    }
    *q = '\0';
}

int main() {

    char str[] = "aaaaabbccccccddddeeeeeee";
    printf("Source string: %s\n", str);

    compressString(str);

    printf("Compressed string: %s\n", str);

    return 0;
}
