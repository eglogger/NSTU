#include <stdio.h>

long divide(long dividend, long divisor) {

    long quotient = 0;

    int sign = ((dividend < 0) || (divisor < 0)) ? -1 : 1;

    long abs_dividend = dividend < 0 ? -dividend : dividend;
    long abs_divisor = divisor < 0 ? -divisor : divisor;

    while (abs_dividend >= abs_divisor) {

        abs_dividend -= abs_divisor;
        quotient++;
    }

    return sign * quotient;
}

int main() {

    long dividend, divisor;

    scanf("%ld", &dividend);
    scanf("%ld", &divisor);

    if (divisor == 0) {
        printf("Division by zero!\n");
    }

    else {
        long result = divide(dividend, divisor);
        printf("%ld", result);
    }

    return 0;
}