#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C  // OLED display TWI address
int x=5;
int y=5;
Adafruit_SSD1306 OLED(-1);
void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);   // initialize and clear display
  OLED.clearDisplay();
  OLED.display();
  OLED.setTextSize(2);     //set text size
  OLED.setTextColor(WHITE);    //set text color
  OLED.setCursor(x,y);     //set start coordinates for printing
  OLED.print("ETI Labs");      //display text
  OLED.display();
}

void loop() {
  if(x>80){
  x=5;
  y=5;
  }
  OLED.clearDisplay();
  OLED.setCursor(x,10);
  OLED.print("ETI Labs");      //display text
  OLED.display();
  x=x+1;
}
