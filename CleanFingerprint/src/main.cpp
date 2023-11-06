#include <Arduino.h>
#include <ESP8266WiFi.h> 
#include <Adafruit_Sensor.h>
#include <Adafruit_Fingerprint.h>

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(D2, D1);
#endif

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  delay(100);

  Serial.println("\n\nEliminando Huellas!");
  Serial.println("Presione '0' para continuar");

  while (1) {
    if (Serial.available() && (Serial.read() == '0')) {
      break;
    }
  }

  finger.begin(57600); //Establecer la velocidad de datos para el puerto serie del sensor

  if (finger.verifyPassword()) {
    Serial.println("Sensor de huellas detectado!");
  } else {
    Serial.println("No se detectó sensor de huellas.");
    while (1);
  }

  finger.emptyDatabase();

  Serial.println("Sin huellas registradas!");
}

void loop() {}
