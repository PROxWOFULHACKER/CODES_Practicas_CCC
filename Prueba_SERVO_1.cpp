#include <Arduino.h>

#include <Servo.h>
Servo servo1;
Servo servo2;

int x;
int y;
int movimiento;
int movimiento2;
int PAUSA = 1000; // Tiempo de espera para estabilizar el movimiento del servo


void setup() {

    Serial.begin(9600); // Monitoreo serial para verificar el valor del movimiento del servo
  servo1.attach(9); // Asignar el primer servo al pin 9 (puedes cambiarlo según tu conexión)
  servo2.attach(6); // Asignar el segundo servo al pin 6 (si es necesario para otro movimiento)
  
}  

void loop() {

    x = analogRead(A0); // Lectura del potenciómetro conectado al pin A0
    y = analogRead(A4); // Lectura del potenciómetro conectado al pin A4 (si es necesario para otro movimiento)
    movimiento = map(x, 0, 1023, 0, 180); // Mapeo del valor leído (0-1023) a un rango de movimiento del servo (0-180 grados)
    movimiento2 = map(y, 0, 1023, 0, 180); // Mapeo del valor leído del segundo potenciómetro (0-1023) a un rango de movimiento del segundo servo (0-180 grados)
    servo1.write(movimiento); // Movimiento del servo según el valor mapeado
    servo2.write(movimiento2); // El segundo servo se mueva de la misma manera, puedes usar el mismo valor de movimiento
    Serial.println(movimiento); // Imprime el valor del movimiento en el monitor serial para verificar su funcionamiento
    delay(PAUSA); // Pequeña pausa para estabilizar el movimiento del servo
    
    //FIN
}