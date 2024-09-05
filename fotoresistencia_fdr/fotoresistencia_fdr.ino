//Creamos una variable de tipo entero 
int lectura = 0;  

void setup() {   
  Serial.begin(9600);   //Iniciamos la comunicación serial   
}  

void loop() {   
  //Tomamos la lectura analógica del pin al cual conectamos   
  //la señal de nuestro pequeño circuito divisor de tension   
  //y la guardamos en una variable   
  lectura = analogRead(0);    
  //Imprimimos por monitor serie el valor    
  Serial.println(lectura);    
  delay(500); 
}