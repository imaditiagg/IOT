#include "dht.h" //incude libraries folder
#define DHT11_PIN D7
dht DHT11;

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C  // OLED display TWI address
Adafruit_SSD1306 OLED(-1);

void setup(){
  Serial.begin(9600);
  OLED.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);   // initialize and clear display
  OLED.clearDisplay();
  OLED.display();
  
  OLED.setTextSize(2);     //set text size
  OLED.setTextColor(WHITE);    //set text color
  OLED.setCursor(10,10);     //set start coordinates for printing
  
  
}

void loop(){
    OLED.clearDisplay();
    DHT11.read11(DHT11_PIN);    //read DHT11 data
    OLED.setCursor(10,10);
    OLED.print(DHT11.temperature);      //display text
    OLED.display();
    
    Serial.print("Temp: ");
    Serial.print(DHT11.temperature);  // Print the temperature
    Serial.println("*C");
    Serial.print("Relative Humidity: ");
    Serial.print(DHT11.humidity);     // Print the humidity
    Serial.println("%");
    delay(2000);
}
