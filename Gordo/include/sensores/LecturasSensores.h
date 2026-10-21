#ifndef LECTURAS_SENSORES_H
#define LECTURAS_SENSORES_H
struct LecturasSensores {
  bool lineaIzq;
  bool lineaDer;
  bool cercaBorde;
  bool latIzq;
  bool c45Izq;
  bool frontal;
  bool c45Der;
  bool latDer;
};
inline unsigned char bitsRival(const LecturasSensores& l) {
  return l.latIzq | l.c45Izq << 1 | l.frontal << 2 | l.c45Der << 3 | l.latDer << 4;
}
#endif
