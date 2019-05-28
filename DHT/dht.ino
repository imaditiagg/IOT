#include "dht.h" //incude libraries folder
#define DHT11_PIN D7
dht DHT11;
int LED = 15;
void setup(){
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop(){
    DHT11.read11(DHT11_PIN);    //read DHT11 data
    if( DHT11.temperature > 24)
        digitalWrite(LED,HIGH);
    else 
        digitalWrite(LED,LOW);
    Serial.print("Temp: ");
    Serial.print(DHT11.temperature);  // Print the temperature
    Serial.println("*C");
    Serial.print("Relative Humidity: ");
    Serial.print(DHT11.humidity);     // Print the humidity
    Serial.println("%");
    delay(2000);
}
