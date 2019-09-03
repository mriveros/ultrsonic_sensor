#include <NewPing.h>
 
/*
 * Fecha: 03-09-2019
 * Autor: Marcos A. Riveros
 * Conexion entre sensor ultrasonico y arduino
 * OBS: Aqui se configuran los pines conectados al sensor con 
el arduino nano.
Previamente se incluye una libreria llamada NewPing que
facilita la interaccion del sensor con el arduino.
La maxima longitud capaz de medir con este sensor es de 
aproximadamente 400 cm.
*/

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 400
 
/*Crear el objeto de la clase NewPing*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  // Esperar 1 segundo entre mediciones
  delay(1000);
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int uS = sonar.ping_median();
  // Imprimir la distancia medida a la consola serial
  Serial.print("Distancia: ");
  // Calcular la distancia con base en una constante centimetrada
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
}
