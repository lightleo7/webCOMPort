#include "utils.h"

#define PRINTF_BUFFER_SIZE 128

void serial_printf(const char *format, ...) {
    char buffer[PRINTF_BUFFER_SIZE];
    va_list args;
    
    va_start(args, format);
    vsnprintf(buffer, PRINTF_BUFFER_SIZE, format, args);
    va_end(args);
    
    Serial.print(buffer);
}
