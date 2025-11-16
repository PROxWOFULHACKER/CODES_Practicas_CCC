#include <Arduino.h>

// LEDs
int DL = 200;
int verde = 1;
int amarillo = 2;
int naranja = 3;
int rojo = 4;

void setup() {
pinMode(verde, OUTPUT);
pinMode(amarillo, OUTPUT);
pinMode(naranja, OUTPUT);
pinMode(rojo, OUTPUT);
}

void loop() {
//Primera etapa
 digitalWrite (verde, HIGH);
 digitalWrite (amarillo, LOW);
 digitalWrite (naranja, LOW);
 digitalWrite (rojo, LOW);
 delay(DL);
 //Segunda etapa
 digitalWrite (verde, LOW);
 digitalWrite (amarillo, HIGH);
 digitalWrite (naranja, LOW);
 digitalWrite (rojo, LOW);
 delay(DL);
  //Tercera etapa
 digitalWrite (verde, LOW);
 digitalWrite (amarillo, LOW);
 digitalWrite (naranja, HIGH);
 digitalWrite (rojo, LOW);
 delay(DL);
    //Cuarta etapa
 digitalWrite (verde, LOW);
 digitalWrite (amarillo, LOW);
 digitalWrite (naranja, LOW);
 digitalWrite (rojo, HIGH);
 delay(DL);
}