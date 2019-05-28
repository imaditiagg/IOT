#include <ESP8266WiFi.h>
#include <MQTTClient.h>
#include "dht.h"
dht DHT;
const char* ssid     = "Aditi";
const char* password = "aditi12345";
WiFiClient WiFiclient;
MQTTClient MQTTclient;

void connectMQTTBroker();//connect client with broker

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
  connectMQTTBroker();//call
}

void connectMQTTBroker() { //connect to broker
  while (!MQTTclient.connect("aditi", "try", "try")){//client name,username,password {
    Serial.print(".");
  }
  Serial.println("connected");
}

void loop() {
  MQTTclient.loop();//handle network packets 
  if(!MQTTclient.connected()) {//if not connected
    connectMQTTBroker();//try to connect
  }
  DHT.read11(D7); //data read every second
  
  String temp = (String)DHT.temperature;
  String humidity = (String)DHT.humidity; 
   
  Serial.println("Temperature is: ");
  Serial.println(DHT.temperature);
  Serial.println("Humidity is: ");
  Serial.println(DHT.humidity);
  MQTTclient.publish("Topic_Temp_Adi", (String)temp); //topic and value 
  MQTTclient.publish("Topic_Humidity_Adi", (String)humidity);
  delay(1000);  
}
