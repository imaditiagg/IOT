#include "dht.h"
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

#include <Wire.h> //to use I2C
#include "TSL2561.h"
TSL2561 tsl(TSL2561_ADDR_FLOAT); 

const char* ssid     = "Aditi";
const char* password = "aditi12345";
unsigned long myChannelNumber = 662455;
const char * myWriteAPIKey = "BGQNQ851V1BIFPB8";
WiFiClient WiFiclient;
dht DHT;

uint32_t prevTime=0;

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

  tsl.setGain(TSL2561_GAIN_16X);      // set 16x gain (for dim situations)
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);

  
}
 
void loop() {
  DHT.read11(D7); //data read every second
  
  String temp = (String)DHT.temperature;
  String humidity = (String)DHT.humidity; 
   
  Serial.println("Temperature is: ");
  Serial.println(DHT.temperature);
  Serial.println("Humidity is: ");
  Serial.println(DHT.humidity);
  
  uint32_t t = millis();
  //write on thingspeak after 15 seconds
  if((t- prevTime) > 15000){
  ThingSpeak.setField(1, temp); //set field values
  ThingSpeak.setField(2, humidity);
  
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  prevTime=t;
  }
  delay(1000); //delay of 1 seconds
  
  
}
