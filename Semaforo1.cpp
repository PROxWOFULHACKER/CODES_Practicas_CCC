#include <Arduino.h>

// Definición de pines
const int pinLedVerde = 12;   // Pin conectado al LED verde (a través de resistencia de 220 o 330 ohms)
const int pinBuzzer   = 8;    // Pin conectado al buzzer / zumbador
const int pinPulsador = 2;    // Pin conectado al pulsador

void setup() {
  // Configuramos el LED y el Buzzer como salidas
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  // Configuramos el pulsador con resistencia interna PULLUP:
  // Conexión: Un pin del pulsador al Pin 2 y el otro directo a GND.
  // - Cuando NO se presiona: lee HIGH (1)
  // - Cuando SÍ se presiona: lee LOW (0)
  pinMode(pinPulsador, INPUT_PULLUP);
}

void loop() {
  // Leemos si el pulsador está presionado o no
  int estadoPulsador = digitalRead(pinPulsador);

  if (estadoPulsador == LOW) {
    // === PULSADOR PRESIONADO ===
    digitalWrite(pinLedVerde, HIGH); // Encendemos el LED verde
    
    // Para Buzzer ACTIVO (suena directamente con voltaje):
    digitalWrite(pinBuzzer, HIGH);

    // *Nota: Si tu buzzer es PASIVO, descomenta la siguiente línea y comenta la de arriba:
    // tone(pinBuzzer, 1000); // Emite un tono a 1000 Hz
  } else {
    // === PULSADOR SUELTO ===
    digitalWrite(pinLedVerde, LOW);  // Apagamos el LED verde
    digitalWrite(pinBuzzer, LOW);   // Apagamos el buzzer
    
    // *Nota: Si usas buzzer pasivo con tone():
    // noTone(pinBuzzer);
      //Linea para hacer commit de prueba-BORRAR-
  
  }
}