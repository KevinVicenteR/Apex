#ifndef PARAMETROS_H
#define PARAMETROS_H

constexpr int PolaridadSensoresEnemigo = 0;

constexpr int MascaraEnemigosActivosHigh = 31;
 
constexpr unsigned long TiempoRetencionEnemigo = 40;
 
constexpr unsigned long ConfirmacionSensorEnemigo = 0;

constexpr int PorcentajeUmbralLinea = 15;
constexpr int UmbralLineaMinimo = 60;
constexpr int MuestrasCalibracionPiso = 64;
 
constexpr int NegroPisoIzquierdo = 994;
constexpr int NegroPisoDerecho = 972;

constexpr int PorcentajeCercaBorde = 70;
constexpr int VelocidadCercaBorde = 100;

constexpr unsigned long TiempoInicioReglamentario = 5000;

constexpr bool UsarEstimadorBorde = true;
 
constexpr bool EstimadorLimitaEmbestida = true;
 
constexpr float RadioDohyo = 0.385f;
constexpr float AnchoLineaBorde = 0.025f;
constexpr float DistanciaSensorPiso = 0.078f;      
constexpr float SeparacionSensoresPiso = 0.04f;    
constexpr float TrochaRuedas = 0.085f;             

constexpr float VelocidadRuedaMaxima = 0.53f;
constexpr int ZonaMuertaPwm = 40;
constexpr float TauRuedaEstimador = 0.06f;
 
constexpr float RadioSalidaEstimado = 0.15f;

constexpr float IncertSalidaCentro = 0.06f;
constexpr float RadioSalidaRound3 = 0.295f;
constexpr float IncertSalidaRound3 = 0.03f;
constexpr float IncertRumboRound3 = 0.3f;

constexpr float ErrorDistancia = 0.3f;
constexpr float ErrorGiro = 0.25f;
constexpr float DerivaRumbo = 0.3f;
 
constexpr float EmpujonAtaque = 0.15f;
constexpr float EmpujonContacto = 0.4f;
constexpr float EmpujonLateral = 0.2f;

constexpr float AnguloLineaLado = 0.6f;
constexpr float IncertAnguloLinea = 0.5f;
constexpr float IncertPosicionLinea = 0.02f;
 
constexpr float SigmasSeguridad = 1.0f;
constexpr float MargenBorde = 0.09f;
 
constexpr float DesaceleracionFreno = 4.0f;
constexpr float RetardoReaccion = 0.04f;
 
constexpr int VelocidadMinimaEstimador = 100;
 
constexpr float IncertPosicionConfiable = 0.08f;
constexpr float IncertRumboConfiable = 0.8f;

constexpr bool DipActivoBajo = true;

constexpr bool ColocacionLibre = true;

constexpr unsigned long ConfirmacionDeteccion = 5;

constexpr unsigned long EsperaInicioCombate = 0;

constexpr bool ModuloArranqueActivoAlto = true;

constexpr unsigned long FiltroModuloArranqueMs = 30;

constexpr unsigned long FiltroParadaModuloMs = 150;

constexpr unsigned long StopMinimoAntesDeStart = 300;
 
constexpr unsigned long TiempoReanudarCombate = 0;
 
constexpr bool ReiniciarTrasParada = true;
 
constexpr unsigned long TiempoMinimoParaReanudar = 1000;
constexpr unsigned long VentanaProgramacionMs = 2000;

constexpr bool AvisoListoLed = true;
constexpr int ParpadeosListo = 3;
constexpr unsigned long PeriodoParpadeoListo = 150;

constexpr int rutinaSegunInterruptores(int dip) {
    return (dip & 3) == 0 ? 1 : (dip & 3) == 1 ? 2 : (dip & 3) == 2 ? 3 : 4;
}

constexpr int RutinaForzada = -1;
constexpr int LadoForzado = 0;

#include "movimiento/parametros/ParametrosMotores.h"
#include "movimiento/parametros/ParametrosAtaque.h"
#include "movimiento/parametros/ParametrosGiroLateral.h"
#include "movimiento/parametros/ParametrosEvasion.h"
#include "movimiento/parametros/ParametrosBusqueda.h"
#include "movimiento/parametros/ParametrosFrenado.h"
#include "movimiento/parametros/ParametrosRutinasInicio.h"

#endif
