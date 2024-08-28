/*  SEMAFORO REQUERIMIENTO 3 -Projecto: Semáforo interactivo para paso de peatones
Semáforo con paso peatón: Igual que en el paso previo pero en cuanto se encuentre el semáforo en Rojo, el paso de peatones estárá en verde. 
Cuando se aproxime el momento finalizar el estado rojo del semáforo, el paso de peatón parpadeará en verde pasándose finalmente a rojo, y con una pequeña latencia, 
el semáforo de vehículos pasará a verde, iniciando un nuevo bucle. */

/** Definiciones **/
// Semaforo automóviles
int rojoCar = 13 ;
int amarilloCar = 12;
int verdeCar = 11;
// Semaforo peatón
int rojoPe = 10;
int verdePe = 9;
// Boton
int button = 2; // asignación del pin 2 variable botón accionamiento peatones.

/* Variables*/
int SafetyLatence = 1500; // (ms) Tiempo en el que ambos pasos (vehículos y peatón) permanecen en rojo.
int TiempoCruce = 5000; // (ms)tiempo permitido para que el peatón cruce.

unsigned long TimeMinVerdeCar = 5000; // (ms) Tiempo mínimo en el que el paso de vehículos se encuentra en verde.
unsigned long startTime; // variable para guardar el tiempo desde que acaba el paso para peatones y empieza el verde coches.
unsigned long finishTime; // (ms)Tiempo de fin semaforo coches verde inicio del cambio de luces.
int switchState = 0;

/* Programa */
void setup(){
 
  pinMode(rojoCar, OUTPUT);
  pinMode(amarilloCar, OUTPUT);
  pinMode(verdeCar, OUTPUT);
  pinMode(rojoPe, OUTPUT);
  pinMode(verdePe, OUTPUT);
  pinMode(button, INPUT);
 // Arranca el ciclo, estados activos (HIGH) de luz verde para vehículos y roja para peatones
  digitalWrite(verdeCar, HIGH);
  digitalWrite(rojoPe, HIGH);
}
 
void loop() {
  finishTime = millis ();
  switchState = digitalRead(button);
 
 if (switchState == HIGH && (finishTime - startTime) > TimeMinVerdeCar){
   cambioLuces();
  }
 if (switchState == HIGH && (finishTime - startTime) < TimeMinVerdeCar){
   delay (TimeMinVerdeCar);
   cambioLuces();
  } 
}
 
void cambioLuces() {
  delay (2000);
  digitalWrite(verdeCar,LOW);
  digitalWrite(amarilloCar, HIGH);
  delay(2000);
 
  digitalWrite(amarilloCar, LOW);
  digitalWrite(rojoCar, HIGH);
  delay(SafetyLatence);
 
  digitalWrite(rojoPe, LOW);
  digitalWrite(verdePe, HIGH);
  delay(TiempoCruce);
 
  for (int x=0; x<10; x++) { // El bucle for enciende el led verde de forma intermitente 9 veces
  digitalWrite(verdePe, HIGH);
  delay(250);
  digitalWrite(verdePe, LOW);
  delay(250);
  }
 
  digitalWrite(rojoPe, HIGH);
  delay(500); // Retraso de encendio del semáforo verde del auto con respecto al rojo del peatón
  digitalWrite(rojoCar, LOW);
  delay(1000);

  digitalWrite(verdeCar, HIGH); 
  startTime = millis();
}