// Both publisher and subscriber are clients
#include <ESP8266WiFi.h>
#include <MQTTClient.h>

#include "dht.h"
const char* ssid     = "Aditi";
const char* password = "aditi12345";
WiFiClient WiFiclient;
MQTTClient MQTTclient;
int val=0;
void connectMQTTBroker(); //connect client with broker server

dht DHT;
int x=1;

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" WiFi Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("connecting to MQTT broker...");
  MQTTclient.begin("broker.shiftr.io", WiFiclient);
  connectMQTTBroker(); //call
}

void connectMQTTBroker() {
  while (!MQTTclient.connect("aditi", "try", "try")) {   // publisher name,username,password
    Serial.print(".");
  }
  Serial.println(" connected");
}

void loop() {
  MQTTclient.loop(); // handle network packets of it
  if(!MQTTclient.connected()) { //recheck if connnect
    connectMQTTBroker();
  }

  DHT.read11(D7);
  String temp = (String)DHT.temperature;
  String humidity = (String)DHT.humidity; 
  
  //val++;
  MQTTclient.publish("Temp_Adi", (String)temp);
  MQTTclient.publish("Humid_Adi", (String)humidity);
 /*if(val==10){
    val=0;
  }*/
  delay(1000);  
}
