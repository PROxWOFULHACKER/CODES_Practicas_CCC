#include <Arduino.h>

//Definimomos las variables
int ledVerde = 2; //Pin del led verde
int ledNaranja = 4; //Pin del led naranja
int ledRojo = 6; //Pin del led rojo
int switchT2 = 10; //Pin del switch T2
int switchT1 = 12; //Pin del switch T1
int DL = 500; //Delay
int PAUSA = 2000; //Pausa

void setup() {

//Activamos los pines
    pinMode(ledVerde, OUTPUT);
    pinMode(ledNaranja, OUTPUT);
    pinMode(ledRojo, OUTPUT);
    pinMode(switchT2, INPUT_PULLUP);
    pinMode(switchT1, INPUT_PULLUP);

}  

void loop() {
//Leemos el estado de los switches
    int estadoT2 = digitalRead(switchT2);
    int estadoT1 = digitalRead(switchT1);

//Condiciones para encender los leds
    if (estadoT2 == HIGH) { //Si el switch T2 está presionado
        digitalWrite(ledVerde, HIGH); //Encendemos el led verde
        delay(DL);
        digitalWrite(ledNaranja, HIGH); //Encendemos el led naranja
        delay(DL);
        digitalWrite(ledRojo, HIGH); //Encendemos el led rojo
        delay(DL)
    } 
    else if     (estadoT1 == HIGH) { //Si el switch T2 está presionado
        digitalWrite(ledRojo, HIGH); //Encendemos el led verde
        delay(DL);
        digitalWrite(ledNaranja, HIGH); //Encendemos el led naranja
        delay(DL);
        digitalWrite(ledVerde, HIGH); //Encendemos el led rojo
        delay(DL)
    }

    delay(PAUSA); //Pausa antes de apagar los leds
}