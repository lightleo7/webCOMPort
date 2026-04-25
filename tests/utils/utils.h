#ifndef UTILS_H
#define UTILS_H
#include <stdarg.h>
#include <Arduino.h>

#define PRINTF_BUFFER_SIZE 128

void serial_printf(const char *format, ...);
#endif