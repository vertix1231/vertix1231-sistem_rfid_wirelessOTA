//*******************************libraries********************************
//RFID-----------------------------
#include "WiFiManager.h"
WiFiManager mydevice;
#define MANUAL 0

//OTA----------------

#include <ArduinoOTA.h>

//--------------------

#include <SPI.h>
#include <MFRC522.h>
//NodeMCU--------------------------
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
//************************************************************************
#define SS_PIN  D2  //D2
#define RST_PIN D1  //D1
//************************************************************************
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
//************************************************************************
/* Set these to your desired credentials. */
//const char *ssid = "your-wifi-id";
//const char *password = "your-password-wifi";
// const char* device_token  = "token-device";  
//************************************************************************

//String URL = "http://192.168.1.8/getdata.php";
//String getData, Link;

String TOKEN, URL, getData, Link;
String OldCardID = "";
unsigned long previousMillis = 0;
//************************************************************************

int BuzzerPin = D4;
int LEDpin = D0;


void connectToWiFi(int a=1, char *ssid = "", char *password = "");
void SendCardID( String Card_uid );
void mainApp();
