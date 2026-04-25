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

byte mode = 0;

void setup() {
    Serial.begin(9600);
}

void check() {
    if (Serial.available() > 0) {
        String st = Serial.readString();

        if (st == "sin") {
            mode = 1;
        }
        if (st == "cos") {
            mode = 2;
        }
        if (st == "tg") {
            mode = 3;
        }
    }

}

void loop() {
    if (mode == 0)
        for (int i = -180; i <= 180; i++) {
            serial_printf("sin: %d, cos: %d, tg: %d\n", 
                        (int) (sin((float)i * (PI / 180.0)) * 100),
                        (int) (cos((float)i * (PI / 180.0)) * 100) + 512,
                        max(min((int) ((tan((float)i * (PI / 180.0)) * 100)) -512, 0), -1024));
            check();
        }
    else if (mode == 1) {
        for (int i = -180; i <= 180; i++) {
            serial_printf("sin: %d\n", 
                        (int) (sin((float)i * (PI / 180.0)) * 100));
            check();
        }

    }
    else if (mode == 2) {
        for (int i = -180; i <= 180; i++) {
            serial_printf("cos: %d\n", 
                        (int) (cos((float)i * (PI / 180.0)) * 100));
            check();
        }

    }
    else if (mode == 3) {
        for (int i = -180; i <= 180; i++) {
            serial_printf("tg: %d\n", 
                        max(min((int) ((tan((float)i * (PI / 180.0)) * 100)), 1024), -1024));
            check();
        }

    }

    
    

}