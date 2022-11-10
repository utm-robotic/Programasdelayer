#include "Componentes.h"

void bandastop(){
  banda.stop(hold);
}

void impulso(){
  gato.setVelocity(100, percent);
  gato.spinToPosition(80, degrees);
  gato.spinToPosition(0, degrees);
} 

void bum(){
  bool salir = true;
  Brain.Screen.clearScreen();
  while(salir == true){
    if(boton.pressing()){
  Brain.Screen.printAt(1, 25, "DARE VUELTAS");
  RightD.spin(fwd, 100, pct);
}
else{
  Brain.Screen.printAt(1, 45, "presioname para dar vueltas");
  RightD.stop();
} 
}
  }
