#include "dht.h"
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

#include <Wire.h> //to use I2C
#include "TSL2561.h"
TSL2561 tsl(TSL2561_ADDR_FLOAT); 

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C  // OLED display TWI address
Adafruit_SSD1306 OLED(-1);

const char* ssid     = "Aditi";
const char* password = "aditi12345";
unsigned long myChannelNumber = 662455;
const char * myWriteAPIKey = "BGQNQ851V1BIFPB8";
WiFiClient WiFiclient;
dht DHT;
int count=1;
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

  OLED.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);   // initialize and clear display
  OLED.clearDisplay();
  OLED.display();
  OLED.setTextSize(1);     //set text size
  OLED.setTextColor(WHITE);    //set text color
  OLED.setCursor(10,10);     //set start coordinates for printing
  OLED.print("ETI Labs");      //display text
  OLED.display();
}
 
void loop() {
  DHT.read11(D7); //data read every second
  OLED.clearDisplay();
  
  String temp = (String)DHT.temperature;
  String humidity = (String)DHT.humidity; 
  uint16_t x = tsl.getLuminosity(TSL2561_VISIBLE); //16 bit reading of unsigned integer   
  
   
  Serial.println("Temperature is: ");
  Serial.println(DHT.temperature);
  Serial.println("Humidity is: ");
  Serial.println(DHT.humidity);
  Serial.println("Light intensity: " + String (x)); 
  uint32_t t = millis();
  //if((count%17)==0){ //write on thingspeak after 17 seconds
  if((t- prevTime) > 15000){
  ThingSpeak.setField(1, temp); //set field values
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, String(x));
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  prevTime=t;
  }
  
  OLED.setCursor(10,10); //OLED update every second
  OLED.print(temp+":"+humidity+":"+String(x));
  OLED.display();
  delay(1000); //delay of 1 seconds
  count++;
  
}
