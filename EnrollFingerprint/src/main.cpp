#include <Arduino.h>
#include <ESP8266WiFi.h> 
#include <Adafruit_Sensor.h>
#include <Adafruit_Fingerprint.h>

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(D2, D1);
#endif

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

uint8_t id;

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  delay(100);
  Serial.println("\n\n Registro de Huellas");

  finger.begin(57600); //Establecer la velocidad de datos para el puerto serie del sensor

  if (finger.verifyPassword()) {
    Serial.println("Sensor de huellas detectado!");
  } else {
    Serial.println("No se encontró sensor de huellas.");
    while (1) { delay(1); }
  }

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);
}

uint8_t readnumber(void) {
  uint8_t num = 0;
  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

uint8_t getFingerprintEnroll() {
  int p = -1;
  Serial.print("Esperando una huella válida para registrarse como: #"); Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Huella tomada.");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación.");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error en la huella.");
      break;
    default:
      Serial.println("Error desconocido.");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Huella convertida.");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Huella demasiado desordenada.");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación.");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("No se pudieron encontrar funciones de huellas dactilares.");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("No se pudieron encontrar funciones de huellas dactilares.");
      return p;
    default:
      Serial.println("Error desconocido.");
      return p;
  }

  Serial.println("Remover el dedo.");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(id);
  p = -1;
  Serial.println("Coloque el mismo dedo nuevamente.");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Huella convertida.");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación.");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error en la huella.");
      break;
    default:
      Serial.println("Error desconocido.");
      break;
    }
  }

  // OK success!
  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Huella convertida.");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Huella demasiado desordenada.");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación.");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("No se pudieron encontrar funciones de huellas dactilares.");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("No se pudieron encontrar funciones de huellas dactilares.");
      return p;
    default:
      Serial.println("Error desconocido.");
      return p;
  }

  // OK converted!
  Serial.print("Creando modelo para: #");  Serial.println(id);

  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("Impresiones coincidentes!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error de comunicación.");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Las huellas dactilares no coinciden.");
    return p;
  } else {
    Serial.println("Error desconocido.");
    return p;
  }

  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("Almacenada!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error desconocido.");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("No se pudo almacenar en esa ubicación.");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error al escribir en flash.");
    return p;
  } else {
    Serial.println("Error desconocido.");
    return p;
  }

  return true;
}

void loop() // run over and over again
{
  Serial.println("¡Listo para registrar una huella digital!");
  Serial.println("Por favor escriba el número de identificación (del 1 al 127) como desea guardar esta huella...");
  id = readnumber();
  if (id == 0) {// ID #0 no disponible.
     return;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);

  while (!  getFingerprintEnroll() );
}
