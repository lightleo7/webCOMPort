#include <stdarg.h>

#define PRINTF_BUFFER_SIZE 128

void serial_printf(const char *format, ...) {
    char buffer[PRINTF_BUFFER_SIZE];
    va_list args;
    
    va_start(args, format);
    vsnprintf(buffer, PRINTF_BUFFER_SIZE, format, args);
    va_end(args);
    
    Serial.print(buffer);
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    serial_printf("just a str\nrand: %ld\n", random(1024)); delay(1);
}
