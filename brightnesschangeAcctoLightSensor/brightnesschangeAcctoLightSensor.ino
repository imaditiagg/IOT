#include <Wire.h> //to use I2C
#include "TSL2561.h"
TSL2561 tsl(TSL2561_ADDR_FLOAT); 
int bulb = 12;

void setup() {
  pinMode(bulb,OUTPUT);
  Serial.begin(9600);
  tsl.setGain(TSL2561_GAIN_16X);      // set 16x gain (for dim situations)
  //tsl.setGain(TSL2561_GAIN_0X);      // set 16x gain (for bright situations)
  
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);  // shortest integration time (bright light)
  //tsl.setTiming(TSL2561_INTEGRATIONTIME_101MS);  // medium integration time (medium light)
  //tsl.setTiming(TSL2561_INTEGRATIONTIME_402MS);  // longest integration time (dim light)
}

void loop() {
  uint16_t x = tsl.getLuminosity(TSL2561_VISIBLE); //16 bit reading of unsigned integer   
  Serial.println("Light intensity: " + String (x));
  if( x > 1000)
  analogWrite(bulb,500);
  else{
    analogWrite(bulb,250);
  }
 
}
