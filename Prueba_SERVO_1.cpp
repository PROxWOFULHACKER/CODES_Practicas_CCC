#include <Arduino.h>

#include <Servo.h>
Servo servo1;

int x;
int movimiento;
int PAUSA = 1000; // Tiempo de espera para estabilizar el movimiento del servo


void setup() {

    Serial.begin(9600); // Monitoreo serial para verificar el valor del movimiento del servo
  servo1.attach(9); // Asign the servo to pin 9
  
}  

void loop() {

    x = analogRead(A0); // Lectura del potenciómetro conectado al pin A0
    movimiento = map(x, 0, 1023, 0, 180); // Mapeo del valor leído (0-1023) a un rango de movimiento del servo (0-180 grados)
    servo1.write(movimiento); // Movimiento del servo según el valor mapeado
    Serial.println(movimiento); // Imprime el valor del movimiento en el monitor serial para verificar su funcionamiento
    delay(PAUSA); // Pequeña pausa para estabilizar el movimiento del servo
}