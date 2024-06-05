#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool findExpressions(int target, int num, char* expression, int total, int prev) {

    if (num == 10) {

        if (total == target) {

            printf("%s\n", expression);
            return true;
        }

        return false;
    }

    char* operators = "+-";

    for (int i = 0; i < strlen(operators); i++) {

        char newExpression[20];

        sprintf(newExpression, "%s%c%d", expression, operators[i], num);

        if (operators[i] == '+') {
            if (findExpressions(target, num + 1, newExpression, total + num, num))
                return true;
        }

        else {
            if (findExpressions(target, num + 1, newExpression, total - num, num))
                return true;
        }
    }

    char newExpression[20];
    sprintf(newExpression, "%s%d", expression, num);

    int newNum = prev * 10 + num;
    if (findExpressions(target, num + 1, newExpression, total - prev + newNum, newNum))
        return true;

    return false;
}

int main() {

    int target;

    printf("Enter the target number: ");
    scanf("%d", &target);

    if (!findExpressions(target, 2, "1", 1, 1)) {
        printf("No expression found.\n");
    }

    return 0;
}