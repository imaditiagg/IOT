#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <string.h>
#include <cstring>

const char* ssid     = "Aditi";
const char* password = "aditi12345";
unsigned long myChannelNumber = 662455;
const char * myReadAPIKey = "VRAJIDRA5FA3CZB2";
WiFiClient WiFiclient;

void setup(){
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(WiFiclient);
}
 
void loop(){
  String temp;
  String humidity;
  String light;
  temp = ThingSpeak.readFloatField(myChannelNumber, 1, myReadAPIKey);
  Serial.println("Temperature= " + temp + "*C");
  humidity = ThingSpeak.readFloatField(myChannelNumber, 2, myReadAPIKey);
  Serial.println("Humidity= " + humidity + "%");
  light = ThingSpeak.readFloatField(myChannelNumber, 3, myReadAPIKey);
  Serial.println("Light= " + light + "%");
  delay(5000);
}
