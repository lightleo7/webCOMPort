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
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  serial_printf("%ld, %ld, %ld\n", random(1024), random(1024), random(1024));
  delay(100);

  if (Serial.available() > 0) {
    Serial.println("Your message: " + Serial.readString());
  }
}