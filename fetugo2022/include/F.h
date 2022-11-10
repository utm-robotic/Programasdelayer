#include "Componentes.h"

void bandastop(){
  banda.stop(hold);
}

void impulso(){
  gato.setVelocity(100, percent);
  gato.spinToPosition(80, degrees);
  gato.spinToPosition(0, degrees);
} 