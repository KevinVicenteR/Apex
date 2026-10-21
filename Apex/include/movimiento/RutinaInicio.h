#ifndef RUTINA_INICIO_H
#define RUTINA_INICIO_H

#include "movimiento/MandoMotores.h"
#include "movimiento/Confirmacion.h"
#include "movimiento/BusquedaRival.h"
#include "movimiento/ControlAtaque.h"
#include "estrategia/DecisionMovimiento.h"
#include "movimiento/rumania/Modo1Defensivo.h"
#include "movimiento/rumania/Modo2Contragolpe.h"
#include "movimiento/rumania/Modo3Lado.h"
#include "movimiento/rumania/Modo4Agresivo.h"

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
  bool girar(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
             unsigned long ahora, unsigned long t, BusquedaRival& busqueda, ControlAtaque& ataque);
  void decidirLado(const DecisionMovimiento& decision, BusquedaRival& busqueda);
  bool avanzarAlCentro(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
                       unsigned long ahora, unsigned long t, ControlAtaque& ataque);
  bool explorar(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
                unsigned long ahora, unsigned long t, ControlAtaque& ataque);

  bool modoRumania(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
                   unsigned long ahora, unsigned long t, ControlAtaque& ataque);
  Modo1Defensivo modo1;
  Modo2Contragolpe modo2;
  Modo3Lado modo3;
  Modo4Agresivo modo4;

  int rutina = 0;
  int lado = 1;
  bool conRutina = false;
  bool enCurso = false;
  unsigned long inicio = 0;

  bool ladoDecidido = false;
  Confirmacion rivalVisto;

  bool frenandoGiro = false;
  unsigned long inicioFreno = 0;
  Freno freno;
};

#endif
