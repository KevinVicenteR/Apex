#include <Arduino.h>
#include "modos/ModoCombate.h"
#include "Pines.h"
#include "Parametros.h"
#include <avr/wdt.h>
#include <EEPROM.h>
namespace {
constexpr int DireccionAvisoReinicio = 1023;
constexpr uint8_t MarcaAvisoReinicio = 0xA7;
}
ModoCombate::ModoCombate(PlacaXMotion& placaRef, DriverMotores& motoresRef,
  Percepcion& percepcionRef, ControlMovimiento& controlRef, ControladorRobot& robotRef)
    : placa(placaRef), motores(motoresRef), percepcion(percepcionRef),
      controlMovimiento(controlRef), robot(robotRef),
      moduloArranque(FiltroModuloArranqueMs, FiltroParadaModuloMs, StopMinimoAntesDeStart) {}
void ModoCombate::iniciar() {
  MCUSR = 0;
  wdt_disable();
  reiniciadaPorParada = EEPROM.read(DireccionAvisoReinicio) == MarcaAvisoReinicio;
  EEPROM.update(DireccionAvisoReinicio, 0);
  if (AvisoListoLed) {
    TX_RX_LED_INIT;
  }
  placa.inicializarPines();
  motores.deshabilitar();
  if (PIN_MODULO_ARRANQUE < 0) {
    empezarCombate();
  }
}
void ModoCombate::empezarCombate() {
  placa.inicializarPines();
  motores.deshabilitar();
  avisoListo(false);
  percepcion = Percepcion();
  percepcion.calibrarPiso();
  controlMovimiento.reiniciar();
  const int dip = placa.leerInterruptores();
  const int rutina = RutinaForzada >= 0 ? RutinaForzada : rutinaSegunInterruptores(dip);
  const int lado = LadoForzado != 0 ? LadoForzado : (dip & 4) ? -1 : 1;
  controlMovimiento.iniciarRutina(rutina, lado);
  enCombate = true;
  combateEmpezado = true;
  inicioCombate = millis();
}
void ModoCombate::actualizar() {
  if (PIN_MODULO_ARRANQUE >= 0) {
    const bool alto = digitalRead((uint8_t)PIN_MODULO_ARRANQUE) == HIGH;
    const bool run = alto == ModuloArranqueActivoAlto;
    const bool marcha = moduloArranque.enMarcha(run, millis());
    if (!marcha) {
      motores.deshabilitar();
      if (combateEmpezado) {
        reiniciarPlaca();
        return;
      }
      actualizarAvisoListo();
      return;
    }
    if (!run) {
      motores.deshabilitar();
      return;
    }
    if (!enCombate) {
      empezarCombate();
    }
  }
  if (millis() - inicioCombate < EsperaInicioCombate) {
    motores.deshabilitar();
    return;
  }
  robot.actualizar();
}
void ModoCombate::reiniciarPlaca() {
  motores.deshabilitar();
  avisoListo(false);
  EEPROM.update(DireccionAvisoReinicio, MarcaAvisoReinicio);
  wdt_enable(WDTO_15MS);
  while (true) {
  }
}
void ModoCombate::avisoListo(bool encendido) {
  if (!AvisoListoLed) {
    return;
  }
  if (encendido) {
    TXLED1;
    RXLED1;
  } else {
    TXLED0;
    RXLED0;
  }
}
void ModoCombate::actualizarAvisoListo() {
  const unsigned long t = millis();
  const bool parpadeando = reiniciadaPorParada && t < 2UL * ParpadeosListo * PeriodoParpadeoListo;
  avisoListo(!parpadeando || (t / PeriodoParpadeoListo) % 2 == 0);
}
