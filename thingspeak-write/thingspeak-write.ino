#include "dht.h"
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

const char* ssid     = "Aditi";
const char* password = "aditi12345";
unsigned long myChannelNumber = 662455;
const char * myWriteAPIKey = "BGQNQ851V1BIFPB8";
WiFiClient WiFiclient;
dht DHT;

void setup() {
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
  Serial.println(WiFi.localIP());// ip address assigned by router or phone
  ThingSpeak.begin(WiFiclient);
}
 
void loop() {
  DHT.read11(D7);
  String temp = (String)DHT.temperature;
  String humidity = (String)DHT.humidity; 
  Serial.println("Temperature is: ");
  Serial.println(DHT.temperature);
  Serial.println("Humidity is: ");
  Serial.println(DHT.humidity);
  
  ThingSpeak.setField(1, temp); //set field values
  ThingSpeak.setField(2, humidity);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(17000);
}
