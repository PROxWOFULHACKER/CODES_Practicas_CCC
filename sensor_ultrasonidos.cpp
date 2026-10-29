
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// En Tinkercad la dirección típica del LCD I2C es 0x27 (o 0x20 en algunas
// versiones)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definición de pines
const int pinTrig = 9;
const int pinEcho = 8;
const int pinBuzzer = 5;
const int ledVerde = 4;
const int ledAmarillo = 3;
const int ledRojo = 2;

void setup() {
  Serial.begin(9600); // Para verificar lecturas en el Monitor Serie

  // Inicialización de la pantalla LCD en Tinkercad
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Configuración de pines de entrada/salida
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);

  // Mensaje de bienvenida
  lcd.setCursor(0, 0);
  lcd.print("Sensor Distancia");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(1500);
  lcd.clear();
}

void loop() {
  // 1. Disparo del pulso ultrasónico
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  // 2. Medir el tiempo que tarda en regresar el eco (en microsegundos)
  long duracion = pulseIn(pinEcho, HIGH);

  // 3. Calcular la distancia en cm (Velocidad del sonido / 2)
  int distancia = duracion * 0.034 / 2;

  // 4. Mostrar lectura en la pantalla LCD y Monitor Serie
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distancia);
  lcd.print(" cm   "); // Espacios para limpiar dígitos sobrantes

  // 5. Evaluación de los niveles de distancia
  if (distancia > 30) {
    // --- NIVEL SEGURO (> 30 cm) ---
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, LOW);
    noTone(pinBuzzer);

    lcd.setCursor(0, 1);
    lcd.print("Estado: SEGURO   ");
    delay(200);

  } else if (distancia >= 10 && distancia <= 30) {
    // --- NIVEL PRECAUCIÓN (10 a 30 cm) ---
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledRojo, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Estado: CUIDADO  ");

    // Pitido intermitente según la cercanía
    tone(pinBuzzer, 1000);
    delay(100);
    noTone(pinBuzzer);
    delay(map(distancia, 10, 30, 80, 300)); // Beep más rápido si se acerca

  } else {
    // --- NIVEL PELIGRO (< 10 cm) ---
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Estado: PELIGRO! ");

    // Sonido continuo de alerta
    tone(pinBuzzer, 1800);
    delay(150);
  }
}
