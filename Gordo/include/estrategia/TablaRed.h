#ifndef TABLA_RED_H
#define TABLA_RED_H
#include <stdint.h>
#include <avr/pgmspace.h>
#define TABLA_RED(nombre, n) const int8_t nombre[n] PROGMEM
#define LEER_RED(tabla, i) ((int8_t)pgm_read_byte(&(tabla)[i]))
#endif
