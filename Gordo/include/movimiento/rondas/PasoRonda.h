#ifndef PASO_RONDA_H
#define PASO_RONDA_H
#include "movimiento/MandoMotores.h"
#include "movimiento/BusquedaRival.h"
#include "movimiento/ControlAtaque.h"
#include "estrategia/DecisionMovimiento.h"
struct PasoRonda {
  const DecisionMovimiento& decision;
  MandoMotores& mando;
  IMotor& motor;
  BusquedaRival& busqueda;
  ControlAtaque& ataque;
  unsigned long ahora;
  unsigned long t;
  int lado;
  int visto;
  bool deFrente;
};
enum class ResultadoRonda : unsigned char { Sigue, Ataca, Termina };
#endif
