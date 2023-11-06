#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Adafruit_Sensor.h>
#include <DHT_U.h>
#include <Adafruit_Fingerprint.h>
#include <Servo.h>


String apiKey = "750PC6UFHUHFPS9X";  //API key Thingspeak
#define DHTTYPE DHT11 // define sensor DHT11

#define RXsensor D1 //pin donde la terminal RX del sensor de huella está conectado
#define TXsensor D2 //pin donde la terminal TX del sensor de huella está conectado
#define DHTPIN D4 //pin donde dht11 está conectado
#define LED_RGB D5 //pin donde el LED RGB está conectado "activador humedad"
#define BUZZ D6 //pin donde el buzzer está conectado "activador temperatura"
#define SERVOMOTOR D7 //pin donde el servomotor está conectado "activador huella"
#define LED_VERDE D8 //pind donde el led verde está conectado

DHT_Unified dht(DHTPIN, DHT11);
WiFiClient client;
uint32_t delayMS;

#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(TXsensor, RXsensor); //D2,D1 = TX sensor Huella, RX sensor Huella
#endif

Servo servo;
int val = 0; //Variable para activar el servomotor
int id1 = 0; //Contador para la huella de Cristopher
int id2 = 0; //Contador para la huella de Pablo
int id3 = 0; //Contador para la huella de Cesar
int id4 = 0; //Contador para las veces que una huella es denegada
int valt = 0; //Contador para buzzer temperatura.
int valtkey = 0; //LLave para contador para buzzer temperatura.

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()
{
  pinMode(TXsensor, OUTPUT); //TX sensor Huella  D2
  pinMode(LED_VERDE, OUTPUT); //LED VERDE ACCESO
  pinMode(LED_RGB, OUTPUT); //LED RGB UMBRAL HUMEDAD
  pinMode(BUZZ, OUTPUT); //BUZZER UMBRAL TEMPERATURA
  
  Serial.begin(9600);
  Serial.println();
  dht.begin();
  WiFi.begin("TIGO-8817", "4NJ9ED800790");  //CAMBIAR USUARIO Y CONTRASEÑA RED Wi-Fi

  servo.attach(SERVOMOTOR); //Servomotor
  while (!Serial);
  delay(100);
  Serial.println("\n\nPrueba de detección de huellas de Adafruit");

  finger.begin(57600); //Establecer la velocidad de datos para el puerto serie del sensor
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("¡Sensor de huellas dactilares encontrado!");
  } else {
    Serial.println("¡No se encontró el sensor de huellas dactilares!");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("El sensor no contiene ningún dato de huellas dactilares. Ejecute el ejemplo de 'inscribirse'.");
  }
  else {
    Serial.println("Esperando una huella válida...");
    Serial.print("El sensor contiene: "); Serial.print(finger.templateCount); Serial.println(" huellas registradas");
  }

  Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Conectado :) ---- Dirección IPv4: ");
  Serial.println(WiFi.localIP());
  Serial.println(F("Características de sensor DHT11:"));

  //Imprimir los detalles del sensor de temperatura.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperatura: "));
  Serial.print  (F("Valor Max:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Valor Min:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humedad"));
  Serial.print  (F("Valor Max:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Valor Min:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}


uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Huella tomada.");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("Huella no detectada.");
      Serial.println(F("------------------------------------"));
      digitalWrite(LED_VERDE, HIGH);
      delay(50);
      digitalWrite(LED_VERDE, LOW);
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Error de comunicación.");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Error de huella.");
      return p;
    default:
      Serial.println("Error desconocido.");
      return p;
  }

  //Conversion correcta
  p = finger.image2Tz();
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

  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Impresiones coincidentes!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Error de comunicación.");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Las huellas dactilares no coinciden.");
    id4 = id4 + 1; //Contador de huellas denegadas.
    return p;
  } else {
    Serial.println("Error desconocido.");
    return p;
  }

  //Huella encontrada
  Serial.print("Huella encontrada con ID #"); Serial.print(finger.fingerID);
  Serial.println("");
  Serial.println(F("------------------------------------"));
  val = 1;
  //Encender led verde
  digitalWrite(LED_VERDE, HIGH);
  delay(1000);
  digitalWrite(LED_VERDE, LOW);
  if(finger.fingerID == 1) {id1 = id1 + 1;}
  if(finger.fingerID == 2) {id2 = id2 + 1;}
  if(finger.fingerID == 3) {id3 = id3 + 1;}
  return finger.fingerID;
}

// devuelve -1 si falla; de lo contrario, devuelve el número de identificación
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;
  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  Serial.print("Huella encontrada con ID #"); Serial.print(finger.fingerID);
  Serial.println("");
  Serial.println(F("------------------------------------"));
  return finger.fingerID;
}



void loop() {
  delay(delayMS); //Retraso entre mediciones.
  sensors_event_t event; //evento de temperatura
  sensors_event_t event2; //evento de humedad

  dht.temperature().getEvent(&event); //Obtención del evento de temperatura
  if (isnan(event.temperature)) {
    Serial.println(F("Error de lectura para temperatura."));
    Serial.println(event.temperature);
  }
  else {
    Serial.print(F("Temperatura: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
    //Umbral y activador Temperatura
    if(event.temperature>40 || event.temperature<20)
    {
      if(valt < 1)
      {
        //valtkey = 1;
        digitalWrite(BUZZ, HIGH);
      }
      if(valt > 2) 
      {
        digitalWrite(BUZZ, LOW);
      }
      valt = valt + 1;  
    }
    else
    {
      valt = 0;
      //valtkey = 0;
      digitalWrite(BUZZ, LOW);
    }
  }
  
  dht.humidity().getEvent(&event2); //Obtención del evento de humedad
  if (isnan(event2.relative_humidity)) {
    Serial.println(F("Error de lectura para humedad."));
    Serial.println(event.relative_humidity);
  }
  else {
    Serial.print(F("Humedad: "));
    Serial.print(event2.relative_humidity);
    Serial.println(F("%"));
    //Umbral y activador Humedad
    if(event2.relative_humidity>70 || event2.relative_humidity<20){digitalWrite(LED_RGB, HIGH);}
    else{digitalWrite(LED_RGB, LOW);}
  }

  if (client.connect("api.thingspeak.com",80)) //Si se establece una conexión
  {  
    String postStr = apiKey;
    postStr +="&field1=";
    postStr += String(event.temperature);
    postStr +="&field2=";
    postStr += String(event2.relative_humidity);
    postStr +="&field3=";
    postStr += String(id1);
    postStr +="&field4=";
    postStr += String(id2);
    postStr +="&field5=";
    postStr += String(id3);
    postStr +="&field6=";
    postStr += String(id4);
    postStr += "\r\n\r\n";
 
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
 
  }

  client.stop();

  getFingerprintID();
  if (val == 1)
  {
    servo.write(0);
    delay(2000);
    servo.write(180);
    delay(2000);
    servo.write(0);
    val = 0;
  }
  
  delay(1000);
}
