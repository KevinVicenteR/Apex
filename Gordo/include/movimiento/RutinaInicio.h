#ifndef RUTINA_INICIO_H
#define RUTINA_INICIO_H
#include "movimiento/MandoMotores.h"
#include "movimiento/Confirmacion.h"
#include "movimiento/BusquedaRival.h"
#include "movimiento/ControlAtaque.h"
#include "estrategia/DecisionMovimiento.h"
#include "movimiento/rondas/Ronda1.h"
#include "movimiento/rondas/Ronda2.h"
#include "movimiento/rondas/Ronda3.h"
#include "movimiento/rondas/Libre.h"
class RutinaInicio {
public:
  void iniciar(int rutinaElegida, int lado);
  void cancelar() {
    rutina = 0;
  }
  int actual() const {
    return rutina;
  }
  bool elegida() const {
    return conRutina;
  }
  bool continuar(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
    unsigned long ahora, BusquedaRival& busqueda, ControlAtaque& ataque);
private:
  Ronda1 ronda1;
  Ronda2 ronda2;
  Ronda3 ronda3;
  Libre libre;
  int rutina = 0;
  int lado = 1;
  bool conRutina = false;
  bool enCurso = false;
  unsigned long inicio = 0;
  Confirmacion rivalVisto;
};
#endif
