#include <stdio.h>
#include <stdarg.h>

void formatPrint(const char *format, ...) {
    
    va_list args;
    va_start(args, format);

    while (*format) {
        
        if (*format == '*') {
            const char *str = va_arg(args, const char *);
            printf("%s", str);
        }
        
        else
            putchar(*format);
        
        format++;
    }

    va_end(args);
}

int main() {

    formatPrint("Hello, my name is *. I`m from *.", "Mikhail", "Russia");
    return 0;
}


