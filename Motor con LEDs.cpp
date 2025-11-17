#include <Arduino.h>

// VARIABLES
int ACCIONAMIENTO = 3000;
int PAUSA = 1500;
int speedPin = 11;
int speedMotor = 255;
int dirPin1 = 7;
int dirPin2 = 6;
int ledverde = 12;
int ledrojo = 13;


void setup() {
//Activación de pines
pinMode(speedPin, OUTPUT);
pinMode(dirPin1, OUTPUT);
pinMode(dirPin2, OUTPUT);
pinMode(ledrojo, OUTPUT);
pinMode(ledverde, OUTPUT);
}

void loop() {
//Secuencia de movimiento y luces

//Primera etapa
digitalWrite (dirPin1, HIGH);
digitalWrite (dirPin2, LOW);
analogWrite (speedPin, speedMotor);
digitalWrite (ledverde, HIGH);
digitalWrite (ledrojo, LOW);
delay(ACCIONAMIENTO);
//Segunda etapa
digitalWrite (dirPin1, LOW);
digitalWrite (dirPin2, LOW);
analogWrite (speedPin, speedMotor);
digitalWrite (ledverde, LOW);
digitalWrite (ledrojo, HIGH);
delay(PAUSA);
//Tercera etapa
digitalWrite (dirPin1, LOW);
digitalWrite (dirPin2, HIGH);
analogWrite (speedPin, speedMotor);
digitalWrite (ledverde, HIGH);
digitalWrite (ledrojo, LOW);
delay(ACCIONAMIENTO);
//Cuarta etapa
digitalWrite (dirPin1, LOW);
digitalWrite (dirPin2, LOW);
analogWrite (speedPin, speedMotor);
digitalWrite (ledverde, LOW);
digitalWrite (ledrojo, HIGH);
delay(PAUSA);
}