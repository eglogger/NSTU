#include <stdio.h>
#include <string.h>

#define MAX_DATA_SIZE 100
#define MAX_BUFFER_SIZE 10

void enterData(char* data) {

    int counter = 0;
    char buffer[MAX_BUFFER_SIZE];

    while (1) {

        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        if (buffer[0] == '\n')
            break;

        int len = strlen(buffer) - 1;

        if (counter + len + 1 < MAX_DATA_SIZE) {

            data[counter++] = len;
            strncpy(&data[counter], buffer, len);
            counter += len;
        }

        else {

            printf("Data array is full!\n");
            break;
        }
    }

    data[counter] = 0;
}

void displayData(char* data) {

    int counter = 0;

    while (data[counter] != 0) {

        int len = data[counter++];

        for (int i = 0; i < len; i++) {
            putchar(data[counter++]);
        }

        putchar('\n');
    }
}

int main() {

    char dataArray[MAX_DATA_SIZE];

    enterData(dataArray);
    displayData(dataArray);

    return 0;
}