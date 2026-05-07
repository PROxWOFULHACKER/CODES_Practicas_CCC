#include <Arduino.h>

int ledRojo = 13; // Pin del LED rojo (puedes conectarlo al pin 13 o cambiar el número)
int ledVerde = 12; // Pin del LED verde (puedes conectarlo al pin 12)
int tiempoEspera = 1000; // Tiempo en milisegundos para el parpadeo (1 segundo)

void setup() {
  // Configuramos el pin del LED como salida para poder enviarle voltaje
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // Bucle para que el LED rojo parpadee 3 veces
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledRojo, HIGH); // Encendemos el LED rojo
    delay(tiempoEspera);         // Esperamos el tiempo definido (1 segundo)
    digitalWrite(ledRojo, LOW);  // Apagamos el LED rojo
    delay(tiempoEspera);         // Esperamos de nuevo antes del siguiente parpadeo
  }

  delay(1500); // Retardo de 1500 ms (1.5 segundos) después de los 3 parpadeos

  digitalWrite(ledVerde, HIGH); // Encendemos el LED verde
  delay(tiempoEspera);          // Mantenemos el LED verde encendido 1 segundo
  digitalWrite(ledVerde, LOW);  // Apagamos el LED verde antes de que se repita el ciclo
}