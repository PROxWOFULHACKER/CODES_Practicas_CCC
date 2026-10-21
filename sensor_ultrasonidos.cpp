// Código para sensor de ultrasonido de 3 pines (Parallax PING) en Tinkercad
const int pinSignal = 7; // Pin conectado a SIG

void setup() {
  Serial.begin(9600); // Iniciar comunicación serial para ver los datos
}

void loop() {
  long duracion;
  long distanciaCm;

  // 1. Enviar un pulso ultrasónico (el pin actúa como SALIDA)
  pinMode(pinSignal, OUTPUT);
  digitalWrite(pinSignal, LOW);
  delayMicroseconds(2);
  digitalWrite(pinSignal, HIGH);
  delayMicroseconds(5);
  digitalWrite(pinSignal, LOW);

  // 2. Leer el pulso de retorno / eco (el pin actúa como ENTRADA)
  pinMode(pinSignal, INPUT);
  duracion = pulseIn(pinSignal, HIGH);

  // 3. Convertir el tiempo medido a distancia en cm
  // La velocidad del sonido es ~343 m/s (~29 microsegundos por cm).
  // Se divide entre 2 porque el sonido va y vuelve.
  distanciaCm = duracion / 29 / 2;

  // 4. Mostrar el resultado en el Monitor Serie
  Serial.print("Distancia: ");
  Serial.print(distanciaCm);
  Serial.println(" cm");

  delay(200); // Pausa breve entre lecturas
}
