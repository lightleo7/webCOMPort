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
    for (int i = -180; i <= 180; i++) {
        serial_printf("sin: %d, cos: %d, tg: %d\n", (int) (sin((float)i * (PI / 180.0)) * 100),
                    max(min((int) ((tan((float)i * (PI / 180.0)) * 100)) -512, 0), -1024),
                    (int) (cos((float)i * (PI / 180.0)) * 100) + 512);
    }
    

}