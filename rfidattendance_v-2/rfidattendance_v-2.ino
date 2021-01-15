#include "config.h"
int led  = D0;

void setup() {
  pinMode(led,OUTPUT);
//  mydevice.resetSettings();
  
  delay(1000);
  Serial.begin(9600);
  
  SPI.begin();  // Init SPI bus
  
  mfrc522.PCD_Init(); // Init MFRC522 card
  //---------------------------------------------
  connectToWiFi();
  ArduinoOTA.onStart([]() {
    Serial.println("Start OTA Connection");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  Serial.println("OTA ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(LEDpin, OUTPUT);
}
//************************************************************************
void loop() {
  ArduinoOTA.handle();
  mainApp();
  delay(1000);
}
